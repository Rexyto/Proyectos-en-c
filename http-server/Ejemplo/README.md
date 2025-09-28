<<<<<<< HEAD
#  Servidor HTTP en C

Un servidor HTTP ligero y funcional desarrollado en C para sistemas Windows, ideal para servir archivos estáticos de forma local durante el desarrollo.

##  Características

-  Servidor HTTP/1.1 completo
-  Ligero y rápido
-  Servicio de archivos estáticos
-  Detección automática de tipos MIME
-  Interfaz gráfica con MessageBox
-  Optimizado para Windows
-  Soporte para múltiples tipos de archivo (HTML, CSS, JS, imágenes)

##  Requisitos

- **Sistema Operativo:** Windows 7 o superior
- **Compilador:** GCC (MinGW recomendado)
- **Bibliotecas:** Winsock2 (incluida en Windows)


##  Uso

### Inicio rápido

1. **Ejecutar el servidor:**
```bash
make run
```
   o directamente:
```bash
./servidor.exe
```

2. **Acceder al servidor:**
   - Abre tu navegador web
   - Visita: `http://localhost:6969`

### Estructura de archivos

```
proyecto/
├── Makefile          # Archivo de compilación
├── server.c          # Código fuente del servidor
├── servidor.exe      # Ejecutable compilado
├── index.html        # Página de bienvenida
└── src/              # Directorio de archivos web
    └── index.html    # Tu contenido web aquí
```

##  Configuración

### Puerto del servidor
El servidor está configurado para ejecutarse en el puerto `6969`. Para cambiarlo:

1. Abre `server.c`
2. Modifica la línea:
```c
#define PORT 6969
```
3. Recompila el proyecto:
```bash
make clean && make
```

### Directorio de archivos
Por defecto, el servidor sirve archivos desde el directorio `src/`. Los archivos deben colocarse en:
- `src/index.html` - Página principal
- `src/styles.css` - Hojas de estilo
- `src/script.js` - Scripts JavaScript
- `src/images/` - Imágenes y recursos
```
##  Tipos de archivo soportados

| Extensión |        Tipo MIME         |
|---------- |--------------------------|
| `.html`   | `text/html`              |
| `.css`    | `text/css`               |
| `.js`     | `application/javascript` |
| `.png`    | `image/png`              |
| `.jpg`    | `image/jpeg`             |
| `.gif`    | `image/gif`              |
| Otros     | `text/plain`             |
```
##  Comandos Make

```bash
make          # Compila el proyecto
make run      # Compila y ejecuta el servidor
make clean    # Elimina archivos compilados
make setup    # Crea la estructura de directorios
```

##  Ejemplo de uso

1. **Coloca tu `index.html` en la carpeta `src/`**
2. **Ejecuta el servidor:**
```bash
make run
```
3. **Aparecerá una ventana de diálogo confirmando que el servidor está funcionando**
4. **Abre tu navegador en `http://localhost:6969`**
5. **¡Tu sitio web estará disponible!**

##  Solución de problemas

### Error: "Puerto en uso"
- Asegúrate de que no hay otra aplicación usando el puerto 6969
- Cambia el puerto en `server.c` si es necesario
- Termina cualquier instancia previa del servidor

### Error de compilación
- Verifica que GCC esté instalado y en el PATH
- En Windows, instala MinGW-w64
- Asegúrate de que las bibliotecas Winsock2 estén disponibles

### Archivos no se cargan
- Verifica que los archivos estén en el directorio `src/`
- Comprueba que los nombres de archivo no tengan espacios o caracteres especiales
- Revisa la consola del servidor para mensajes de error

##  Estructura del código

### `server.c`
- **`get_mime_type()`** - Determina el tipo MIME por extensión
- **`get_file_extension()`** - Extrae la extensión del archivo
- **`send_file()`** - Lee y envía archivos al cliente
- **`handle_request()`** - Procesa peticiones HTTP
- **`main()`** - Función principal y loop del servidor

### Características técnicas
- Manejo de errores robusto
- Interfaz gráfica con MessageBox
- Soporte para archivos binarios
- Headers HTTP correctos
- Gestión de memoria eficiente

##  Estados del servidor

- **🟢 OPERATIVO** - Servidor funcionando correctamente
- **🟡 INICIANDO** - Configurando socket y puerto
- **🔴 ERROR** - Problema de configuración o puerto ocupado

##  Consejos de desarrollo

1. **Desarrollo web local:** Perfecto para probar sitios estáticos
2. **Prototipado rápido:** Inicia un servidor en segundos
3. **Aprendizaje:** Excelente para entender HTTP y redes
4. **Testing:** Prueba tu HTML/CSS/JS localmente

##  Seguridad

 **Advertencia:** Este servidor está diseñado solo para desarrollo local. NO lo uses en producción sin implementar medidas de seguridad adicionales:

- No hay autenticación
- No hay cifrado HTTPS
- Limitaciones básicas de acceso a archivos
- Solo para uso en red local confiable

=======
#  Servidor HTTP en C

Un servidor HTTP ligero y funcional desarrollado en C para sistemas Windows, ideal para servir archivos estáticos de forma local durante el desarrollo.

##  Características

-  Servidor HTTP/1.1 completo
-  Ligero y rápido
-  Servicio de archivos estáticos
-  Detección automática de tipos MIME
-  Interfaz gráfica con MessageBox
-  Optimizado para Windows
-  Soporte para múltiples tipos de archivo (HTML, CSS, JS, imágenes)

##  Requisitos

- **Sistema Operativo:** Windows 7 o superior
- **Compilador:** GCC (MinGW recomendado)
- **Bibliotecas:** Winsock2 (incluida en Windows)


##  Uso

### Inicio rápido

1. **Ejecutar el servidor:**
```bash
make run
```
   o directamente:
```bash
./servidor.exe
```

2. **Acceder al servidor:**
   - Abre tu navegador web
   - Visita: `http://localhost:6969`

### Estructura de archivos

```
proyecto/
├── Makefile          # Archivo de compilación
├── server.c          # Código fuente del servidor
├── servidor.exe      # Ejecutable compilado
├── index.html        # Página de bienvenida
└── src/              # Directorio de archivos web
    └── index.html    # Tu contenido web aquí
```

##  Configuración

### Puerto del servidor
El servidor está configurado para ejecutarse en el puerto `6969`. Para cambiarlo:

1. Abre `server.c`
2. Modifica la línea:
```c
#define PORT 6969
```
3. Recompila el proyecto:
```bash
make clean && make
```

### Directorio de archivos
Por defecto, el servidor sirve archivos desde el directorio `src/`. Los archivos deben colocarse en:
- `src/index.html` - Página principal
- `src/styles.css` - Hojas de estilo
- `src/script.js` - Scripts JavaScript
- `src/images/` - Imágenes y recursos
```
##  Tipos de archivo soportados

| Extensión |        Tipo MIME         |
|---------- |--------------------------|
| `.html`   | `text/html`              |
| `.css`    | `text/css`               |
| `.js`     | `application/javascript` |
| `.png`    | `image/png`              |
| `.jpg`    | `image/jpeg`             |
| `.gif`    | `image/gif`              |
| Otros     | `text/plain`             |
```
##  Comandos Make

```bash
make          # Compila el proyecto
make run      # Compila y ejecuta el servidor
make clean    # Elimina archivos compilados
make setup    # Crea la estructura de directorios
```

##  Ejemplo de uso

1. **Coloca tu `index.html` en la carpeta `src/`**
2. **Ejecuta el servidor:**
```bash
make run
```
3. **Aparecerá una ventana de diálogo confirmando que el servidor está funcionando**
4. **Abre tu navegador en `http://localhost:6969`**
5. **¡Tu sitio web estará disponible!**

##  Solución de problemas

### Error: "Puerto en uso"
- Asegúrate de que no hay otra aplicación usando el puerto 6969
- Cambia el puerto en `server.c` si es necesario
- Termina cualquier instancia previa del servidor

### Error de compilación
- Verifica que GCC esté instalado y en el PATH
- En Windows, instala MinGW-w64
- Asegúrate de que las bibliotecas Winsock2 estén disponibles

### Archivos no se cargan
- Verifica que los archivos estén en el directorio `src/`
- Comprueba que los nombres de archivo no tengan espacios o caracteres especiales
- Revisa la consola del servidor para mensajes de error

##  Estructura del código

### `server.c`
- **`get_mime_type()`** - Determina el tipo MIME por extensión
- **`get_file_extension()`** - Extrae la extensión del archivo
- **`send_file()`** - Lee y envía archivos al cliente
- **`handle_request()`** - Procesa peticiones HTTP
- **`main()`** - Función principal y loop del servidor

### Características técnicas
- Manejo de errores robusto
- Interfaz gráfica con MessageBox
- Soporte para archivos binarios
- Headers HTTP correctos
- Gestión de memoria eficiente

##  Estados del servidor

- **🟢 OPERATIVO** - Servidor funcionando correctamente
- **🟡 INICIANDO** - Configurando socket y puerto
- **🔴 ERROR** - Problema de configuración o puerto ocupado

##  Consejos de desarrollo

1. **Desarrollo web local:** Perfecto para probar sitios estáticos
2. **Prototipado rápido:** Inicia un servidor en segundos
3. **Aprendizaje:** Excelente para entender HTTP y redes
4. **Testing:** Prueba tu HTML/CSS/JS localmente

##  Seguridad

 **Advertencia:** Este servidor está diseñado solo para desarrollo local. NO lo uses en producción sin implementar medidas de seguridad adicionales:

- No hay autenticación
- No hay cifrado HTTPS
- Limitaciones básicas de acceso a archivos
- Solo para uso en red local confiable

>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
**¡Disfruta desarrollando con tu servidor HTTP en C! 🚀**