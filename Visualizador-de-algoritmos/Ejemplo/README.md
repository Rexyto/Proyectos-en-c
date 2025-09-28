#  Visualizador de Algoritmos de Ordenamiento

Un programa interactivo en C que muestra paso a paso cómo funcionan los algoritmos de ordenamiento más importantes, con visualización ASCII en tiempo real.

##  Características

###  Algoritmos Implementados
- **Bubble Sort (Burbuja)**: Algoritmo básico que compara elementos adyacentes
- **Quick Sort (Rápido)**: Algoritmo eficiente que usa divide y vencerás con pivot
- **Merge Sort (Mezcla)**: Algoritmo estable que divide y mezcla subarrays ordenados

###  Visualización
- **Representación numérica**: Posiciones y valores claramente marcados
- **Barras ASCII**: Representación gráfica con caracteres (`|`, `#`, `*`)
- **Destacado visual**: Elementos siendo comparados aparecen entre `[]` y `<>`
- **Explicaciones paso a paso**: Cada operación es explicada en detalle
- **Pausas controladas**: Velocidad ajustada para seguir fácilmente el proceso

###  Generación Automática de Arrays
- **Array aleatorio**: Números del 1 al 50
- **Array casi ordenado**: Solo algunos elementos fuera de lugar (mejor caso)
- **Array en orden inverso**: Completamente desordenado (peor caso)
- **Array con duplicados**: Muchos números repetidos

##  Instalación y Uso

### Requisitos
- **Sistema Operativo**: Windows
- **Compilador**: GCC (MinGW, Dev-C++, Code::Blocks, etc.)
- **Librerías**: Estándar de C (stdio.h, stdlib.h, windows.h, conio.h, time.h)

### Compilación
```bash
gcc -o visualizador.exe sorting_visualizer.c
```

### Ejecución
```bash
visualizador.exe
```

##  Menú Interactivo

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

##  Ejemplo de Visualización

```
>>> PASADA 1 <<<

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

##  Funcionalidades Principales

### 1. Algoritmos Individuales
- Visualización paso a paso de cada algoritmo
- Explicación de cada comparación e intercambio
- Destacado visual de elementos siendo procesados

### 2. Comparación de Algoritmos
- Ejecuta los tres algoritmos secuencialmente
- Permite observar diferencias en comportamiento
- Mismo array para comparación justa

### 3. Generación de Arrays
- **Aleatorio**: Para casos generales
- **Casi ordenado**: Para ver comportamiento en mejor caso
- **Orden inverso**: Para analizar peor caso
- **Con duplicados**: Para probar estabilidad

### 4. Controles Simples
- Navegación por menú numérico
- Pausas automáticas entre pasos
- Control manual para avanzar

##  Conceptos Educativos Demostrados

### Complejidad Temporal
- **Bubble Sort**: O(n²) en todos los casos
- **Quick Sort**: O(n log n) promedio, O(n²) peor caso
- **Merge Sort**: O(n log n) en todos los casos

### Técnicas Algorítmicas
- **Comparación directa** (Bubble Sort)
- **Divide y vencerás** (Quick Sort, Merge Sort)
- **Recursión** (Quick Sort, Merge Sort)
- **Particionamiento** (Quick Sort)
- **Mezcla de subarrays** (Merge Sort)

### Características de Algoritmos
- **Estabilidad**: Preservación del orden relativo
- **In-place**: Uso de memoria adicional
- **Adaptabilidad**: Comportamiento con datos parcialmente ordenados



##  Uso Educativo

### Para Estudiantes
- Comprende visualmente cómo funcionan los algoritmos
- Observa diferencias en eficiencia y comportamiento
- Experimenta con diferentes tipos de datos

### Para Profesores
- Herramienta de demostración en clase
- Ejemplos concretos de conceptos teóricos
- Comparación práctica de algoritmos

### Conceptos Reforzados
- **Análisis de algoritmos**
- **Estructuras de datos**
- **Recursión y divide y vencerás**
- **Complejidad computacional**
- **Programación en C**

##  Solución de Problemas

### Problemas Comunes
- **Error de compilación**: Verificar que GCC esté instalado correctamente
- **Pantalla parpadeante**: El programa controla automáticamente la velocidad
- **Caracteres extraños**: Usa solo ASCII simple, compatible con cualquier terminal

### Compatibilidad
- **Windows 7/8/10/11**: Totalmente compatible
- **Terminales**: CMD, PowerShell, terminales de IDE
- **Compiladores**: GCC, MinGW, Clang

##  Casos de Uso

### Aprendizaje
```
Opción 5 → Generar array aleatorio → Opción 1 (Bubble Sort)
Observar paso a paso cómo funciona el algoritmo básico
```

### Comparación
```
Opción 4 → Ver los tres algoritmos con el mismo array
Comparar eficiencia y diferentes enfoques
```

### Análisis de Casos
```
Opción 5 → Array en orden inverso → Cualquier algoritmo
Observar comportamiento en peor caso
```