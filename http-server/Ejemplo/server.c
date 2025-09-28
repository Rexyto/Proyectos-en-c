#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "user32.lib")

#define PORT 6969
#define BUFFER_SIZE 1024
#define MAX_FILE_PATH 256

// Función para obtener el tipo MIME basado en la extensión del archivo
const char* get_mime_type(const char* file_ext) {
    if (strcmp(file_ext, "html") == 0) return "text/html";
    if (strcmp(file_ext, "css") == 0) return "text/css";
    if (strcmp(file_ext, "js") == 0) return "application/javascript";
    if (strcmp(file_ext, "png") == 0) return "image/png";
    if (strcmp(file_ext, "jpg") == 0) return "image/jpeg";
    if (strcmp(file_ext, "gif") == 0) return "image/gif";
    return "text/plain";
}

// Función para obtener la extensión del archivo
char* get_file_extension(const char* filename) {
    char* dot = strrchr(filename, '.');
    if (!dot || dot == filename) return "";
    return dot + 1;
}

// Función para leer archivo y enviarlo como respuesta
void send_file(SOCKET client_socket, const char* filepath) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        // Enviar respuesta 404
        const char* not_found = "HTTP/1.1 404 Not Found\r\n"
                               "Content-Type: text/html\r\n"
                               "Content-Length: 47\r\n"
                               "\r\n"
                               "<html><body><h1>404 Not Found</h1></body></html>";
        send(client_socket, not_found, strlen(not_found), 0);
        return;
    }

    // Obtener tamaño del archivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Obtener tipo MIME
    const char* mime_type = get_mime_type(get_file_extension(filepath));

    // Enviar headers HTTP
    char header[BUFFER_SIZE];
    snprintf(header, sizeof(header),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %ld\r\n"
             "\r\n", mime_type, file_size);
    
    send(client_socket, header, strlen(header), 0);

    // Enviar contenido del archivo
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(client_socket, buffer, (int)bytes_read, 0);
    }

    fclose(file);
}

// Función para procesar las peticiones HTTP
void handle_request(SOCKET client_socket) {
    char buffer[BUFFER_SIZE];
    char method[16], path[MAX_FILE_PATH], version[16];
    
    // Leer la petición
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        closesocket(client_socket);
        return;
    }
    
    buffer[bytes_received] = '\0';
    
    // Parsear la primera línea de la petición HTTP
    sscanf(buffer, "%15s %255s %15s", method, path, version);
    
    printf("Petición: %s %s %s\n", method, path, version);
    
    // Si la ruta es "/", servir index.html
    if (strcmp(path, "/") == 0) {
        strcpy(path, "/index.html");
    }
    
    // Construir la ruta completa del archivo
    char filepath[MAX_FILE_PATH];
    snprintf(filepath, sizeof(filepath), "src%s", path);
    
    // Enviar el archivo
    send_file(client_socket, filepath);
    
    // Cerrar conexión
    closesocket(client_socket);
}

int main() {
    WSADATA wsaData;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);
    char message[256];
    
    // Mostrar ventana de inicio
    snprintf(message, sizeof(message), "Iniciando Servidor HTTP...\n\nPuerto: %d\nURL: http://localhost:%d", PORT, PORT);
    MessageBoxA(NULL, message, "Servidor HTTP - Iniciando", MB_OK | MB_ICONINFORMATION);
    
    // Inicializar Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        MessageBoxA(NULL, "Error inicializando Winsock", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    // Crear socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        snprintf(message, sizeof(message), "Error creando socket: %d", WSAGetLastError());
        MessageBoxA(NULL, message, "Error", MB_OK | MB_ICONERROR);
        WSACleanup();
        return 1;
    }
    
    // Configurar opción para reutilizar la dirección
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) == SOCKET_ERROR) {
        snprintf(message, sizeof(message), "Error configurando socket: %d", WSAGetLastError());
        MessageBoxA(NULL, message, "Error", MB_OK | MB_ICONERROR);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    
    // Configurar dirección del servidor
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind del socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        snprintf(message, sizeof(message), "Error en bind: %d\nPuerto %d puede estar en uso.", WSAGetLastError(), PORT);
        MessageBoxA(NULL, message, "Error", MB_OK | MB_ICONERROR);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    
    // Escuchar conexiones
    if (listen(server_socket, 10) == SOCKET_ERROR) {
        snprintf(message, sizeof(message), "Error en listen: %d", WSAGetLastError());
        MessageBoxA(NULL, message, "Error", MB_OK | MB_ICONERROR);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    
    // Mostrar ventana de éxito
    snprintf(message, sizeof(message), 
             "¡Servidor HTTP Operativo!\n\n"
             "Puerto: %d\n"
             "URL Local: http://localhost:%d\n"
             "URL Red: http://127.0.0.1:%d\n\n"
             "Directorio: ./src/\n\n"
             "Presiona OK para continuar.\n"
             "Para detener el servidor, cierra esta ventana de consola o presiona Ctrl+C.",
             PORT, PORT, PORT);
    MessageBoxA(NULL, message, "🌐 Servidor HTTP - ¡OPERATIVO! 🌐", MB_OK | MB_ICONINFORMATION);
    
    printf("=== SERVIDOR HTTP OPERATIVO ===\n");
    printf("Puerto: %d\n", PORT);
    printf("URL: http://localhost:%d\n", PORT);
    printf("Directorio: ./src/\n");
    printf("Presiona Ctrl+C para detener\n");
    printf("==============================\n\n");
    
    // Loop principal del servidor
    while (1) {
        // Aceptar conexión
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket == INVALID_SOCKET) {
            printf("Error aceptando conexión: %d\n", WSAGetLastError());
            continue;
        }
        
        // Procesar petición
        handle_request(client_socket);
    }
    
    closesocket(server_socket);
    WSACleanup();
    return 0;
}