#  Reto: Intérprete y Conversor Brainfuck

**Dificultad**: ⭐⭐⭐⭐

**Conceptos**: Intérpretes, Parsing, Conversión de archivos, Optimización, Manejo de memoria

##  Descripción del Reto

Tu misión es crear un **conjunto de herramientas completas para Brainfuck** que incluya tanto un intérprete robusto como un conversor de archivos. Este proyecto te enseñará análisis léxico, ejecución de código interpretado, y manipulación de archivos binarios.

### ¿Qué es Brainfuck?

Brainfuck es un lenguaje minimalista con solo 8 comandos que opera sobre una cinta de memoria:
```
| Comando |               Descripción                     |
|---------|-----------------------------------------------|
|    `>`  | Mover el puntero a la derecha                 |
|    `<`  | Mover el puntero a la izquierda               |
|    `+`  | Incrementar el valor en la celda actual       |
|    `-`  | Decrementar el valor en la celda actual       |
|    `.`  | Imprimir el carácter ASCII de la celda actual |
|    `,`  | Leer un carácter del input y almacenarlo      |
|    `[`  | Saltar después del `]` si la celda es 0       |
|    `]`  | Volver al `[` si la celda no es 0             |
````

##  Tareas del Proyecto

### Parte 1: Intérprete Brainfuck 
Crea un programa `brainfuck.c` que ejecute código Brainfuck directamente.

**Características requeridas:**
- **Cinta de memoria**: Mínimo 30,000 celdas (recomendado 65,536)
- **Validación de sintaxis**: Verificar corchetes balanceados
- **Protección de memoria**: Evitar accesos fuera de límites
- **Manejo de archivos**: Leer programas desde archivos `.bf`
- **Filtrado**: Ignorar caracteres que no son comandos Brainfuck
- **Protección anti-bucles**: Límite de instrucciones ejecutadas

**Opciones de línea de comandos:**
```bash
./brainfuck [opciones] archivo.bf

Opciones:
  -v, --verbose    Mostrar información detallada de ejecución
  -h, --help       Mostrar ayuda
  -t, --text       Mostrar caracteres no imprimibles como códigos
```

**Ejemplo de uso:**
```bash
./brainfuck hola_mundo.bf
./brainfuck -v -t programa_complejo.bf
```

### Parte 2: Conversor a Brainfuck 
Crea un programa `to_bf.c` que convierta cualquier archivo a código Brainfuck.

**Funcionalidad:**
- **Conversión binaria**: Transformar cualquier archivo (texto, imagen, binario) a código Brainfuck
- **Optimización**: Calcular diferencias entre bytes consecutivos para reducir código
- **Eficiencia**: Usar técnicas como multiplicación para valores grandes
- **Archivos grandes**: Soporte para archivos de varios MB

**Opciones de línea de comandos:**
```bash
./to_bf [opciones] archivo_entrada archivo_salida.bf

Opciones:
  -v, --verbose    Mostrar información detallada y progreso
  -o, --optimize   Usar optimizaciones avanzadas
  -c, --comment    Añadir comentarios al código generado
  -h, --help       Mostrar esta ayuda
```

**Ejemplo de flujo completo:**
```bash
# Crear un archivo de prueba
echo "Hola mundo!" > mensaje.txt

# Convertir a Brainfuck
./to_bf -v -o mensaje.txt mensaje.bf

# Ejecutar el código generado
./brainfuck mensaje.bf
# Output: Hola mundo!
```

## Especificaciones Técnicas

### Intérprete (`brainfuck.c`)

**Estructura de datos:**
```c
#define TAPE_SIZE 65536
unsigned char tape[TAPE_SIZE] = {0};
unsigned char *ptr = tape;
```

**Características avanzadas:**
- **Contador de instrucciones**: Protección contra bucles infinitos (ej: 100M instrucciones)
- **Validación de límites**: Verificar `ptr` dentro de `[tape, tape + TAPE_SIZE)`
- **Manejo de EOF**: En `,` comando, EOF → celda = 0
- **Modo texto**: Mostrar caracteres no imprimibles como `[código]`
- **Información de debug**: Posición del puntero, instrucciones ejecutadas

### Conversor (`to_bf.c`)

**Algoritmo de optimización:**
```c
// Para cada byte del archivo:
int diff = current_byte - previous_byte;

// Generar código para alcanzar el valor
if (abs(diff) > 15) {
    // Usar multiplicación: factor1 * factor2
    // Ejemplo: para llegar a 72, usar 8*9
} else {
    // Usar suma/resta simple: +++++ o -----
}

// Imprimir el byte
fprintf(output, ".");
```

**Optimizaciones requeridas:**
- **Diferencias**: No partir de 0 cada vez, usar diferencia con byte anterior
- **Multiplicación**: Para valores grandes, usar loops de multiplicación
- **Factorización**: Encontrar factores óptimos para minimizar operaciones
- **Comentarios opcionales**: Documentar el código generado

##  Casos de Prueba

### Programas Brainfuck para el intérprete:

1. **Hola Mundo**
```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.
```

2. **Eco infinito**
```brainfuck
,[.,]
```

3. **Suma de dos dígitos**
```brainfuck
,>,<[>+<-]>.
```

### Archivos para el conversor:

1. **Archivo de texto simple**
```bash
echo "ABC" > test.txt
./to_bf test.txt test.bf
./brainfuck test.bf  # Debe imprimir: ABC
```

2. **Archivo con caracteres especiales**
```bash
printf "Hello\nWorld\x00\x01" > special.bin
./to_bf -c special.bin special.bf
./brainfuck special.bf > output.bin
diff special.bin output.bin  # Debe ser idéntico
```

##  Interfaz y Usabilidad

### Manejo de errores requerido:
- **Archivos no encontrados**
- **Memoria insuficiente**
- **Archivos demasiado grandes**
- **Sintaxis inválida** (corchetes no balanceados)
- **Desbordamiento de puntero**
- **Bucles infinitos**`

##  Recursos Útiles

- [Brainfuck en Wikipedia](https://en.wikipedia.org/wiki/Brainfuck)
- [Brainfuck Algorithms](http://brainfuck.org/)
- [Optimizaciones de Brainfuck](https://esolangs.org/wiki/Brainfuck_optimizations)
- [Manejo de archivos binarios en C](https://www.cprogramming.com/tutorial/cfileio.html)
