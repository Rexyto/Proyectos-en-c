<<<<<<< HEAD
#  Calculadora Científica en C

Una calculadora científica completa desarrollada en C con interfaz gráfica nativa de Windows usando la API de Windows.

## Características

###  Operaciones Básicas
-  Suma (+)
-  Resta (-)
-  Multiplicación (*)
-  División (/)
-  Números decimales

###  Funciones Científicas
- **Trigonometría**: sin, cos, tan (en grados)
- **Logaritmos**: ln (logaritmo natural), log (logaritmo base 10)
- **Raíces**: sqrt (raíz cuadrada)
- **Exponenciales**: e^x, x^y (potencias)
- **Factorial**: x! (números enteros)

###  Constantes Matemáticas
- **π (pi)**: 3.14159265...
- **e (número de Euler)**: 2.71828182...

###  Controles
- **C**: Limpiar todo
- **DEL**: Borrar último dígito
- **=**: Calcular resultado

##  Compilación

### Requisitos
- Compilador GCC (MinGW) o Microsoft Visual Studio
- Windows (utiliza Windows API)

### Con MinGW/GCC
```bash
gcc calculadora.c -o calculadora.exe -luser32 -lgdi32 -lm
```
##  Uso

1. **Ejecutar** el archivo `calculadora.exe`
2. **Introducir números** usando los botones numéricos
3. **Seleccionar operación** (+, -, *, /, x^y)
4. **Usar funciones científicas** directamente sobre el número mostrado
5. **Presionar =** para obtener el resultado

###  Ejemplos de Uso

- **Operación básica**: `5 + 3 = 8`
- **Seno de 90°**: Introducir `90`, presionar `sin` → `1`
- **Logaritmo natural**: Introducir `2.718`, presionar `ln` → `≈1`
- **Potencia**: `2 x^y 3 = 8`
- **Factorial**: Introducir `5`, presionar `x!` → `120`

##  Interfaz

La calculadora presenta:
- **Display grande** con números claros
- **Botones organizados** por categorías
- **Diseño intuitivo** similar a calculadoras físicas
- **Tamaño compacto** (450x520 pixels)

##  Características Técnicas

- **Precisión**: Números de doble precisión (64 bits)
- **Manejo de errores**: División por cero, raíces de negativos, etc.
- **Formato automático**: Elimina ceros innecesarios
- **Validación de entrada**: Previene errores de usuario

##  Manejo de Errores

La calculadora maneja automáticamente:
- ❌ División por cero → "Error"
- ❌ Raíz cuadrada de números negativos → "Error"  
- ❌ Logaritmos de números ≤ 0 → "Error"
- ❌ Factorial de números no enteros o muy grandes → "Error"
=======
#  Calculadora Científica en C

Una calculadora científica completa desarrollada en C con interfaz gráfica nativa de Windows usando la API de Windows.

## Características

###  Operaciones Básicas
-  Suma (+)
-  Resta (-)
-  Multiplicación (*)
-  División (/)
-  Números decimales

###  Funciones Científicas
- **Trigonometría**: sin, cos, tan (en grados)
- **Logaritmos**: ln (logaritmo natural), log (logaritmo base 10)
- **Raíces**: sqrt (raíz cuadrada)
- **Exponenciales**: e^x, x^y (potencias)
- **Factorial**: x! (números enteros)

###  Constantes Matemáticas
- **π (pi)**: 3.14159265...
- **e (número de Euler)**: 2.71828182...

###  Controles
- **C**: Limpiar todo
- **DEL**: Borrar último dígito
- **=**: Calcular resultado

##  Compilación

### Requisitos
- Compilador GCC (MinGW) o Microsoft Visual Studio
- Windows (utiliza Windows API)

### Con MinGW/GCC
```bash
gcc calculadora.c -o calculadora.exe -luser32 -lgdi32 -lm
```
##  Uso

1. **Ejecutar** el archivo `calculadora.exe`
2. **Introducir números** usando los botones numéricos
3. **Seleccionar operación** (+, -, *, /, x^y)
4. **Usar funciones científicas** directamente sobre el número mostrado
5. **Presionar =** para obtener el resultado

###  Ejemplos de Uso

- **Operación básica**: `5 + 3 = 8`
- **Seno de 90°**: Introducir `90`, presionar `sin` → `1`
- **Logaritmo natural**: Introducir `2.718`, presionar `ln` → `≈1`
- **Potencia**: `2 x^y 3 = 8`
- **Factorial**: Introducir `5`, presionar `x!` → `120`

##  Interfaz

La calculadora presenta:
- **Display grande** con números claros
- **Botones organizados** por categorías
- **Diseño intuitivo** similar a calculadoras físicas
- **Tamaño compacto** (450x520 pixels)

##  Características Técnicas

- **Precisión**: Números de doble precisión (64 bits)
- **Manejo de errores**: División por cero, raíces de negativos, etc.
- **Formato automático**: Elimina ceros innecesarios
- **Validación de entrada**: Previene errores de usuario

##  Manejo de Errores

La calculadora maneja automáticamente:
- ❌ División por cero → "Error"
- ❌ Raíz cuadrada de números negativos → "Error"  
- ❌ Logaritmos de números ≤ 0 → "Error"
- ❌ Factorial de números no enteros o muy grandes → "Error"
>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
