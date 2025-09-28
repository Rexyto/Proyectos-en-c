# Reto: Sistema de Conversión de Unidades Avanzado

**Dificultad**: ⭐⭐

**Conceptos**: Programación en C, Estructuras, Validación de entrada, Interfaz de usuario, Manejo de errores

## Descripción del Reto

Tu misión es crear un **sistema completo de conversión de unidades** que sea robusto, fácil de usar y extensible. Este proyecto te enseñará sobre estructuras de datos, validación de entrada, diseño de interfaces de consola y manejo de errores en C.

### ¿Qué hace un Conversor de Unidades?

Un conversor de unidades permite transformar valores entre diferentes sistemas de medida de forma precisa y confiable:
- **Longitud**: metros, kilómetros, millas, pies
- **Peso**: kilogramos, libras, onzas  
- **Temperatura**: Celsius, Fahrenheit, Kelvin
- **Volumen**: litros, mililitros, galones

##  Tareas del Proyecto

### Parte 1: Conversor Básico 
Crea un programa `conversor.c` con funcionalidad completa de conversión.

**Características requeridas:**
- **Menús interactivos**: Navegación clara por categorías
- **4 categorías**: Longitud, peso, temperatura y volumen
- **Validación robusta**: Manejo de entradas inválidas
- **Interfaz limpia**: Presentación profesional de resultados
- **Multiplataforma**: Funciona en Windows, Linux y macOS
- **Protecciones físicas**: Validar límites realistas (ej: no temperaturas bajo cero absoluto)

**Flujo del programa:**
```
1. Mostrar menú principal
2. Usuario selecciona categoría
3. Mostrar unidades disponibles  
4. Usuario selecciona unidad origen
5. Usuario selecciona unidad destino
6. Usuario ingresa valor
7. Mostrar resultado formateado
8. Opción de continuar o salir
```

### Parte 2: Extensiones Avanzadas 
Amplía el conversor con funcionalidades adicionales.

**Nuevas categorías:**
- **Área**: metros², kilómetros², acres, hectáreas
- **Velocidad**: m/s, km/h, mph, nudos
- **Energía**: julios, calorías, kWh, BTU
- **Presión**: pascales, atmósferas, mmHg, psi

**Funcionalidades adicionales:**
- **Historial**: Guardar últimas 10 conversiones
- **Modo batch**: Leer conversiones desde archivo
- **Precisión configurable**: Elegir número de decimales
- **Unidades favoritas**: Guardar combinaciones frecuentes

##  Especificaciones Técnicas

### Validaciones Requeridas

**Por categoría:**
- **Longitud/Peso/Volumen**: Solo valores positivos
- **Temperatura**: 
  - Celsius: ≥ -273.15°C
  - Kelvin: ≥ 0K
  - Fahrenheit: ≥ -459.67°F
- **Entrada numérica**: Rechazar texto, caracteres especiales
- **Opciones de menú**: Solo números en rango válido

**Manejo de errores:**
```c
if(valor < 0) {
    printf("Error: No se permiten valores negativos para %s.\n", categoria);
    return;
}

if(temperatura_celsius < -273.15) {
    printf("Error: Temperatura por debajo del cero absoluto (-273.15°C).\n");
    return;
}
```

##  Casos de Prueba

### Casos básicos:
1. **Conversión simple**
```
Entrada: 1 km → metros
Resultado: 1 Kilometros = 1000 Metros
```

2. **Conversión con decimales**
```
Entrada: 2.5 libras → kilogramos  
Resultado: 3 Libras = 1 Kilogramos
```

3. **Temperatura con validación**
```
Entrada: 100°C → Fahrenheit
Resultado: 100 Celsius = 212 Fahrenheit
```

### Casos de error:
1. **Valor negativo**
```
Entrada: -5 metros
Error: No se permiten valores negativos para longitud.
```

2. **Temperatura imposible**
```
Entrada: -300°C
Error: Temperatura por debajo del cero absoluto (-273.15°C).
```

3. **Entrada inválida**
```
Entrada: "abc" metros
Error: Por favor ingrese un numero valido.
```

## Interfaz y Experiencia de Usuario

### Diseño de menús:
```
=====================================
         CONVERSOR DE UNIDADES
=====================================

1. Longitud
2. Peso
3. Temperatura
4. Volumen
5. Salir

Seleccione una opcion (1-5): _
```

### Formato de resultados:
```
--- RESULTADO ---
5 Kilometros = 5000 Metros
``
Presione Enter para continuar...


### Características UX:
- **Limpieza automática**: Pantalla se limpia entre operaciones
- **Navegación clara**: Menús numerados intuitivos
- **Resultados destacados**: Separadores visuales
- **Confirmaciones**: Pausa para revisar resultados
- **Salida elegante**: Mensaje de despedida
```
## Compilación y Ejecución

### Requisitos:
- **Compilador**: GCC o compatible con C99
- **Sistemas**: Windows, Linux, macOS
- **Dependencias**: Solo bibliotecas estándar de C

### Comandos:
```bash
# Compilar
gcc -std=c99 -o conversor conversor.c

# Ejecutar
./conversor

# Windows
gcc -o conversor.exe conversor.c
conversor.exe
```

##  Recursos Útiles

- [Factores de conversión estándar](https://www.nist.gov/pml/weights-and-measures)
- [Manejo de archivos en C](https://www.cprogramming.com/tutorial/cfileio.html)
- [Validación de entrada robusta](https://stackoverflow.com/questions/4023895/how-to-read-a-line-from-the-console-in-c)
- [Interfaces de consola](https://en.wikipedia.org/wiki/Text-based_user_interface)