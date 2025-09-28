#  Reto: Servidor HTTP

**Dificultad**: ⭐⭐⭐⭐

**Conceptos**: Redes, Protocolos HTTP, Programación de sistemas, Multithreading, Gestión de archivos

##  Descripción del Reto

Tu misión es crear un **servidor HTTP completo y robusto** utilizando C puro y la API de Windows. Este proyecto te enseñará programación de redes, protocolos HTTP, manejo concurrente de conexiones, y arquitectura de servidores web modernos.

### ¿Qué incluye un Servidor HTTP Profesional?

Un servidor HTTP moderno debe manejar:
```
| Categoría           |                Funciones                     |
|---------------------|----------------------------------------------|
| Protocolo HTTP      | GET, POST, PUT, DELETE, HEAD, OPTIONS        |
| Respuestas          | 200, 201, 404, 405, 500, Headers completos   |
| Tipos de archivo    | HTML, CSS, JS, JSON, XML, Imágenes, Videos   |
| Seguridad           | Validación de rutas, Headers de seguridad    |
| Rendimiento         | Multithreading, Keep-alive, Compresión       |
| Características     | Logs, Virtual hosts, CGI básico, WebSockets  |
```

##  Tareas del Proyecto

### Parte 1: Servidor HTTP Básico Mejorado 
Mejora tu servidor actual con funcionalidades HTTP esenciales.

**Características requeridas:**
- **Métodos HTTP múltiples**: GET, POST, PUT, DELETE, HEAD, OPTIONS
- **Headers completos**: Date, Server, Content-Length, Connection
- **Códigos de estado**: 200, 201, 400, 404, 405, 500, 501
- **Tipos MIME extendidos**: JSON, XML, PDF, Videos (MP4, AVI)
- **Validación de rutas**: Prevenir ataques de directorio traversal
- **Logging detallado**: Registro de todas las peticiones y errores

**Estructura base requerida:**
```c
// Estructura para manejar diferentes métodos HTTP
typedef struct {
    char method[16];
    char path[512];
    char version[16];
    char headers[2048];
    char body[4096];
    size_t body_length;
} HTTPRequest;

typedef struct {
    int status_code;
    char status_text[64];
    char headers[2048];
    char* body;
    size_t body_length;
} HTTPResponse;

// Funciones requeridas
HTTPRequest* parse_http_request(const char* raw_request);
HTTPResponse* create_http_response(int status_code, const char* content_type, 
                                  const char* body, size_t body_length);
void send_http_response(SOCKET client_socket, HTTPResponse* response);
void log_request(const char* client_ip, const char* method, 
                const char* path, int status_code);
```

### Parte 2: Funcionalidades Avanzadas 
Implementa características de servidor web profesional.

**API RESTful básica:**
- **GET /api/status**: Información del servidor (uptime, requests, memoria)
- **GET /api/files**: Lista de archivos en el directorio web
- **POST /api/upload**: Subida de archivos al servidor
- **DELETE /api/files/{filename}**: Eliminación de archivos
- **GET /api/logs**: Últimas 100 líneas de log

**Manejo de formularios:**
- **Content-Type**: application/x-www-form-urlencoded
- **Multipart/form-data**: Para subida de archivos
- **JSON parsing**: Manejo de datos JSON en POST/PUT

**Headers de seguridad:**
```c
// Headers de seguridad requeridos
"X-Content-Type-Options: nosniff\r\n"
"X-Frame-Options: DENY\r\n"
"X-XSS-Protection: 1; mode=block\r\n"
"Strict-Transport-Security: max-age=31536000\r\n"
"Content-Security-Policy: default-src 'self'\r\n"
```

### Parte 3: Concurrencia y Rendimiento 
Implementa manejo concurrent de conexiones y optimizaciones.

**Multithreading:**
```c
// Pool de threads para manejar múltiples conexiones
#define MAX_THREADS 50
#define MAX_QUEUE 100

typedef struct {
    SOCKET client_socket;
    struct sockaddr_in client_addr;
} ConnectionInfo;

typedef struct {
    ConnectionInfo queue[MAX_QUEUE];
    int front, rear, count;
    CRITICAL_SECTION mutex;
    CONDITION_VARIABLE condition;
} ThreadPool;

DWORD WINAPI worker_thread(LPVOID lpParam);
void thread_pool_init(ThreadPool* pool);
void thread_pool_add_task(ThreadPool* pool, SOCKET client_socket, 
                         struct sockaddr_in client_addr);
```

**Características de rendimiento:**
- **Connection pooling**: Reutilización de conexiones
- **Keep-alive**: Conexiones persistentes HTTP/1.1
- **Compresión gzip**: Para archivos de texto (HTML, CSS, JS, JSON)
- **Caché de archivos**: Mantener archivos frecuentes en memoria
- **Estadísticas**: Contador de requests, bytes transferidos, errores

### Parte 4: Interfaz Web de Administración 
Crear un panel de control web para monitorear el servidor.

**Dashboard HTML/CSS/JS:**
```
┌─────────────────────────────────────────────────────────┐
│     Servidor HTTP - Panel de Control                    │
├─────────────────────────────────────────────────────────┤
│     Estadísticas:                                       │
│     • Requests totales: 1,234                           │
│     • Conexiones activas: 5                             │
│     • Uptime: 2h 30m                                    │
│     • Memoria usada: 15.2 MB                            │
├─────────────────────────────────────────────────────────┤
│     Gestión de archivos:                                │
│     [Upload File] [List Files] [View Logs]              │
├─────────────────────────────────────────────────────────┤
│   Configuración:                                        │
│     Puerto: [6969] [Apply]                              │
│     Max Connections: [50] [Apply]                       │
│     Log Level: [INFO ▼] [Apply]                         │
└─────────────────────────────────────────────────────────┘
```

**Funcionalidades del panel:**
- **Estadísticas en tiempo real**: Actualización automática cada 5 segundos
- **Gestión de archivos**: Upload, delete, rename archivos
- **Visualización de logs**: Scroll infinito con filtros
- **Configuración dinámica**: Cambiar settings sin reiniciar
- **Gráficos**: Charts de requests por hora, tipos de archivo servidos

##  Especificaciones Técnicas

### Validación y Seguridad

**Validaciones requeridas:**
- **Path traversal**: Bloquear `../`, `..\\`, rutas absolutas
- **Tamaño de request**: Límite de 10MB para uploads
- **Extensiones permitidas**: Whitelist de tipos de archivo
- **Rate limiting**: Máximo 100 requests por IP por minuto
- **Input sanitization**: Validar todos los inputs del usuario

**Manejo de errores robusto:**
```c
// Códigos de error específicos
#define HTTP_400_BAD_REQUEST     "HTTP/1.1 400 Bad Request\r\n"
#define HTTP_403_FORBIDDEN       "HTTP/1.1 403 Forbidden\r\n"
#define HTTP_404_NOT_FOUND       "HTTP/1.1 404 Not Found\r\n"
#define HTTP_405_METHOD_NOT_ALLOWED "HTTP/1.1 405 Method Not Allowed\r\n"
#define HTTP_413_PAYLOAD_TOO_LARGE  "HTTP/1.1 413 Payload Too Large\r\n"
#define HTTP_429_TOO_MANY_REQUESTS  "HTTP/1.1 429 Too Many Requests\r\n"
#define HTTP_500_INTERNAL_ERROR     "HTTP/1.1 500 Internal Server Error\r\n"
```

### Sistema de Logging

**Formato de log requerido:**
```
[2024-09-27 15:30:45] INFO 192.168.1.100:54321 GET /index.html 200 2.1KB 15ms
[2024-09-27 15:30:46] ERROR 192.168.1.101:54322 POST /api/upload 413 0B 5ms
[2024-09-27 15:30:47] WARN 192.168.1.102:54323 GET /admin 403 0.5KB 8ms
```

**Niveles de log:**
- **ERROR**: Errores del servidor, conexiones fallidas
- **WARN**: Rate limiting, accesos denegados
- **INFO**: Requests normales, startup/shutdown
- **DEBUG**: Detalles de parsing, thread pool status



##  Recursos Útiles

- [HTTP/1.1 RFC 2616](https://tools.ietf.org/html/rfc2616)
- [Windows Socket Programming](https://docs.microsoft.com/en-us/windows/win32/winsock/)
- [Multithreading en Windows](https://docs.microsoft.com/en-us/windows/win32/procthread/)
- [MIME Types Lista Completa](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types)
- [HTTP Security Headers](https://owasp.org/www-project-secure-headers/)

- [RESTful API Design](https://restfulapi.net/)
