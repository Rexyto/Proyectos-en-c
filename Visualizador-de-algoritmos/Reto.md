#  Reto: Visualizador de Algoritmos de Ordenamiento

**Dificultad**: ⭐⭐⭐  

**Conceptos**: Algoritmos, Representación visual, Depuración, Estructuras de datos  

##  Descripción del Reto

Tu misión es crear un **visualizador interactivo de algoritmos de ordenamiento** que muestre paso a paso cómo funcionan los algoritmos más importantes. Este proyecto te enseñará implementación de algoritmos, visualización de datos, y programación interactiva en consola.

###  ¿Por qué este proyecto?

Los algoritmos de ordenamiento son fundamentales en ciencias de la computación, pero pueden ser abstractos y difíciles de entender. Un visualizador permite:
- **Ver** exactamente cómo trabaja cada algoritmo
- **Comparar** eficiencia y comportamiento
- **Entender** conceptos como recursión y divide-y-vencerás
- **Experimentar** con diferentes tipos de datos

##  Tareas del Proyecto

### Parte 1: Algoritmos Básicos
Implementa los tres algoritmos fundamentales con visualización completa.

**Algoritmos requeridos:**
- **Bubble Sort**: Algoritmo de intercambio simple
- **Quick Sort**: Divide y vencerás con pivot
- **Merge Sort**: Divide y vencerás con mezcla

**Características básicas:**
- **Visualización ASCII**: Barras y números
- **Paso a paso**: Pausa entre operaciones
- **Destacado visual**: Elementos siendo comparados
- **Explicaciones**: Descripción de cada operación

### Parte 2: Interfaz Interactiva
Crea un sistema de menús y controles usuario-amigable.

**Menú principal requerido:**
```
============================================================
         VISUALIZADOR DE ALGORITMOS DE ORDENAMIENTO
============================================================

  1. Bubble Sort (Burbuja)
  2. Quick Sort (Rápido)
  3. Merge Sort (Mezcla)
  4. Comparar todos los algoritmos
  5. Generar nuevo array
  6. Salir

Seleccione una opción (1-6):
```

**Funcionalidades del menú:**
- **Navegación numérica**: Selección por números 1-6
- **Generación automática**: Arrays sin entrada manual
- **Comparación**: Ejecutar todos los algoritmos secuencialmente
- **Control de flujo**: Pausas y continuación automática

### Parte 3: Generación de Datos 
Implementa diferentes tipos de arrays para probar los algoritmos.

**Tipos de arrays requeridos:**
- **Aleatorio**: Números del 1 al 50
- **Casi ordenado**: Solo algunos elementos fuera de lugar
- **Orden inverso**: Completamente desordenado (peor caso)  
- **Con duplicados**: Muchos números repetidos

**Características:**
- **Tamaño controlado**: 5-15 elementos (óptimo para visualización)
- **Generación automática**: Sin entrada manual del usuario
- **Casos de prueba**: Diferentes escenarios algorítmicos

##  Especificaciones Técnicas

### Visualización ASCII

**Formato de salida requerido:**
```
Comparando elementos marcados:
Posiciones:  0  1  2  3  4  5  6  7
Valores:    [64]<34> 25  12  22  11  90   5
Barras:     ########## *** ||| |  ||  |  |||||||||| |
--------------------------------------------------------

>>> 64 > 34, INTERCAMBIANDO <<<

Después del intercambio:
Posiciones:  0  1  2  3  4  5  6  7
Valores:    [34]<64> 25  12  22  11  90   5
Barras:     *** ########## ||| |  ||  |  |||||||||| |
--------------------------------------------------------
```

**Elementos visuales:**
- **Posiciones numeradas**: Índices 0, 1, 2, ...
- **Valores destacados**: `[elemento1]` `<elemento2>` para comparaciones
- **Barras ASCII**: `|` normal, `#` para primer elemento, `*` para segundo
- **Separadores**: Líneas de guiones para claridad

### Estructura del Código

**Funciones principales requeridas:**
```c
// Visualización
void print_array_visual(int arr[], int size, int highlight1, int highlight2, const char* operation);
void delay(int milliseconds);
void clear_screen();
void pause_screen();

// Algoritmos
void bubble_sort_visual(int arr[], int n);
void quick_sort_visual(int arr[], int low, int high, int n, int depth);
void merge_sort_visual(int arr[], int l, int r, int n, int depth);

// Generación de datos
void generate_random_array(int arr[], int n);
void generate_pattern_array(int arr[], int n, int pattern);

// Utilidades
void swap(int* a, int* b);
void copy_array(int source[], int dest[], int n);
```

### Configuración del Sistema

**Constantes requeridas:**
```c
#define MAX_SIZE 20        // Tamaño máximo del array
#define DELAY_MS 1000      // Pausa entre pasos (1 segundo)
```

**Compatibilidad:**
- **Sistema objetivo**: Windows
- **Librerías**: `stdio.h`, `stdlib.h`, `windows.h`, `conio.h`, `time.h`
- **Funciones específicas**: `Sleep()`, `_getch()`, `system("cls")`

##  Opciones de Línea de Comandos

**Compilación:**
```bash
gcc -o visualizador.exe sorting_visualizer.c
```

**Ejecución:**
```bash
visualizador.exe
```

**No se requieren parámetros**: El programa es completamente interactivo a través de menús.


##  Recursos Útiles

### Algoritmos
- [Visualización de algoritmos online](https://visualgo.net/en/sorting)
- [Análisis de complejidad](https://www.bigocheatsheet.com/)
- [Algoritmos en C](https://www.geeksforgeeks.org/sorting-algorithms/)
### ASCII Art
- [ASCII Table](https://www.asciitable.com/)
- [Técnicas visualización](https://en.wikipedia.org/wiki/ASCII_art)
