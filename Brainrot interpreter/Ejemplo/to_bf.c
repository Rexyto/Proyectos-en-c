#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (50 * 1024 * 1024)  // 50MB máximo
#define BUFFER_SIZE 8192

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

void print_usage(const char *program_name) {
    printf("Uso: %s [opciones] archivo_entrada archivo_salida.bf\n", program_name);
    printf("Opciones:\n");
    printf("  -v, --verbose    Mostrar información detallada y progreso\n");
    printf("  -o, --optimize   Usar optimizaciones avanzadas\n");
    printf("  -h, --help       Mostrar esta ayuda\n");
    printf("  -c, --comment    Añadir comentarios al código generado\n");
}

long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

void print_progress(long current, long total, int verbose) {
    if (!verbose) return;
    
    int percent = (int)((current * 100) / total);
    static int last_percent = -1;
    
    if (percent != last_percent) {
        printf("\rProgreso: %d%% (%ld/%ld bytes)", percent, current, total);
        fflush(stdout);
        last_percent = percent;
    }
}

// Optimización: usar multiplicación en lugar de muchos + o -
void write_optimized_value(FILE *fout, int value, int add_comment) {
    if (value == 0) {
        if (add_comment) fprintf(fout, " # valor 0 (ya está)\n");
        return;
    }

    if (add_comment) fprintf(fout, " # valor %d\n", value);

    // Para valores grandes, usar multiplicación
    if (abs(value) > 15) {
        // Encontrar factores aproximados
        int factor1 = 1, factor2 = abs(value);
        
        // Buscar factores cercanos para minimizar operaciones
        for (int i = 2; i * i <= abs(value); i++) {
            if (abs(value) % i == 0) {
                int other = abs(value) / i;
                if (abs(i - other) < abs(factor1 - factor2)) {
                    factor1 = i;
                    factor2 = other;
                }
            }
        }

        if (factor1 > 1 && factor2 > 1 && factor1 <= 20 && factor2 <= 20) {
            // Usar multiplicación: factor1 * factor2
            for (int i = 0; i < factor1; i++) fputc('+', fout);
            fprintf(fout, "[>");
            for (int i = 0; i < factor2; i++) fputc('+', fout);
            fprintf(fout, "<-]>");
            
            // Ajustar si no es exacto
            int remainder = abs(value) - (factor1 * factor2);
            if (value > 0) {
                for (int i = 0; i < remainder; i++) fputc('+', fout);
            } else {
                // Para negativos, necesitamos ir al revés
                for (int i = 0; i < factor1 * factor2; i++) fputc('-', fout);
                for (int i = 0; i < remainder; i++) fputc('+', fout);
            }
            return;
        }
    }

    // Método simple para valores pequeños
    char op = (value > 0) ? '+' : '-';
    int count = abs(value);
    for (int i = 0; i < count; i++) {
        fputc(op, fout);
    }
}

int convert_file(const char *input_file, const char *output_file, int verbose, int optimize, int add_comments) {
    FILE *fin = fopen(input_file, "rb");
    if (!fin) {
        fprintf(stderr, "Error: No se pudo abrir archivo de entrada '%s': %s\n", 
                input_file, strerror(errno));
        return 0;
    }

    long file_size = get_file_size(input_file);
    if (file_size < 0) {
        print_error("No se pudo obtener el tamaño del archivo");
        fclose(fin);
        return 0;
    }

    if (file_size == 0) {
        print_error("El archivo de entrada está vacío");
        fclose(fin);
        return 0;
    }

    if (file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: El archivo es demasiado grande (%ld bytes). Máximo: %d bytes\n", 
                file_size, MAX_FILE_SIZE);
        fclose(fin);
        return 0;
    }

    FILE *fout = fopen(output_file, "w");
    if (!fout) {
        fprintf(stderr, "Error: No se pudo crear archivo de salida '%s': %s\n", 
                output_file, strerror(errno));
        fclose(fin);
        return 0;
    }

    if (verbose) {
        printf("Convirtiendo archivo: %s (%ld bytes)\n", input_file, file_size);
        printf("Archivo de salida: %s\n", output_file);
        if (optimize) printf("Optimizaciones activadas\n");
        if (add_comments) printf("Comentarios activados\n");
    }

    // Añadir encabezado con comentarios
    if (add_comments) {
        fprintf(fout, "# Archivo generado automáticamente por to_bf\n");
        fprintf(fout, "# Archivo original: %s (%ld bytes)\n", input_file, file_size);
        fprintf(fout, "# Este código Brainfuck reproduce el contenido del archivo original\n\n");
    }

    int prev = 0;
    int c;
    long bytes_processed = 0;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Leer archivo en chunks para archivos grandes
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            c = buffer[i];
            int diff = c - prev;
            
            if (add_comments && bytes_processed % 1000 == 0) {
                fprintf(fout, "\n# Byte %ld: %d", bytes_processed, c);
                if (c >= 32 && c <= 126) {
                    fprintf(fout, " ('%c')", c);
                }
                fprintf(fout, "\n");
            }
            
            if (optimize) {
                write_optimized_value(fout, diff, 0);
            } else {
                // Método simple
                if (diff > 0) {
                    for (int j = 0; j < diff; j++) fputc('+', fout);
                } else if (diff < 0) {
                    for (int j = 0; j < -diff; j++) fputc('-', fout);
                }
            }
            
            fputc('.', fout); // imprimir el byte
            
            // Añadir nueva línea ocasionalmente para legibilidad
            if (!add_comments && bytes_processed % 80 == 79) {
                fputc('\n', fout);
            }
            
            prev = c;
            bytes_processed++;
            
            if (verbose && bytes_processed % 1000 == 0) {
                print_progress(bytes_processed, file_size, verbose);
            }
        }
    }

    if (ferror(fin)) {
        print_error("Error leyendo el archivo de entrada");
        fclose(fin);
        fclose(fout);
        return 0;
    }

    if (add_comments) {
        fprintf(fout, "\n\n# Fin del archivo. Total de bytes: %ld\n", bytes_processed);
    }

    fclose(fin);
    fclose(fout);

    if (verbose) {
        printf("\nConversión completada exitosamente.\n");
        printf("Bytes procesados: %ld\n", bytes_processed);
        
        // Mostrar tamaño del archivo generado
        long output_size = get_file_size(output_file);
        if (output_size > 0) {
            printf("Tamaño del archivo Brainfuck: %ld bytes\n", output_size);
            printf("Ratio de compresión: %.2fx\n", (double)output_size / file_size);
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    int verbose = 0;
    int optimize = 0;
    int add_comments = 0;
    char *input_file = NULL;
    char *output_file = NULL;

    // Parsear argumentos
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--optimize") == 0) {
            optimize = 1;
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--comment") == 0) {
            add_comments = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else if (argv[i][0] == '-') {
            fprintf(stderr, "Opción desconocida: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        } else {
            if (!input_file) {
                input_file = argv[i];
            } else if (!output_file) {
                output_file = argv[i];
            } else {
                print_error("Demasiados argumentos");
                print_usage(argv[0]);
                return 1;
            }
        }
    }

    if (!input_file || !output_file) {
        print_error("Debe especificar archivo de entrada y salida");
        print_usage(argv[0]);
        return 1;
    }

    // Verificar que los archivos no sean el mismo
    if (strcmp(input_file, output_file) == 0) {
        print_error("El archivo de entrada y salida no pueden ser el mismo");
        return 1;
    }

    // Realizar la conversión
    if (convert_file(input_file, output_file, verbose, optimize, add_comments)) {
        return 0;
    } else {
        return 1;
    }
}