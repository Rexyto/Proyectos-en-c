<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estructura para organizar factores de conversion
typedef struct {
    char nombre[20];
    double factor;
} Unidad;

// Prototipos de funciones
void mostrarMenuPrincipal();
void mostrarMenuLongitud();
void mostrarMenuPeso();
void mostrarMenuTemperatura();
void mostrarMenuVolumen();
void convertirLongitud();
void convertirPeso();
void convertirTemperatura();
void convertirVolumen();
double leerNumero(const char* mensaje);
int leerOpcion(int min, int max);
void limpiarBuffer();
void limpiarPantalla();
void pausar();

int main() {
    int opcion;
    
    // Configurar locale para caracteres especiales
    setlocale(LC_ALL, "");
    
    printf("Bienvenido al Conversor de Unidades!\n");
    
    do {
        mostrarMenuPrincipal();
        opcion = leerOpcion(1, 5);
        
        switch(opcion) {
            case 1:
                convertirLongitud();
                break;
            case 2:
                convertirPeso();
                break;
            case 3:
                convertirTemperatura();
                break;
            case 4:
                convertirVolumen();
                break;
            case 5:
                printf("\nGracias por usar el Conversor de Unidades!\n");
                break;
        }
        
        if(opcion != 5) {
            pausar();
            limpiarPantalla();
        }
        
    } while(opcion != 5);
    
    return 0;
}

void mostrarMenuPrincipal() {
    printf("\n=====================================\n");
    printf("         CONVERSOR DE UNIDADES\n");
    printf("=====================================\n\n");
    printf("1. Longitud\n");
    printf("2. Peso\n");
    printf("3. Temperatura\n");
    printf("4. Volumen\n");
    printf("5. Salir\n\n");
    printf("Seleccione una opcion (1-5): ");
}

void mostrarMenuLongitud() {
    printf("\n=== CONVERSION DE LONGITUD ===\n");
    printf("1. Metros\n");
    printf("2. Kilometros\n");
    printf("3. Millas\n");
    printf("4. Pies\n");
}

void mostrarMenuPeso() {
    printf("\n=== CONVERSION DE PESO ===\n");
    printf("1. Kilogramos\n");
    printf("2. Libras\n");
    printf("3. Onzas\n");
}

void mostrarMenuTemperatura() {
    printf("\n=== CONVERSION DE TEMPERATURA ===\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
}

void mostrarMenuVolumen() {
    printf("\n=== CONVERSION DE VOLUMEN ===\n");
    printf("1. Litros\n");
    printf("2. Mililitros\n");
    printf("3. Galones\n");
}

void convertirLongitud() {
    // Factores de conversion a metros (unidad base)
    Unidad unidades[] = {
        {"Metros", 1.0},
        {"Kilometros", 1000.0},
        {"Millas", 1609.34},
        {"Pies", 0.3048}
    };
    
    int origen, destino;
    double valor, resultado;
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuLongitud();
    printf("Opcion: ");
    origen = leerOpcion(1, 4) - 1;
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuLongitud();
    printf("Opcion: ");
    destino = leerOpcion(1, 4) - 1;
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    if(valor < 0) {
        printf("Error: No se permiten valores negativos para longitud.\n");
        return;
    }
    
    // Convertir a metros primero, luego a la unidad destino
    resultado = (valor * unidades[origen].factor) / unidades[destino].factor;
    
    printf("\n--- RESULTADO ---\n");
    printf("%.0f %s = %.0f %s\n", 
           valor, unidades[origen].nombre, resultado, unidades[destino].nombre);
}

void convertirPeso() {
    // Factores de conversion a gramos (unidad base)
    Unidad unidades[] = {
        {"Kilogramos", 1000.0},
        {"Libras", 453.592},
        {"Onzas", 28.3495}
    };
    
    int origen, destino;
    double valor, resultado;
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuPeso();
    printf("Opcion: ");
    origen = leerOpcion(1, 3) - 1;
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuPeso();
    printf("Opcion: ");
    destino = leerOpcion(1, 3) - 1;
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    if(valor < 0) {
        printf("Error: No se permiten valores negativos para peso.\n");
        return;
    }
    
    // Convertir a gramos primero, luego a la unidad destino
    resultado = (valor * unidades[origen].factor) / unidades[destino].factor;
    
    printf("\n--- RESULTADO ---\n");
    printf("%.0f %s = %.0f %s\n", 
           valor, unidades[origen].nombre, resultado, unidades[destino].nombre);
}

void convertirTemperatura() {
    int origen, destino;
    double valor, resultado;
    char unidades[][15] = {"Celsius", "Fahrenheit", "Kelvin"};
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuTemperatura();
    printf("Opcion: ");
    origen = leerOpcion(1, 3);
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuTemperatura();
    printf("Opcion: ");
    destino = leerOpcion(1, 3);
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    // Conversiones de temperatura
    if(origen == destino) {
        resultado = valor;
    }
    else if(origen == 1 && destino == 2) { // Celsius a Fahrenheit
        resultado = (valor * 9.0/5.0) + 32;
    }
    else if(origen == 1 && destino == 3) { // Celsius a Kelvin
        if(valor < -273.15) {
            printf("Error: Temperatura por debajo del cero absoluto (-273.15C).\n");
            return;
        }
        resultado = valor + 273.15;
    }
    else if(origen == 2 && destino == 1) { // Fahrenheit a Celsius
        resultado = (valor - 32) * 5.0/9.0;
        if(resultado < -273.15) {
            printf("Error: Temperatura por debajo del cero absoluto.\n");
            return;
        }
    }
    else if(origen == 2 && destino == 3) { // Fahrenheit a Kelvin
        resultado = (valor - 32) * 5.0/9.0 + 273.15;
        if(resultado < 0) {
            printf("Error: Temperatura por debajo del cero absoluto.\n");
            return;
        }
    }
    else if(origen == 3 && destino == 1) { // Kelvin a Celsius
        if(valor < 0) {
            printf("Error: Los valores en Kelvin no pueden ser negativos.\n");
            return;
        }
        resultado = valor - 273.15;
    }
    else if(origen == 3 && destino == 2) { // Kelvin a Fahrenheit
        if(valor < 0) {
            printf("Error: Los valores en Kelvin no pueden ser negativos.\n");
            return;
        }
        resultado = (valor - 273.15) * 9.0/5.0 + 32;
    }
    
    printf("\n--- RESULTADO ---\n");
    printf("%.2f %s = %.2f %s\n", 
           valor, unidades[origen-1], resultado, unidades[destino-1]);
}

void convertirVolumen() {
    // Factores de conversion a litros (unidad base)
    Unidad unidades[] = {
        {"Litros", 1.0},
        {"Mililitros", 0.001},
        {"Galones", 3.78541}
    };
    
    int origen, destino;
    double valor, resultado;
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuVolumen();
    printf("Opcion: ");
    origen = leerOpcion(1, 3) - 1;
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuVolumen();
    printf("Opcion: ");
    destino = leerOpcion(1, 3) - 1;
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    if(valor < 0) {
        printf("Error: No se permiten valores negativos para volumen.\n");
        return;
    }
    
    // Convertir a litros primero, luego a la unidad destino
    resultado = (valor * unidades[origen].factor) / unidades[destino].factor;
    
    printf("\n--- RESULTADO ---\n");
    printf("%.0f %s = %.0f %s\n", 
           valor, unidades[origen].nombre, resultado, unidades[destino].nombre);
}

double leerNumero(const char* mensaje) {
    double numero;
    
    while(1) {
        printf("%s", mensaje);
        
        if(scanf("%lf", &numero) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            limpiarBuffer();
            continue;
        }
        
        limpiarBuffer();
        break;
    }
    
    return numero;
}

int leerOpcion(int min, int max) {
    int opcion;
    
    while(1) {
        if(scanf("%d", &opcion) != 1) {
            printf("Error: Seleccione una opcion valida (%d-%d): ", min, max);
            limpiarBuffer();
            continue;
        }
        
        limpiarBuffer();
        
        if(opcion >= min && opcion <= max) {
            break;
        }
        
        printf("Error: Seleccione una opcion valida (%d-%d): ", min, max);
    }
    
    return opcion;
}

void limpiarBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void limpiarPantalla() {
    // Funciona tanto en Windows como en sistemas Unix
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPresione Enter para continuar...");
    getchar();
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estructura para organizar factores de conversion
typedef struct {
    char nombre[20];
    double factor;
} Unidad;

// Prototipos de funciones
void mostrarMenuPrincipal();
void mostrarMenuLongitud();
void mostrarMenuPeso();
void mostrarMenuTemperatura();
void mostrarMenuVolumen();
void convertirLongitud();
void convertirPeso();
void convertirTemperatura();
void convertirVolumen();
double leerNumero(const char* mensaje);
int leerOpcion(int min, int max);
void limpiarBuffer();
void limpiarPantalla();
void pausar();

int main() {
    int opcion;
    
    // Configurar locale para caracteres especiales
    setlocale(LC_ALL, "");
    
    printf("Bienvenido al Conversor de Unidades!\n");
    
    do {
        mostrarMenuPrincipal();
        opcion = leerOpcion(1, 5);
        
        switch(opcion) {
            case 1:
                convertirLongitud();
                break;
            case 2:
                convertirPeso();
                break;
            case 3:
                convertirTemperatura();
                break;
            case 4:
                convertirVolumen();
                break;
            case 5:
                printf("\nGracias por usar el Conversor de Unidades!\n");
                break;
        }
        
        if(opcion != 5) {
            pausar();
            limpiarPantalla();
        }
        
    } while(opcion != 5);
    
    return 0;
}

void mostrarMenuPrincipal() {
    printf("\n=====================================\n");
    printf("         CONVERSOR DE UNIDADES\n");
    printf("=====================================\n\n");
    printf("1. Longitud\n");
    printf("2. Peso\n");
    printf("3. Temperatura\n");
    printf("4. Volumen\n");
    printf("5. Salir\n\n");
    printf("Seleccione una opcion (1-5): ");
}

void mostrarMenuLongitud() {
    printf("\n=== CONVERSION DE LONGITUD ===\n");
    printf("1. Metros\n");
    printf("2. Kilometros\n");
    printf("3. Millas\n");
    printf("4. Pies\n");
}

void mostrarMenuPeso() {
    printf("\n=== CONVERSION DE PESO ===\n");
    printf("1. Kilogramos\n");
    printf("2. Libras\n");
    printf("3. Onzas\n");
}

void mostrarMenuTemperatura() {
    printf("\n=== CONVERSION DE TEMPERATURA ===\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
}

void mostrarMenuVolumen() {
    printf("\n=== CONVERSION DE VOLUMEN ===\n");
    printf("1. Litros\n");
    printf("2. Mililitros\n");
    printf("3. Galones\n");
}

void convertirLongitud() {
    // Factores de conversion a metros (unidad base)
    Unidad unidades[] = {
        {"Metros", 1.0},
        {"Kilometros", 1000.0},
        {"Millas", 1609.34},
        {"Pies", 0.3048}
    };
    
    int origen, destino;
    double valor, resultado;
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuLongitud();
    printf("Opcion: ");
    origen = leerOpcion(1, 4) - 1;
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuLongitud();
    printf("Opcion: ");
    destino = leerOpcion(1, 4) - 1;
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    if(valor < 0) {
        printf("Error: No se permiten valores negativos para longitud.\n");
        return;
    }
    
    // Convertir a metros primero, luego a la unidad destino
    resultado = (valor * unidades[origen].factor) / unidades[destino].factor;
    
    printf("\n--- RESULTADO ---\n");
    printf("%.0f %s = %.0f %s\n", 
           valor, unidades[origen].nombre, resultado, unidades[destino].nombre);
}

void convertirPeso() {
    // Factores de conversion a gramos (unidad base)
    Unidad unidades[] = {
        {"Kilogramos", 1000.0},
        {"Libras", 453.592},
        {"Onzas", 28.3495}
    };
    
    int origen, destino;
    double valor, resultado;
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuPeso();
    printf("Opcion: ");
    origen = leerOpcion(1, 3) - 1;
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuPeso();
    printf("Opcion: ");
    destino = leerOpcion(1, 3) - 1;
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    if(valor < 0) {
        printf("Error: No se permiten valores negativos para peso.\n");
        return;
    }
    
    // Convertir a gramos primero, luego a la unidad destino
    resultado = (valor * unidades[origen].factor) / unidades[destino].factor;
    
    printf("\n--- RESULTADO ---\n");
    printf("%.0f %s = %.0f %s\n", 
           valor, unidades[origen].nombre, resultado, unidades[destino].nombre);
}

void convertirTemperatura() {
    int origen, destino;
    double valor, resultado;
    char unidades[][15] = {"Celsius", "Fahrenheit", "Kelvin"};
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuTemperatura();
    printf("Opcion: ");
    origen = leerOpcion(1, 3);
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuTemperatura();
    printf("Opcion: ");
    destino = leerOpcion(1, 3);
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    // Conversiones de temperatura
    if(origen == destino) {
        resultado = valor;
    }
    else if(origen == 1 && destino == 2) { // Celsius a Fahrenheit
        resultado = (valor * 9.0/5.0) + 32;
    }
    else if(origen == 1 && destino == 3) { // Celsius a Kelvin
        if(valor < -273.15) {
            printf("Error: Temperatura por debajo del cero absoluto (-273.15C).\n");
            return;
        }
        resultado = valor + 273.15;
    }
    else if(origen == 2 && destino == 1) { // Fahrenheit a Celsius
        resultado = (valor - 32) * 5.0/9.0;
        if(resultado < -273.15) {
            printf("Error: Temperatura por debajo del cero absoluto.\n");
            return;
        }
    }
    else if(origen == 2 && destino == 3) { // Fahrenheit a Kelvin
        resultado = (valor - 32) * 5.0/9.0 + 273.15;
        if(resultado < 0) {
            printf("Error: Temperatura por debajo del cero absoluto.\n");
            return;
        }
    }
    else if(origen == 3 && destino == 1) { // Kelvin a Celsius
        if(valor < 0) {
            printf("Error: Los valores en Kelvin no pueden ser negativos.\n");
            return;
        }
        resultado = valor - 273.15;
    }
    else if(origen == 3 && destino == 2) { // Kelvin a Fahrenheit
        if(valor < 0) {
            printf("Error: Los valores en Kelvin no pueden ser negativos.\n");
            return;
        }
        resultado = (valor - 273.15) * 9.0/5.0 + 32;
    }
    
    printf("\n--- RESULTADO ---\n");
    printf("%.2f %s = %.2f %s\n", 
           valor, unidades[origen-1], resultado, unidades[destino-1]);
}

void convertirVolumen() {
    // Factores de conversion a litros (unidad base)
    Unidad unidades[] = {
        {"Litros", 1.0},
        {"Mililitros", 0.001},
        {"Galones", 3.78541}
    };
    
    int origen, destino;
    double valor, resultado;
    
    printf("\nSeleccione la unidad de origen:");
    mostrarMenuVolumen();
    printf("Opcion: ");
    origen = leerOpcion(1, 3) - 1;
    
    printf("\nSeleccione la unidad de destino:");
    mostrarMenuVolumen();
    printf("Opcion: ");
    destino = leerOpcion(1, 3) - 1;
    
    valor = leerNumero("\nIngrese el valor a convertir: ");
    
    if(valor < 0) {
        printf("Error: No se permiten valores negativos para volumen.\n");
        return;
    }
    
    // Convertir a litros primero, luego a la unidad destino
    resultado = (valor * unidades[origen].factor) / unidades[destino].factor;
    
    printf("\n--- RESULTADO ---\n");
    printf("%.0f %s = %.0f %s\n", 
           valor, unidades[origen].nombre, resultado, unidades[destino].nombre);
}

double leerNumero(const char* mensaje) {
    double numero;
    
    while(1) {
        printf("%s", mensaje);
        
        if(scanf("%lf", &numero) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            limpiarBuffer();
            continue;
        }
        
        limpiarBuffer();
        break;
    }
    
    return numero;
}

int leerOpcion(int min, int max) {
    int opcion;
    
    while(1) {
        if(scanf("%d", &opcion) != 1) {
            printf("Error: Seleccione una opcion valida (%d-%d): ", min, max);
            limpiarBuffer();
            continue;
        }
        
        limpiarBuffer();
        
        if(opcion >= min && opcion <= max) {
            break;
        }
        
        printf("Error: Seleccione una opcion valida (%d-%d): ", min, max);
    }
    
    return opcion;
}

void limpiarBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void limpiarPantalla() {
    // Funciona tanto en Windows como en sistemas Unix
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPresione Enter para continuar...");
    getchar();
>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
}