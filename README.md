<<<<<<< HEAD
#  Proyectos de Programación en C

Una colección de **desafíos prácticos** diseñados para poner a prueba y mejorar tus habilidades en C.

##  ¿Por qué estos proyectos?

El lenguaje C sigue siendo fundamental en:
- **Sistemas operativos** (Linux, Windows kernel)
- **Sistemas embebidos** (IoT, microcontroladores)
- **Compiladores e intérpretes** (GCC, Python CPython)
- **Bases de datos** (PostgreSQL, SQLite)
- **Juegos de alto rendimiento** (engines gráficos)

Estos proyectos te darán experiencia práctica en las áreas que más importan.

##  Filosofía de Aprendizaje

> **"No se aprende C leyendo sobre C, se aprende C escribiendo C"**

Cada proyecto está diseñado con:
-  **Objetivos claros** - Sabes exactamente qué vas a aprender
-  **Aplicación real** - Proyectos que podrías usar de verdad
-  **Código de referencia** - Mi implementación como guía
-  **Documentación detallada** - Para que entiendas cada decisión

##  Estructura de Cada Proyecto

```
nombre-del-reto/
├── Reto.md              #  La descripción completa del desafío
└── ejemplos/            #  Cómo yo lo hice
    ├── src/            
    │   ├── main.c
    │   ├── utils.c
    │   └── headers/
    └── Readme.md
```

###  Cómo usar cada proyecto:

1. **Lee `Reto.md`** - Entiende qué tienes que construir
2. **Intenta implementarlo** - Sin ver mi código primero
3. **Compara con `ejemplos/`** - Ve cómo lo resolví yo
4. **Mejora tu solución** - Incorpora técnicas que no conocías

##  Catálogo de Proyectos

###  Intérpretes y Compiladores
> *"La cuna de la programación actual"*

#### `brainfuck-interpreter` ⭐⭐⭐⭐
**Intérprete y conversor para el lenguaje esotérico Brainfuck**
-  **Conceptos**: Parsing, AST, ejecución interpretada  
-  **Aprenderás**: Cómo funcionan los intérpretes por dentro  


###  Utilidades
> *"Herramientas prácticas para el día a día"*

#### `calculadora` ⭐⭐
**Programa que realiza operaciones aritméticas básicas**  
-  **Conceptos**: GUI Programming, Windows API, Parsing matemático, Manejo de eventos  
-  **Aprenderás**: Cómo estructurar programas útiles y reutilizables  

#### `conversor-unidades` ⭐⭐
**Programa que convierte unidades de longitud, peso, temperatura y volumen**  
- **Conceptos**: Programación en C, Estructuras, Validación de entrada, Menús interactivos, Manejo de errores  
- **Aprenderás**: Cómo crear una herramienta útil de conversión de unidades, manejar entrada de usuario segura y organizar datos con estructuras.

###  Web
> *"La base de internet moderna"*

#### `http-server` ⭐⭐⭐⭐
**Servidor HTTP multithreaded en C con soporte para API RESTful**  
-  **Conceptos**: Redes, Protocolos HTTP, Programación de sistemas, Multithreading, Gestión de archivos  
-  **Aprenderás**: Cómo funcionan los servidores web por dentro y cómo manejar múltiples clientes concurrentes  

### Algoritmos y Estructuras de Datos
> *"Aprender jugando con los fundamentos de la computación"*

#### `sorting-visualizer` ⭐⭐⭐
**Visualizador interactivo de algoritmos de ordenamiento en C**  
- **Conceptos**: Algoritmos, Visualización de datos, Depuración paso a paso  
- **Aprenderás**: Cómo funcionan Bubble, Quick y Merge Sort y cómo se comportan en distintos tipos de datos

##  Herramientas Necesarias

### **Compilador y Build Tools**
```bash
# Ubuntu/Debian
sudo apt install gcc make gdb valgrind

# macOS
xcode-select --install
brew install valgrind

# Windows (WSL recomendado)
wsl --install
```

### **Librerías Útiles**
- **ncurses** - Interfaces de terminal
- **pthread** - Multithreading
- **math.h** - Matemáticas avanzadas
- **sys/socket.h** - Networking

### **Debugging y Profiling**
- **gdb** - Debugger principal
- **valgrind** - Memory leaks y profiling
- **strace** - System calls tracing
- **perf** - Performance profiling

##  Contribuir al Proyecto

¿Quieres aportar? ¡Excelente!

### **Ideas para contribuciones:**
-  **Nuevos proyectos** - Propón desafíos interesantes
-  **Mejoras de código** - Optimizaciones en mis ejemplos
-  **Documentación** - Explicaciones más claras
-  **Tests adicionales** - Más casos de prueba
-  **Variaciones** - Implementaciones alternativas

##  Tracking de Progreso

Usa este checklist para hacer seguimiento de tu progreso:

```markdown
## Mi Progreso en C

### Proyectos Completados 
- [ ] brainfuck-interpreter
- [ ] calculadora-científica
- [ ] http-server
- [ ] Visualizador-de-algoritmos
- [ ] Conversor-de-unidades

```

---

=======
#  Proyectos de Programación en C

Una colección de **desafíos prácticos** diseñados para poner a prueba y mejorar tus habilidades en C.

##  ¿Por qué estos proyectos?

El lenguaje C sigue siendo fundamental en:
- **Sistemas operativos** (Linux, Windows kernel)
- **Sistemas embebidos** (IoT, microcontroladores)
- **Compiladores e intérpretes** (GCC, Python CPython)
- **Bases de datos** (PostgreSQL, SQLite)
- **Juegos de alto rendimiento** (engines gráficos)

Estos proyectos te darán experiencia práctica en las áreas que más importan.

##  Filosofía de Aprendizaje

> **"No se aprende C leyendo sobre C, se aprende C escribiendo C"**

Cada proyecto está diseñado con:
-  **Objetivos claros** - Sabes exactamente qué vas a aprender
-  **Aplicación real** - Proyectos que podrías usar de verdad
-  **Código de referencia** - Mi implementación como guía
-  **Documentación detallada** - Para que entiendas cada decisión

##  Estructura de Cada Proyecto

```
nombre-del-reto/
├── Reto.md              #  La descripción completa del desafío
└── ejemplos/            #  Cómo yo lo hice
    ├── src/            
    │   ├── main.c
    │   ├── utils.c
    │   └── headers/
    └── Readme.md
```

###  Cómo usar cada proyecto:

1. **Lee `Reto.md`** - Entiende qué tienes que construir
2. **Intenta implementarlo** - Sin ver mi código primero
3. **Compara con `ejemplos/`** - Ve cómo lo resolví yo
4. **Mejora tu solución** - Incorpora técnicas que no conocías

##  Catálogo de Proyectos

###  Intérpretes y Compiladores
> *"La cuna de la programación actual"*

#### `brainfuck-interpreter` ⭐⭐⭐⭐
**Intérprete y conversor para el lenguaje esotérico Brainfuck**
-  **Conceptos**: Parsing, AST, ejecución interpretada  
-  **Aprenderás**: Cómo funcionan los intérpretes por dentro  


###  Utilidades
> *"Herramientas prácticas para el día a día"*

#### `calculadora` ⭐⭐
**Programa que realiza operaciones aritméticas básicas**  
-  **Conceptos**: GUI Programming, Windows API, Parsing matemático, Manejo de eventos  
-  **Aprenderás**: Cómo estructurar programas útiles y reutilizables  

#### `conversor-unidades` ⭐⭐
**Programa que convierte unidades de longitud, peso, temperatura y volumen**  
- **Conceptos**: Programación en C, Estructuras, Validación de entrada, Menús interactivos, Manejo de errores  
- **Aprenderás**: Cómo crear una herramienta útil de conversión de unidades, manejar entrada de usuario segura y organizar datos con estructuras.

###  Web
> *"La base de internet moderna"*

#### `http-server` ⭐⭐⭐⭐
**Servidor HTTP multithreaded en C con soporte para API RESTful**  
-  **Conceptos**: Redes, Protocolos HTTP, Programación de sistemas, Multithreading, Gestión de archivos  
-  **Aprenderás**: Cómo funcionan los servidores web por dentro y cómo manejar múltiples clientes concurrentes  

### Algoritmos y Estructuras de Datos
> *"Aprender jugando con los fundamentos de la computación"*

#### `sorting-visualizer` ⭐⭐⭐
**Visualizador interactivo de algoritmos de ordenamiento en C**  
- **Conceptos**: Algoritmos, Visualización de datos, Depuración paso a paso  
- **Aprenderás**: Cómo funcionan Bubble, Quick y Merge Sort y cómo se comportan en distintos tipos de datos

##  Herramientas Necesarias

### **Compilador y Build Tools**
```bash
# Ubuntu/Debian
sudo apt install gcc make gdb valgrind

# macOS
xcode-select --install
brew install valgrind

# Windows (WSL recomendado)
wsl --install
```

### **Librerías Útiles**
- **ncurses** - Interfaces de terminal
- **pthread** - Multithreading
- **math.h** - Matemáticas avanzadas
- **sys/socket.h** - Networking

### **Debugging y Profiling**
- **gdb** - Debugger principal
- **valgrind** - Memory leaks y profiling
- **strace** - System calls tracing
- **perf** - Performance profiling

##  Contribuir al Proyecto

¿Quieres aportar? ¡Excelente!

### **Ideas para contribuciones:**
-  **Nuevos proyectos** - Propón desafíos interesantes
-  **Mejoras de código** - Optimizaciones en mis ejemplos
-  **Documentación** - Explicaciones más claras
-  **Tests adicionales** - Más casos de prueba
-  **Variaciones** - Implementaciones alternativas

##  Tracking de Progreso

Usa este checklist para hacer seguimiento de tu progreso:

```markdown
## Mi Progreso en C

### Proyectos Completados 
- [ ] brainfuck-interpreter
- [ ] calculadora-científica
- [ ] http-server
- [ ] Visualizador-de-algoritmos
- [ ] Conversor-de-unidades

```

---

>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
> **"El mejor programador de C no es el que más sabe, sino el que nunca deja de practicar"**