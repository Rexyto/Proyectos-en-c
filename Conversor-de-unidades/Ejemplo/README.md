# Conversor de Unidades

Un programa completo en C para convertir entre diferentes unidades de medida de forma fácil e intuitiva.

##  Descripción

Este conversor de unidades permite realizar conversiones entre diferentes sistemas de medida para longitud, peso, temperatura y volumen. El programa cuenta con una interfaz de consola clara y menús interactivos que facilitan su uso.

## Características

- **4 categorías de conversión**: Longitud, Peso, Temperatura y Volumen
- **Interfaz intuitiva** con menús numerados
- **Validación de entrada** para evitar errores
- **Resultados limpios** sin decimales innecesarios
- **Manejo de errores** robusto
- **Multiplataforma** (Windows, Linux, macOS)

##  Unidades Soportadas

###  Longitud
- Metros
- Kilómetros
- Millas
- Pies

###  Peso
- Kilogramos
- Libras
- Onzas

###  Temperatura
- Celsius
- Fahrenheit
- Kelvin

###  Volumen
- Litros
- Mililitros
- Galones

##  Instalación y Compilación

### Requisitos
- Compilador GCC o cualquier compilador compatible con C99
- Sistema operativo: Windows, Linux o macOS

### Pasos de instalación

1. **Clona o descarga el repositorio**


2. **Compila el programa**
```bash
gcc -o conversor conversor.c
```

3. **Ejecuta el programa**
```bash
./conversor
```

En Windows:
```cmd
gcc -o conversor.exe conversor.c
conversor.exe
```

## 📖Uso

1. **Ejecuta el programa** y verás el menú principal
2. **Selecciona la categoría** de conversión (1-5)
3. **Elige la unidad de origen** del listado
4. **Elige la unidad de destino** del listado
5. **Ingresa el valor** a convertir
6. **Ve el resultado** de la conversión

### Ejemplo de uso:
```
=====================================
         CONVERSOR DE UNIDADES
=====================================

1. Longitud
2. Peso
3. Temperatura
4. Volumen
5. Salir

Seleccione una opcion (1-5): 1

=== CONVERSION DE LONGITUD ===
1. Metros
2. Kilometros
3. Millas
4. Pies
Opcion: 2

=== CONVERSION DE LONGITUD ===
1. Metros
2. Kilometros
3. Millas
4. Pies
Opcion: 1

Ingrese el valor a convertir: 1

--- RESULTADO ---
1 Kilometros = 1000 Metros
```

##  Características Técnicas

### Validaciones implementadas:
- **Valores negativos**: No se permiten para longitud, peso y volumen
- **Temperatura**: Validación del cero absoluto (-273.15°C, 0K)
- **Entrada inválida**: Manejo robusto de caracteres no numéricos
- **Rangos**: Validación de opciones de menú

### Precisión:
- **Longitud y volumen**: Resultados sin decimales para mayor claridad
- **Peso**: Resultados sin decimales 
- **Temperatura**: Resultados con 2 decimales para mayor precisión

##  Estructura del Código

```
conversor.c
├── main()                    # Función principal y bucle del programa
├── mostrarMenu*()           # Funciones para mostrar menús
├── convertir*()             # Funciones de conversión por categoría
├── leerNumero()             # Validación y lectura de números
├── leerOpcion()             # Validación y lectura de opciones
├── limpiarBuffer()          # Limpieza del buffer de entrada
├── limpiarPantalla()        # Limpieza multiplataforma de pantalla
└── pausar()                 # Pausa para continuar
```

##  Solución de Problemas

### Error de compilación
```bash
# Si tienes errores de compilación, prueba con:
gcc -std=c99 -o conversor conversor.c
```

### Caracteres extraños en pantalla
```bash
# En sistemas Linux/Mac, asegúrate de que tu terminal soporte UTF-8:
export LANG=es_ES.UTF-8
```

### El programa no limpia la pantalla
```bash
# En algunos sistemas, puedes necesitar instalar clear/cls:
# Linux: sudo apt install ncurses-bin
# Windows: El comando cls está incluido por defecto
```

##  Ejemplos de Conversiones
```
| Entrada   |  Resultado  |
|-----------|-------------|
| 1 km      | 1000 metros |
| 5 libras  | 2268 gramos |
| 100°C     | 212°F       |
| 2 galones | 8 litros    |
```
##  Notas del Desarrollador

- El programa utiliza factores de conversión estándar internacionales
- Para temperaturas, se implementan validaciones del cero absoluto
- La interfaz está optimizada para terminales estándar
- Compatible con compiladores modernos de C