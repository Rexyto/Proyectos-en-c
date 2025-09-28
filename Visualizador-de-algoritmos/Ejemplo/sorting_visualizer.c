<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_SIZE 20
#define DELAY_MS 1000

// Hacer pausa
void delay(int milliseconds) {
    Sleep(milliseconds);
}

// Limpiar pantalla
void clear_screen() {
    system("cls");
}

// Pausa hasta que se presione una tecla
void pause_screen() {
    printf("\nPresiona cualquier tecla para continuar...");
    _getch();
}

// Imprimir array de forma visual
void print_array_visual(int arr[], int size, int highlight1, int highlight2, const char* operation) {
    printf("\n%s\n", operation);
    printf("Posiciones: ");
    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    printf("Valores:    ");
    for (int i = 0; i < size; i++) {
        if (i == highlight1) printf("[%2d]", arr[i]);
        else if (i == highlight2) printf("<%2d>", arr[i]);
        else printf(" %2d ", arr[i]);
    }
    printf("\n");
    
    // Representacion con barras ASCII
    printf("Barras:     ");
    for (int i = 0; i < size; i++) {
        char bar = '|';
        if (i == highlight1) bar = '#';
        else if (i == highlight2) bar = '*';
        
        int height = arr[i];
        if (height > 10) height = 10; // Limitar altura
        if (height < 1) height = 1;   // Minimo 1 barra
        
        for (int j = 0; j < height; j++) {
            printf("%c", bar);
        }
        printf(" ");
    }
    printf("\n");
    for (int i = 0; i < 60; i++) printf("-");
    printf("\n");
}

// Intercambiar elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// BUBBLE SORT con visualizacion
void bubble_sort_visual(int arr[], int n) {
    clear_screen();
    printf("\n=== BUBBLE SORT ===\n");
    printf("Algoritmo: Compara elementos adyacentes e intercambia si estan desordenados\n");
    print_array_visual(arr, n, -1, -1, "Estado inicial:");
    delay(DELAY_MS);
    
    for (int i = 0; i < n - 1; i++) {
        printf("\n>>> PASADA %d <<<\n", i + 1);
        
        for (int j = 0; j < n - i - 1; j++) {
            print_array_visual(arr, n, j, j + 1, "Comparando elementos marcados:");
            printf("Comparando: arr[%d]=%d con arr[%d]=%d\n", j, arr[j], j+1, arr[j+1]);
            delay(DELAY_MS);
            
            if (arr[j] > arr[j + 1]) {
                printf(">>> %d > %d, INTERCAMBIANDO <<<\n", arr[j], arr[j+1]);
                swap(&arr[j], &arr[j + 1]);
                print_array_visual(arr, n, j, j + 1, "Despues del intercambio:");
                delay(DELAY_MS);
            } else {
                printf(">>> %d <= %d, NO se intercambia <<<\n", arr[j], arr[j+1]);
                delay(DELAY_MS / 2);
            }
        }
        printf(">>> El elemento %d esta en su posicion final <<<\n", arr[n - i - 1]);
        delay(DELAY_MS);
    }
    
    print_array_visual(arr, n, -1, -1, "ORDENAMIENTO COMPLETO!");
    pause_screen();
}

// Particion para Quick Sort
int partition_visual(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = (low - 1);
    
    printf("\n>>> PARTICIONANDO <<<\n");
    printf("Pivot seleccionado: %d (posicion %d)\n", pivot, high);
    print_array_visual(arr, n, high, -1, "Pivot marcado:");
    delay(DELAY_MS);
    
    for (int j = low; j <= high - 1; j++) {
        print_array_visual(arr, n, j, high, "Comparando con pivot:");
        printf("Comparando: %d con pivot %d\n", arr[j], pivot);
        delay(DELAY_MS);
        
        if (arr[j] < pivot) {
            i++;
            printf(">>> %d < %d (pivot), moviendo a la izquierda <<<\n", arr[j], pivot);
            if (i != j) {
                swap(&arr[i], &arr[j]);
                print_array_visual(arr, n, i, j, "Despues del intercambio:");
                delay(DELAY_MS);
            }
        } else {
            printf(">>> %d >= %d (pivot), se queda a la derecha <<<\n", arr[j], pivot);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    printf(">>> Colocando pivot en su posicion final: %d <<<\n", i + 1);
    print_array_visual(arr, n, i + 1, -1, "Pivot en posicion correcta:");
    delay(DELAY_MS);
    
    return (i + 1);
}

void quick_sort_visual(int arr[], int low, int high, int n, int depth) {
    if (low < high) {
        printf("\n--- NIVEL DE RECURSION %d ---\n", depth);
        printf("Ordenando desde posicion %d hasta %d\n", low, high);
        
        int pi = partition_visual(arr, low, high, n);
        
        printf("Particion completa. Pivot en posicion %d\n", pi);
        if (pi - 1 >= low) printf("Siguiente: ordenar izquierda [%d-%d]\n", low, pi - 1);
        if (pi + 1 <= high) printf("Siguiente: ordenar derecha [%d-%d]\n", pi + 1, high);
        delay(DELAY_MS);
        
        quick_sort_visual(arr, low, pi - 1, n, depth + 1);
        quick_sort_visual(arr, pi + 1, high, n, depth + 1);
    }
}

// Mezcla para Merge Sort
void merge_visual(int arr[], int l, int m, int r, int n) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[MAX_SIZE], R[MAX_SIZE];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    printf("\n>>> MEZCLANDO SUBARRAYS <<<\n");
    printf("Izquierdo [%d-%d]: ", l, m);
    for (i = 0; i < n1; i++) printf("%d ", L[i]);
    printf("\nDerecho [%d-%d]: ", m+1, r);
    for (j = 0; j < n2; j++) printf("%d ", R[j]);
    printf("\n");
    delay(DELAY_MS);
    
    i = 0; j = 0; k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            printf("Tomando %d del izquierdo\n", L[i]);
            i++;
        } else {
            arr[k] = R[j];
            printf("Tomando %d del derecho\n", R[j]);
            j++;
        }
        k++;
        print_array_visual(arr, n, k-1, -1, "Estado despues de mezcla:");
        delay(DELAY_MS);
    }
    
    while (i < n1) {
        arr[k] = L[i];
        printf("Copiando resto izquierdo: %d\n", L[i]);
        i++; k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        printf("Copiando resto derecho: %d\n", R[j]);
        j++; k++;
    }
    
    printf(">>> Mezcla completada para [%d-%d] <<<\n", l, r);
    delay(DELAY_MS);
}

void merge_sort_visual(int arr[], int l, int r, int n, int depth) {
    if (l < r) {
        printf("\n--- NIVEL DE RECURSION %d ---\n", depth);
        printf("Dividiendo desde posicion %d hasta %d\n", l, r);
        
        int m = l + (r - l) / 2;
        printf("Punto medio: %d -> [%d-%d] y [%d-%d]\n", m, l, m, m+1, r);
        delay(DELAY_MS);
        
        merge_sort_visual(arr, l, m, n, depth + 1);
        merge_sort_visual(arr, m + 1, r, n, depth + 1);
        merge_visual(arr, l, m, r, n);
    }
}

// Generar array aleatorio
void generate_random_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1; // numeros del 1 al 50
    }
}

// Generar array con patron especifico
void generate_pattern_array(int arr[], int n, int pattern) {
    switch (pattern) {
        case 1: // Array aleatorio
            generate_random_array(arr, n);
            break;
        case 2: // Array casi ordenado
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            // Desordenar solo algunos elementos
            if (n > 2) {
                swap(&arr[n-1], &arr[n-2]);
                swap(&arr[1], &arr[3]);
            }
            break;
        case 3: // Array en orden inverso
            for (int i = 0; i < n; i++) {
                arr[i] = n - i;
            }
            break;
        case 4: // Array con muchos duplicados
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                arr[i] = (rand() % 5) + 1; // solo numeros 1-5
            }
            break;
    }
}

// Copiar array
void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Menu principal
void print_menu() {
    clear_screen();
    printf("\n");
    for (int i = 0; i < 60; i++) printf("=");
    printf("\n");
    printf("         VISUALIZADOR DE ALGORITMOS DE ORDENAMIENTO\n");
    for (int i = 0; i < 60; i++) printf("=");
    printf("\n\n");
    printf("  1. Bubble Sort (Burbuja)\n");
    printf("  2. Quick Sort (Rapido)\n");
    printf("  3. Merge Sort (Mezcla)\n");
    printf("  4. Comparar todos los algoritmos\n");
    printf("  5. Generar nuevo array\n");
    printf("  6. Salir\n\n");
    printf("Seleccione una opcion (1-6): ");
}

void show_current_array(int arr[], int n) {
    printf("\nArray actual (%d elementos): ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void show_generation_menu() {
    printf("\n=== GENERAR NUEVO ARRAY ===\n");
    printf("1. Array aleatorio\n");
    printf("2. Array casi ordenado\n");
    printf("3. Array en orden inverso\n");
    printf("4. Array con duplicados\n");
    printf("Seleccione tipo (1-4): ");
}

int main() {
    int arr[MAX_SIZE];
    int arr_copy[MAX_SIZE];
    int n = 10; // tamaño por defecto
    int choice, pattern, new_size;
    
    // Generar array inicial aleatorio
    printf("=== BIENVENIDO AL VISUALIZADOR ===\n");
    printf("Generando array aleatorio inicial...\n");
    generate_random_array(arr, n);
    delay(1000);
    
    while (1) {
        print_menu();
        show_current_array(arr, n);
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                copy_array(arr, arr_copy, n);
                bubble_sort_visual(arr_copy, n);
                break;
                
            case 2:
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n=== QUICK SORT ===\n");
                printf("Algoritmo: Divide y venceras usando pivot\n");
                print_array_visual(arr_copy, n, -1, -1, "Estado inicial:");
                delay(DELAY_MS);
                quick_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "ORDENAMIENTO COMPLETO!");
                pause_screen();
                break;
                
            case 3:
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n=== MERGE SORT ===\n");
                printf("Algoritmo: Divide y venceras con mezcla\n");
                print_array_visual(arr_copy, n, -1, -1, "Estado inicial:");
                delay(DELAY_MS);
                merge_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "ORDENAMIENTO COMPLETO!");
                pause_screen();
                break;
                
            case 4:
                clear_screen();
                printf("\n=== COMPARACION DE ALGORITMOS ===\n");
                show_current_array(arr, n);
                printf("Ejecutando todos...\n");
                pause_screen();
                
                copy_array(arr, arr_copy, n);
                bubble_sort_visual(arr_copy, n);
                
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n--- QUICK SORT ---\n");
                quick_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "QUICK SORT COMPLETO!");
                pause_screen();
                
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n--- MERGE SORT ---\n");
                merge_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "MERGE SORT COMPLETO!");
                pause_screen();
                break;
                
            case 5:
                clear_screen();
                printf("Tamaño actual: %d elementos\n", n);
                printf("Nuevo tamaño (5-15): ");
                scanf("%d", &new_size);
                
                if (new_size < 5 || new_size > 15) {
                    printf("Tamaño invalido. Usando 10.\n");
                    new_size = 10;
                }
                n = new_size;
                
                show_generation_menu();
                scanf("%d", &pattern);
                
                if (pattern < 1 || pattern > 4) pattern = 1;
                
                generate_pattern_array(arr, n, pattern);
                printf("Array generado!\n");
                pause_screen();
                break;
                
            case 6:
                clear_screen();
                printf("Gracias por usar el visualizador!\n");
                pause_screen();
                return 0;
                
            default:
                printf("Opcion invalida.");
                pause_screen();
        }
    }
    
    return 0;
=======
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_SIZE 20
#define DELAY_MS 1000

// Hacer pausa
void delay(int milliseconds) {
    Sleep(milliseconds);
}

// Limpiar pantalla
void clear_screen() {
    system("cls");
}

// Pausa hasta que se presione una tecla
void pause_screen() {
    printf("\nPresiona cualquier tecla para continuar...");
    _getch();
}

// Imprimir array de forma visual
void print_array_visual(int arr[], int size, int highlight1, int highlight2, const char* operation) {
    printf("\n%s\n", operation);
    printf("Posiciones: ");
    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    printf("Valores:    ");
    for (int i = 0; i < size; i++) {
        if (i == highlight1) printf("[%2d]", arr[i]);
        else if (i == highlight2) printf("<%2d>", arr[i]);
        else printf(" %2d ", arr[i]);
    }
    printf("\n");
    
    // Representacion con barras ASCII
    printf("Barras:     ");
    for (int i = 0; i < size; i++) {
        char bar = '|';
        if (i == highlight1) bar = '#';
        else if (i == highlight2) bar = '*';
        
        int height = arr[i];
        if (height > 10) height = 10; // Limitar altura
        if (height < 1) height = 1;   // Minimo 1 barra
        
        for (int j = 0; j < height; j++) {
            printf("%c", bar);
        }
        printf(" ");
    }
    printf("\n");
    for (int i = 0; i < 60; i++) printf("-");
    printf("\n");
}

// Intercambiar elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// BUBBLE SORT con visualizacion
void bubble_sort_visual(int arr[], int n) {
    clear_screen();
    printf("\n=== BUBBLE SORT ===\n");
    printf("Algoritmo: Compara elementos adyacentes e intercambia si estan desordenados\n");
    print_array_visual(arr, n, -1, -1, "Estado inicial:");
    delay(DELAY_MS);
    
    for (int i = 0; i < n - 1; i++) {
        printf("\n>>> PASADA %d <<<\n", i + 1);
        
        for (int j = 0; j < n - i - 1; j++) {
            print_array_visual(arr, n, j, j + 1, "Comparando elementos marcados:");
            printf("Comparando: arr[%d]=%d con arr[%d]=%d\n", j, arr[j], j+1, arr[j+1]);
            delay(DELAY_MS);
            
            if (arr[j] > arr[j + 1]) {
                printf(">>> %d > %d, INTERCAMBIANDO <<<\n", arr[j], arr[j+1]);
                swap(&arr[j], &arr[j + 1]);
                print_array_visual(arr, n, j, j + 1, "Despues del intercambio:");
                delay(DELAY_MS);
            } else {
                printf(">>> %d <= %d, NO se intercambia <<<\n", arr[j], arr[j+1]);
                delay(DELAY_MS / 2);
            }
        }
        printf(">>> El elemento %d esta en su posicion final <<<\n", arr[n - i - 1]);
        delay(DELAY_MS);
    }
    
    print_array_visual(arr, n, -1, -1, "ORDENAMIENTO COMPLETO!");
    pause_screen();
}

// Particion para Quick Sort
int partition_visual(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = (low - 1);
    
    printf("\n>>> PARTICIONANDO <<<\n");
    printf("Pivot seleccionado: %d (posicion %d)\n", pivot, high);
    print_array_visual(arr, n, high, -1, "Pivot marcado:");
    delay(DELAY_MS);
    
    for (int j = low; j <= high - 1; j++) {
        print_array_visual(arr, n, j, high, "Comparando con pivot:");
        printf("Comparando: %d con pivot %d\n", arr[j], pivot);
        delay(DELAY_MS);
        
        if (arr[j] < pivot) {
            i++;
            printf(">>> %d < %d (pivot), moviendo a la izquierda <<<\n", arr[j], pivot);
            if (i != j) {
                swap(&arr[i], &arr[j]);
                print_array_visual(arr, n, i, j, "Despues del intercambio:");
                delay(DELAY_MS);
            }
        } else {
            printf(">>> %d >= %d (pivot), se queda a la derecha <<<\n", arr[j], pivot);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    printf(">>> Colocando pivot en su posicion final: %d <<<\n", i + 1);
    print_array_visual(arr, n, i + 1, -1, "Pivot en posicion correcta:");
    delay(DELAY_MS);
    
    return (i + 1);
}

void quick_sort_visual(int arr[], int low, int high, int n, int depth) {
    if (low < high) {
        printf("\n--- NIVEL DE RECURSION %d ---\n", depth);
        printf("Ordenando desde posicion %d hasta %d\n", low, high);
        
        int pi = partition_visual(arr, low, high, n);
        
        printf("Particion completa. Pivot en posicion %d\n", pi);
        if (pi - 1 >= low) printf("Siguiente: ordenar izquierda [%d-%d]\n", low, pi - 1);
        if (pi + 1 <= high) printf("Siguiente: ordenar derecha [%d-%d]\n", pi + 1, high);
        delay(DELAY_MS);
        
        quick_sort_visual(arr, low, pi - 1, n, depth + 1);
        quick_sort_visual(arr, pi + 1, high, n, depth + 1);
    }
}

// Mezcla para Merge Sort
void merge_visual(int arr[], int l, int m, int r, int n) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[MAX_SIZE], R[MAX_SIZE];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    printf("\n>>> MEZCLANDO SUBARRAYS <<<\n");
    printf("Izquierdo [%d-%d]: ", l, m);
    for (i = 0; i < n1; i++) printf("%d ", L[i]);
    printf("\nDerecho [%d-%d]: ", m+1, r);
    for (j = 0; j < n2; j++) printf("%d ", R[j]);
    printf("\n");
    delay(DELAY_MS);
    
    i = 0; j = 0; k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            printf("Tomando %d del izquierdo\n", L[i]);
            i++;
        } else {
            arr[k] = R[j];
            printf("Tomando %d del derecho\n", R[j]);
            j++;
        }
        k++;
        print_array_visual(arr, n, k-1, -1, "Estado despues de mezcla:");
        delay(DELAY_MS);
    }
    
    while (i < n1) {
        arr[k] = L[i];
        printf("Copiando resto izquierdo: %d\n", L[i]);
        i++; k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        printf("Copiando resto derecho: %d\n", R[j]);
        j++; k++;
    }
    
    printf(">>> Mezcla completada para [%d-%d] <<<\n", l, r);
    delay(DELAY_MS);
}

void merge_sort_visual(int arr[], int l, int r, int n, int depth) {
    if (l < r) {
        printf("\n--- NIVEL DE RECURSION %d ---\n", depth);
        printf("Dividiendo desde posicion %d hasta %d\n", l, r);
        
        int m = l + (r - l) / 2;
        printf("Punto medio: %d -> [%d-%d] y [%d-%d]\n", m, l, m, m+1, r);
        delay(DELAY_MS);
        
        merge_sort_visual(arr, l, m, n, depth + 1);
        merge_sort_visual(arr, m + 1, r, n, depth + 1);
        merge_visual(arr, l, m, r, n);
    }
}

// Generar array aleatorio
void generate_random_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1; // numeros del 1 al 50
    }
}

// Generar array con patron especifico
void generate_pattern_array(int arr[], int n, int pattern) {
    switch (pattern) {
        case 1: // Array aleatorio
            generate_random_array(arr, n);
            break;
        case 2: // Array casi ordenado
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            // Desordenar solo algunos elementos
            if (n > 2) {
                swap(&arr[n-1], &arr[n-2]);
                swap(&arr[1], &arr[3]);
            }
            break;
        case 3: // Array en orden inverso
            for (int i = 0; i < n; i++) {
                arr[i] = n - i;
            }
            break;
        case 4: // Array con muchos duplicados
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                arr[i] = (rand() % 5) + 1; // solo numeros 1-5
            }
            break;
    }
}

// Copiar array
void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Menu principal
void print_menu() {
    clear_screen();
    printf("\n");
    for (int i = 0; i < 60; i++) printf("=");
    printf("\n");
    printf("         VISUALIZADOR DE ALGORITMOS DE ORDENAMIENTO\n");
    for (int i = 0; i < 60; i++) printf("=");
    printf("\n\n");
    printf("  1. Bubble Sort (Burbuja)\n");
    printf("  2. Quick Sort (Rapido)\n");
    printf("  3. Merge Sort (Mezcla)\n");
    printf("  4. Comparar todos los algoritmos\n");
    printf("  5. Generar nuevo array\n");
    printf("  6. Salir\n\n");
    printf("Seleccione una opcion (1-6): ");
}

void show_current_array(int arr[], int n) {
    printf("\nArray actual (%d elementos): ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void show_generation_menu() {
    printf("\n=== GENERAR NUEVO ARRAY ===\n");
    printf("1. Array aleatorio\n");
    printf("2. Array casi ordenado\n");
    printf("3. Array en orden inverso\n");
    printf("4. Array con duplicados\n");
    printf("Seleccione tipo (1-4): ");
}

int main() {
    int arr[MAX_SIZE];
    int arr_copy[MAX_SIZE];
    int n = 10; // tamaño por defecto
    int choice, pattern, new_size;
    
    // Generar array inicial aleatorio
    printf("=== BIENVENIDO AL VISUALIZADOR ===\n");
    printf("Generando array aleatorio inicial...\n");
    generate_random_array(arr, n);
    delay(1000);
    
    while (1) {
        print_menu();
        show_current_array(arr, n);
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                copy_array(arr, arr_copy, n);
                bubble_sort_visual(arr_copy, n);
                break;
                
            case 2:
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n=== QUICK SORT ===\n");
                printf("Algoritmo: Divide y venceras usando pivot\n");
                print_array_visual(arr_copy, n, -1, -1, "Estado inicial:");
                delay(DELAY_MS);
                quick_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "ORDENAMIENTO COMPLETO!");
                pause_screen();
                break;
                
            case 3:
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n=== MERGE SORT ===\n");
                printf("Algoritmo: Divide y venceras con mezcla\n");
                print_array_visual(arr_copy, n, -1, -1, "Estado inicial:");
                delay(DELAY_MS);
                merge_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "ORDENAMIENTO COMPLETO!");
                pause_screen();
                break;
                
            case 4:
                clear_screen();
                printf("\n=== COMPARACION DE ALGORITMOS ===\n");
                show_current_array(arr, n);
                printf("Ejecutando todos...\n");
                pause_screen();
                
                copy_array(arr, arr_copy, n);
                bubble_sort_visual(arr_copy, n);
                
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n--- QUICK SORT ---\n");
                quick_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "QUICK SORT COMPLETO!");
                pause_screen();
                
                copy_array(arr, arr_copy, n);
                clear_screen();
                printf("\n--- MERGE SORT ---\n");
                merge_sort_visual(arr_copy, 0, n - 1, n, 0);
                print_array_visual(arr_copy, n, -1, -1, "MERGE SORT COMPLETO!");
                pause_screen();
                break;
                
            case 5:
                clear_screen();
                printf("Tamaño actual: %d elementos\n", n);
                printf("Nuevo tamaño (5-15): ");
                scanf("%d", &new_size);
                
                if (new_size < 5 || new_size > 15) {
                    printf("Tamaño invalido. Usando 10.\n");
                    new_size = 10;
                }
                n = new_size;
                
                show_generation_menu();
                scanf("%d", &pattern);
                
                if (pattern < 1 || pattern > 4) pattern = 1;
                
                generate_pattern_array(arr, n, pattern);
                printf("Array generado!\n");
                pause_screen();
                break;
                
            case 6:
                clear_screen();
                printf("Gracias por usar el visualizador!\n");
                pause_screen();
                return 0;
                
            default:
                printf("Opcion invalida.");
                pause_screen();
        }
    }
    
    return 0;
>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
}