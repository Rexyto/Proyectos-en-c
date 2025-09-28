<<<<<<< HEAD
# Intérprete y Conversor Brainfuck

Este proyecto contiene dos herramientas para trabajar con el lenguaje de programación esotérico **Brainfuck**:

1. **brainfuck.c**: Un intérprete completo de Brainfuck
2. **to_bf.c**: Un conversor que transforma archivos binarios a código Brainfuck

## ¿Qué es Brainfuck?

Brainfuck es un lenguaje de programación esotérico minimalista creado en 1993 por Urban Müller. Utiliza solo 8 comandos simples para manipular una cinta de memoria:

- `>`: Mueve el puntero hacia la derecha
- `<`: Mueve el puntero hacia la izquierda  
- `+`: Incrementa el valor en la celda actual
- `-`: Decrementa el valor en la celda actual
- `.`: Imprime el carácter ASCII de la celda actual
- `,`: Lee un carácter y lo almacena en la celda actual
- `[`: Si la celda actual es 0, salta al comando después del `]` correspondiente
- `]`: Si la celda actual no es 0, regresa al comando después del `[` correspondiente

## Compilación

Para compilar ambos programas, usa `gcc`:

```bash
# Compilar el intérprete
gcc -o brainfuck brainfuck.c

# Compilar el conversor
gcc -o to_bf to_bf.c
```

O compila ambos a la vez:

```bash
gcc -o brainfuck brainfuck.c && gcc -o to_bf to_bf.c
```

## Uso

### Intérprete Brainfuck (`brainfuck`)

Ejecuta programas escritos en Brainfuck:

```bash
./brainfuck programa.bf
```

**Ejemplo:**
```bash
# Crear un programa simple que imprima "Hello"
echo "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+." > hello.bf
./brainfuck hello.bf
```

### Conversor a Brainfuck (`to_bf`)

Convierte cualquier archivo binario a código Brainfuck que, cuando se ejecute, reproduce el contenido original:

```bash
./to_bf archivo_entrada archivo_salida.bf
```

**Ejemplos:**
```bash
# Convertir un archivo de texto
echo "Hola mundo!" > texto.txt
./to_bf texto.txt texto.bf

# Ejecutar el código generado
./brainfuck texto.bf
# Output: Hola mundo!

# Convertir una imagen pequeña
./to_bf imagen.jpg imagen.bf
./brainfuck imagen.bf > imagen_copia.jpg
```

## Características

### Intérprete Brainfuck
- **Cinta de memoria**: 30,000 celdas de 8 bits cada una
- **Soporte completo**: Implementa todos los 8 comandos de Brainfuck
- **Bucles anidados**: Maneja correctamente bucles `[` y `]` anidados
- **Entrada/Salida**: Soporte para lectura de teclado y escritura a consola

### Conversor to_bf
- **Optimización**: Genera código eficiente calculando diferencias entre bytes consecutivos
- **Compatibilidad**: Funciona con cualquier tipo de archivo (texto, imágenes, binarios)
- **Simplicidad**: Algoritmo directo que minimiza el código Brainfuck generado

## Limitaciones

- **Memoria finita**: La cinta tiene 30,000 celdas (puede modificarse cambiando `TAPE_SIZE`)
- **Sin verificación de límites**: No hay protección contra desbordamiento de puntero
- **Archivos grandes**: El conversor puede generar código muy largo para archivos grandes
- **Codificación**: Los archivos se procesan como bytes, sin consideraciones de codificación de texto

## Ejemplos de Programas Brainfuck

### Hola Mundo
```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.
```

### Eco (repite la entrada)
```brainfuck
,[.,]
```

### Suma dos números de un dígito
```brainfuck
,>,<[>+<-]>.
```

## Compilación Avanzada

Para optimizar el rendimiento:

```bash
gcc -O2 -o brainfuck brainfuck.c
gcc -O2 -o to_bf to_bf.c
```

Para debugging:

```bash
gcc -g -Wall -o brainfuck brainfuck.c
gcc -g -Wall -o to_bf to_bf.c
```
=======
# Intérprete y Conversor Brainfuck

Este proyecto contiene dos herramientas para trabajar con el lenguaje de programación esotérico **Brainfuck**:

1. **brainfuck.c**: Un intérprete completo de Brainfuck
2. **to_bf.c**: Un conversor que transforma archivos binarios a código Brainfuck

## ¿Qué es Brainfuck?

Brainfuck es un lenguaje de programación esotérico minimalista creado en 1993 por Urban Müller. Utiliza solo 8 comandos simples para manipular una cinta de memoria:

- `>`: Mueve el puntero hacia la derecha
- `<`: Mueve el puntero hacia la izquierda  
- `+`: Incrementa el valor en la celda actual
- `-`: Decrementa el valor en la celda actual
- `.`: Imprime el carácter ASCII de la celda actual
- `,`: Lee un carácter y lo almacena en la celda actual
- `[`: Si la celda actual es 0, salta al comando después del `]` correspondiente
- `]`: Si la celda actual no es 0, regresa al comando después del `[` correspondiente

## Compilación

Para compilar ambos programas, usa `gcc`:

```bash
# Compilar el intérprete
gcc -o brainfuck brainfuck.c

# Compilar el conversor
gcc -o to_bf to_bf.c
```

O compila ambos a la vez:

```bash
gcc -o brainfuck brainfuck.c && gcc -o to_bf to_bf.c
```

## Uso

### Intérprete Brainfuck (`brainfuck`)

Ejecuta programas escritos en Brainfuck:

```bash
./brainfuck programa.bf
```

**Ejemplo:**
```bash
# Crear un programa simple que imprima "Hello"
echo "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+." > hello.bf
./brainfuck hello.bf
```

### Conversor a Brainfuck (`to_bf`)

Convierte cualquier archivo binario a código Brainfuck que, cuando se ejecute, reproduce el contenido original:

```bash
./to_bf archivo_entrada archivo_salida.bf
```

**Ejemplos:**
```bash
# Convertir un archivo de texto
echo "Hola mundo!" > texto.txt
./to_bf texto.txt texto.bf

# Ejecutar el código generado
./brainfuck texto.bf
# Output: Hola mundo!

# Convertir una imagen pequeña
./to_bf imagen.jpg imagen.bf
./brainfuck imagen.bf > imagen_copia.jpg
```

## Características

### Intérprete Brainfuck
- **Cinta de memoria**: 30,000 celdas de 8 bits cada una
- **Soporte completo**: Implementa todos los 8 comandos de Brainfuck
- **Bucles anidados**: Maneja correctamente bucles `[` y `]` anidados
- **Entrada/Salida**: Soporte para lectura de teclado y escritura a consola

### Conversor to_bf
- **Optimización**: Genera código eficiente calculando diferencias entre bytes consecutivos
- **Compatibilidad**: Funciona con cualquier tipo de archivo (texto, imágenes, binarios)
- **Simplicidad**: Algoritmo directo que minimiza el código Brainfuck generado

## Limitaciones

- **Memoria finita**: La cinta tiene 30,000 celdas (puede modificarse cambiando `TAPE_SIZE`)
- **Sin verificación de límites**: No hay protección contra desbordamiento de puntero
- **Archivos grandes**: El conversor puede generar código muy largo para archivos grandes
- **Codificación**: Los archivos se procesan como bytes, sin consideraciones de codificación de texto

## Ejemplos de Programas Brainfuck

### Hola Mundo
```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.
```

### Eco (repite la entrada)
```brainfuck
,[.,]
```

### Suma dos números de un dígito
```brainfuck
,>,<[>+<-]>.
```

## Compilación Avanzada

Para optimizar el rendimiento:

```bash
gcc -O2 -o brainfuck brainfuck.c
gcc -O2 -o to_bf to_bf.c
```

Para debugging:

```bash
gcc -g -Wall -o brainfuck brainfuck.c
gcc -g -Wall -o to_bf to_bf.c
```
>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
