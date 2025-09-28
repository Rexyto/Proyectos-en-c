#  Reto: Calculadora Científica con GUI en C

**Dificultad**: ⭐⭐⭐

**Conceptos**: GUI Programming, Windows API, Parsing matemático, Manejo de eventos

##  Descripción del Reto

Tu misión es crear una **calculadora científica completa con interfaz gráfica nativa** utilizando la Windows API en C. Este proyecto te enseñará programación de interfaces gráficas, manejo de eventos, análisis de expresiones matemáticas, y diseño de software robusto.

### ¿Qué incluye una Calculadora Científica?

Una calculadora científica moderna debe manejar:
```
| Categoría         |                Funciones                      |
|-------------------|-----------------------------------------------|
| Básicas           | +, -, *, /, números decimales                 |
| Científicas       | sin, cos, tan, ln, log, sqrt, x^y, e^x        |
| Constantes        | π (pi), e (número de Euler)                   |
| Especiales        | x! (factorial), paréntesis                    |
| Controles         | C (limpiar), DEL (borrar), = (calcular)       |
```

## Tareas del Proyecto

### Parte 1: Calculadora Básica con GUI 
Crea un programa `calculadora.c` que implemente una calculadora con interfaz gráfica.

**Características requeridas:**
- **Interfaz nativa**: Usar Windows API (CreateWindow, etc.)
- **Display visual**: Pantalla grande para mostrar números y resultados
- **Botones intuitivos**: Layout similar a calculadoras físicas
- **Manejo de eventos**: Responder a clicks de botones correctamente
- **Aritmética básica**: +, -, *, /, números decimales
- **Validación de entrada**: Prevenir errores de usuario
- **Manejo de memoria**: Gestión correcta de operandos y operadores

**Requisitos técnicos:**
```c
// Estructura básica requerida
#define ID_DISPLAY 1001
#define ID_BUTTON_BASE 1010

HWND hDisplay;
char displayText[256] = "0";
double operand1 = 0, operand2 = 0;
char operator = 0;
int waitingForOperand = 1;
```

### Parte 2: Funciones Científicas Avanzadas 
Extiende la calculadora con funcionalidades científicas completas.

**Funciones trigonométricas:**
- **sin, cos, tan**: Trabajar en grados (conversión automática)
- **Precisión**: Manejar valores especiales (sin(90°) = 1 exacto)
- **Validación**: Detectar valores fuera de dominio

**Funciones logarítmicas y exponenciales:**
- **ln**: Logaritmo natural (base e)
- **log**: Logaritmo decimal (base 10)  
- **e^x**: Función exponencial
- **x^y**: Potencias generales
- **sqrt**: Raíz cuadrada con validación de negativos

**Funciones especiales:**
- **x!**: Factorial (solo enteros no negativos ≤ 170)
- **Constantes**: π y e con precisión de 15 dígitos

### Parte 3: Interfaz y Usabilidad Profesional 
Crear una experiencia de usuario pulida y profesional.

**Diseño visual:**
```
┌─────────────────────────────────────────────┐
│ Display: 3.14159265358979323846             │
├─────────────────────────────────────────────┤
│ sin │ cos │ tan │ ln  │ log │  C  │         │
│ sqt │ x^y │ e^x │ x!  │ pi  │ DEL │         │
├─────────────────────────────────────────────┤
│  7  │  8  │  9  │  /  │  e  │               │
│  4  │  5  │  6  │  *  │     │               │
│  1  │  2  │  3  │  -  │  =  │               │
│     0     │  .  │  +  │     │               │
└─────────────────────────────────────────────┘
```

**Características de usabilidad:**
- **Botones grandes**: Fáciles de clickear (mínimo 40x40 px)
- **Fuente grande**: Display con texto legible (28px)
- **Colores consistentes**: Esquema de colores profesional
- **Feedback visual**: Botones que responden al hover/click
- **Layouts responsivo**: Botones bien distribuidos sin solapamiento

##  Especificaciones Técnicas


### Validación y Manejo de Errores

**Casos de error requeridos:**
- **División por cero** → Mostrar "Error"
- **Raíz cuadrada de negativo** → Mostrar "Error"
- **Logaritmo de ≤ 0** → Mostrar "Error"
- **Factorial de no entero** → Mostrar "Error"
- **Factorial > 170** → Mostrar "Error" (overflow)
- **Operaciones con "Error"** → Mantener estado de error

##  Casos de Prueba

### Tests de Funcionalidad Básica:

1. **Aritmética simple**
```
Input: 5 + 3 =
Expected: 8

Input: 10 - 4 =  
Expected: 6

Input: 7 * 8 =
Expected: 56

Input: 15 / 3 =
Expected: 5
```

2. **Números decimales**
```
Input: 3.14 + 2.86 =
Expected: 6

Input: 0.1 + 0.2 =
Expected: 0.3 (manejar precisión flotante)
```

### Tests de Funciones Científicas:

3. **Trigonometría**
```
Input: 90, sin
Expected: 1

Input: 0, cos  
Expected: 1

Input: 45, tan
Expected: 1 (aproximadamente)
```

4. **Logaritmos y exponenciales**
```
Input: 10, log
Expected: 1

Input: e (botón), ln
Expected: 1

Input: 2, e^x
Expected: 7.389... (e²)
```

5. **Funciones especiales**
```
Input: 5, x!
Expected: 120

Input: pi (botón)
Expected: 3.14159265...

Input: 9, sqrt
Expected: 3
```

### Tests de Manejo de Errores:

6. **Errores matemáticos**
```
Input: 5, /, 0, =
Expected: Error

Input: -4, sqrt
Expected: Error

Input: 0, ln
Expected: Error

Input: 3.5, x!
Expected: Error
```

##  Instrucciones de Compilación

### Compilación con MinGW/GCC:
```bash
gcc calculadora.c -o calculadora.exe -luser32 -lgdi32 -lm
```


##  Recursos Útiles

- [Windows API Programming](https://docs.microsoft.com/en-us/windows/win32/api/)
- [Manejo de Ventanas y Controles](https://docs.microsoft.com/en-us/windows/win32/controls/)
- [Funciones Matemáticas en C](https://www.cplusplus.com/reference/cmath/)
- [Precisión de Punto Flotante](https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html)
- [Diseño de Interfaces](https://docs.microsoft.com/en-us/windows/win32/uxguide/guidelines)

##  Desafíos Bonus (Opcional)

### Nivel Experto:
- **Historial**: Mantener registro de cálculos anteriores
- **Temas**: Modo claro/oscuro
- **Teclado**: Soporte para entrada por teclado
- **Copiar/Pegar**: Integración con clipboard
- **Modo científico/básico**: Toggle entre interfaces
- **Funciones avanzadas**: sinh, cosh, tanh, log₂
- **Conversiones**: Decimal ↔ Binario ↔ Hexadecimal
- **Gráficos**: Plot de funciones simples

---

**Buena suerte creando tu calculadora científica** 
