#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define TAPE_SIZE 65536   // tamaño aumentado para archivos más grandes
#define MAX_FILE_SIZE (10 * 1024 * 1024)  // 10MB máximo

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

void print_usage(const char *program_name) {
    printf("Uso: %s [opciones] archivo.bf\n", program_name);
    printf("Opciones:\n");
    printf("  -v, --verbose    Mostrar información detallada\n");
    printf("  -h, --help       Mostrar esta ayuda\n");
    printf("  -t, --text       Modo texto (mostrar caracteres no imprimibles como códigos)\n");
}

int is_valid_brainfuck_char(char c) {
    return (c == '>' || c == '<' || c == '+' || c == '-' || 
            c == '.' || c == ',' || c == '[' || c == ']');
}

int validate_brackets(const char *code) {
    int bracket_count = 0;
    for (const char *p = code; *p; p++) {
        if (*p == '[') {
            bracket_count++;
        } else if (*p == ']') {
            bracket_count--;
            if (bracket_count < 0) {
                print_error("Paréntesis ']' sin '[' correspondiente");
                return 0;
            }
        }
    }
    if (bracket_count != 0) {
        print_error("Paréntesis '[' sin ']' correspondiente");
        return 0;
    }
    return 1;
}

void run_brainfuck(const char *code, int verbose, int text_mode) {
    unsigned char tape[TAPE_SIZE] = {0};
    unsigned char *ptr = tape;
    const char *pc = code;
    long instructions_executed = 0;
    
    if (verbose) {
        printf("Iniciando ejecución de Brainfuck...\n");
        printf("Tamaño de cinta: %d bytes\n", TAPE_SIZE);
    }

    while (*pc) {
        // Verificar límites del puntero
        if (ptr < tape) {
            print_error("Puntero fuera de límites (muy a la izquierda)");
            return;
        }
        if (ptr >= tape + TAPE_SIZE) {
            print_error("Puntero fuera de límites (muy a la derecha)");
            return;
        }

        switch (*pc) {
            case '>': 
                ptr++; 
                break;
            case '<': 
                ptr--; 
                break;
            case '+': 
                (*ptr)++; 
                break;
            case '-': 
                (*ptr)--; 
                break;
            case '.': 
                if (text_mode && !isprint(*ptr) && *ptr != '\n' && *ptr != '\t') {
                    printf("[%d]", *ptr);
                } else {
                    putchar(*ptr);
                }
                fflush(stdout);
                break;
            case ',': 
                {
                    int input = getchar();
                    if (input == EOF) {
                        *ptr = 0;
                    } else {
                        *ptr = (unsigned char)input;
                    }
                }
                break;
            case '[':
                if (*ptr == 0) {
                    int loop = 1;
                    while (loop > 0) {
                        pc++;
                        if (*pc == '\0') {
                            print_error("Bucle '[' sin ']' correspondiente durante ejecución");
                            return;
                        }
                        if (*pc == '[') loop++;
                        else if (*pc == ']') loop--;
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int loop = 1;
                    while (loop > 0) {
                        pc--;
                        if (pc < code) {
                            print_error("Bucle ']' sin '[' correspondiente durante ejecución");
                            return;
                        }
                        if (*pc == ']') loop++;
                        else if (*pc == '[') loop--;
                    }
                }
                break;
        }
        pc++;
        instructions_executed++;
        
        // Protección contra bucles infinitos
        if (instructions_executed > 100000000) {  // 100M instrucciones
            print_error("Posible bucle infinito detectado (100M+ instrucciones)");
            if (verbose) {
                printf("Posición del puntero: %ld\n", ptr - tape);
                printf("Valor actual: %d\n", *ptr);
            }
            return;
        }
    }
    
    if (verbose) {
        printf("\nEjecución completada.\n");
        printf("Instrucciones ejecutadas: %ld\n", instructions_executed);
        printf("Posición final del puntero: %ld\n", ptr - tape);
    }
}

char* read_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Error: No se pudo abrir el archivo '%s': %s\n", 
                filename, strerror(errno));
        return NULL;
    }

    // Obtener tamaño del archivo
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (size <= 0) {
        print_error("El archivo está vacío o no se pudo leer su tamaño");
        fclose(f);
        return NULL;
    }

    if (size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: El archivo es demasiado grande (%ld bytes). Máximo: %d bytes\n", 
                size, MAX_FILE_SIZE);
        fclose(f);
        return NULL;
    }

    // Leer archivo
    char *code = malloc(size + 1);
    if (!code) {
        print_error("No se pudo asignar memoria para el archivo");
        fclose(f);
        return NULL;
    }

    size_t bytes_read = fread(code, 1, size, f);
    if (bytes_read != size) {
        fprintf(stderr, "Error: Solo se pudieron leer %zu de %ld bytes\n", bytes_read, size);
        free(code);
        fclose(f);
        return NULL;
    }

    code[size] = '\0';
    fclose(f);

    // Filtrar solo caracteres válidos de Brainfuck
    char *filtered = malloc(size + 1);
    if (!filtered) {
        print_error("No se pudo asignar memoria para el código filtrado");
        free(code);
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (is_valid_brainfuck_char(code[i])) {
            filtered[j++] = code[i];
        }
    }
    filtered[j] = '\0';

    free(code);
    return filtered;
}

int main(int argc, char *argv[]) {
    int verbose = 0;
    int text_mode = 0;
    char *filename = NULL;

    // Parsear argumentos
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--text") == 0) {
            text_mode = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else if (argv[i][0] == '-') {
            fprintf(stderr, "Opción desconocida: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        } else {
            if (filename) {
                print_error("Solo se puede especificar un archivo");
                print_usage(argv[0]);
                return 1;
            }
            filename = argv[i];
        }
    }

    if (!filename) {
        print_error("Debe especificar un archivo .bf");
        print_usage(argv[0]);
        return 1;
    }

    // Leer y validar el archivo
    char *code = read_file(filename);
    if (!code) {
        return 1;
    }

    if (strlen(code) == 0) {
        print_error("El archivo no contiene código Brainfuck válido");
        free(code);
        return 1;
    }

    if (!validate_brackets(code)) {
        free(code);
        return 1;
    }

    if (verbose) {
        printf("Archivo: %s\n", filename);
        printf("Instrucciones válidas encontradas: %zu\n", strlen(code));
    }

    // Ejecutar el programa
    run_brainfuck(code, verbose, text_mode);

    free(code);
    return 0;
}