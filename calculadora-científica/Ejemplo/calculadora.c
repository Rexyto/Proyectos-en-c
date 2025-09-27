#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID_DISPLAY 1001
#define ID_CLEAR 1002
#define ID_BACKSPACE 1003
#define ID_EQUALS 1004

// Números
#define ID_0 1010
#define ID_1 1011
#define ID_2 1012
#define ID_3 1013
#define ID_4 1014
#define ID_5 1015
#define ID_6 1016
#define ID_7 1017
#define ID_8 1018
#define ID_9 1019

// Operaciones básicas
#define ID_PLUS 1020
#define ID_MINUS 1021
#define ID_MULTIPLY 1022
#define ID_DIVIDE 1023
#define ID_DECIMAL 1024

// Funciones científicas
#define ID_SIN 1030
#define ID_COS 1031
#define ID_TAN 1032
#define ID_LOG 1036
#define ID_LN 1037
#define ID_SQRT 1038
#define ID_POWER 1039
#define ID_EXP 1040
#define ID_FACTORIAL 1041

// Constantes
#define ID_PI 1050
#define ID_E 1051

// Variables globales
HWND hDisplay;
char displayText[256] = "0";
double operand1 = 0;
double operand2 = 0;
char operator = 0;
int waitingForOperand = 1;

const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;

// Prototipos de funciones
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void CreateButtons(HWND hwnd);
void UpdateDisplay();
void AppendDigit(char digit);
void SetOperator(char op);
void Calculate();
void ClearAll();
double Factorial(double n);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "CalculadoraCientifica";
    
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    
    RegisterClass(&wc);
    
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Calculadora Cientifica",
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
        CW_USEDEFAULT, CW_USEDEFAULT, 450, 520,
        NULL, NULL, hInstance, NULL
    );
    
    if (hwnd == NULL) return 0;
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            CreateButtons(hwnd);
            break;
            
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                // Números
                case ID_0: case ID_1: case ID_2: case ID_3: case ID_4:
                case ID_5: case ID_6: case ID_7: case ID_8: case ID_9:
                    AppendDigit('0' + (LOWORD(wParam) - ID_0));
                    break;
                    
                case ID_DECIMAL:
                    if (strchr(displayText, '.') == NULL) {
                        AppendDigit('.');
                    }
                    break;
                    
                // Operaciones básicas
                case ID_PLUS:
                    SetOperator('+');
                    break;
                case ID_MINUS:
                    SetOperator('-');
                    break;
                case ID_MULTIPLY:
                    SetOperator('*');
                    break;
                case ID_DIVIDE:
                    SetOperator('/');
                    break;
                case ID_POWER:
                    SetOperator('^');
                    break;
                    
                case ID_EQUALS:
                    Calculate();
                    break;
                    
                case ID_CLEAR:
                    ClearAll();
                    break;
                    
                case ID_BACKSPACE:
                    if (strlen(displayText) > 1) {
                        displayText[strlen(displayText) - 1] = '\0';
                    } else {
                        strcpy(displayText, "0");
                    }
                    UpdateDisplay();
                    break;
                    
                // Funciones científicas
                case ID_SIN: {
                    double val = atof(displayText) * PI / 180.0; // Convierte a radianes
                    double result = sin(val);
                    sprintf(displayText, "%.10g", result);
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_COS: {
                    double val = atof(displayText) * PI / 180.0;
                    double result = cos(val);
                    sprintf(displayText, "%.10g", result);
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_TAN: {
                    double val = atof(displayText) * PI / 180.0;
                    double result = tan(val);
                    sprintf(displayText, "%.10g", result);
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_LOG: {
                    double val = atof(displayText);
                    if (val > 0) {
                        double result = log10(val);
                        sprintf(displayText, "%.10g", result);
                    } else {
                        strcpy(displayText, "Error");
                    }
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_LN: {
                    double val = atof(displayText);
                    if (val > 0) {
                        double result = log(val);
                        sprintf(displayText, "%.10g", result);
                    } else {
                        strcpy(displayText, "Error");
                    }
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_SQRT: {
                    double val = atof(displayText);
                    if (val >= 0) {
                        double result = sqrt(val);
                        sprintf(displayText, "%.10g", result);
                    } else {
                        strcpy(displayText, "Error");
                    }
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_EXP: {
                    double val = atof(displayText);
                    double result = exp(val);
                    sprintf(displayText, "%.10g", result);
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                case ID_FACTORIAL: {
                    double val = atof(displayText);
                    if (val >= 0 && val == floor(val) && val <= 170) {
                        double result = Factorial(val);
                        sprintf(displayText, "%.10g", result);
                    } else {
                        strcpy(displayText, "Error");
                    }
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                }
                
                // Constantes
                case ID_PI:
                    sprintf(displayText, "%.10g", PI);
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
                    
                case ID_E:
                    sprintf(displayText, "%.10g", E);
                    UpdateDisplay();
                    waitingForOperand = 1;
                    break;
            }
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void CreateButtons(HWND hwnd) {
    // Display
    hDisplay = CreateWindow(
        "EDIT", displayText,
        WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY | WS_BORDER,
        10, 10, 420, 50,
        hwnd, (HMENU)ID_DISPLAY, NULL, NULL
    );
    
    // Fuente para el display
    HFONT hFont = CreateFont(28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_DONTCARE, "Arial");
    SendMessage(hDisplay, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Fila 1: Funciones científicas principales
    CreateWindow("BUTTON", "sin", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 10, 70, 60, 40, hwnd, (HMENU)ID_SIN, NULL, NULL);
    CreateWindow("BUTTON", "cos", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 80, 70, 60, 40, hwnd, (HMENU)ID_COS, NULL, NULL);
    CreateWindow("BUTTON", "tan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 150, 70, 60, 40, hwnd, (HMENU)ID_TAN, NULL, NULL);
    CreateWindow("BUTTON", "ln", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 220, 70, 60, 40, hwnd, (HMENU)ID_LN, NULL, NULL);
    CreateWindow("BUTTON", "log", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 290, 70, 60, 40, hwnd, (HMENU)ID_LOG, NULL, NULL);
    CreateWindow("BUTTON", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 360, 70, 70, 40, hwnd, (HMENU)ID_CLEAR, NULL, NULL);
                 
    // Fila 2: Más funciones y constantes
    CreateWindow("BUTTON", "sqrt", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 10, 120, 60, 40, hwnd, (HMENU)ID_SQRT, NULL, NULL);
    CreateWindow("BUTTON", "x^y", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 80, 120, 60, 40, hwnd, (HMENU)ID_POWER, NULL, NULL);
    CreateWindow("BUTTON", "e^x", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 150, 120, 60, 40, hwnd, (HMENU)ID_EXP, NULL, NULL);
    CreateWindow("BUTTON", "x!", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 220, 120, 60, 40, hwnd, (HMENU)ID_FACTORIAL, NULL, NULL);
    CreateWindow("BUTTON", "pi", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 290, 120, 60, 40, hwnd, (HMENU)ID_PI, NULL, NULL);
    CreateWindow("BUTTON", "DEL", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 360, 120, 70, 40, hwnd, (HMENU)ID_BACKSPACE, NULL, NULL);
    
    // Fila 3: Números 7, 8, 9, operaciones
    CreateWindow("BUTTON", "7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 10, 170, 80, 50, hwnd, (HMENU)ID_7, NULL, NULL);
    CreateWindow("BUTTON", "8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 100, 170, 80, 50, hwnd, (HMENU)ID_8, NULL, NULL);
    CreateWindow("BUTTON", "9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 190, 170, 80, 50, hwnd, (HMENU)ID_9, NULL, NULL);
    CreateWindow("BUTTON", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 280, 170, 70, 50, hwnd, (HMENU)ID_DIVIDE, NULL, NULL);
    CreateWindow("BUTTON", "e", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 360, 170, 70, 50, hwnd, (HMENU)ID_E, NULL, NULL);
                 
    // Fila 4: Números 4, 5, 6, multiplicación
    CreateWindow("BUTTON", "4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 10, 230, 80, 50, hwnd, (HMENU)ID_4, NULL, NULL);
    CreateWindow("BUTTON", "5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 100, 230, 80, 50, hwnd, (HMENU)ID_5, NULL, NULL);
    CreateWindow("BUTTON", "6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 190, 230, 80, 50, hwnd, (HMENU)ID_6, NULL, NULL);
    CreateWindow("BUTTON", "*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 280, 230, 70, 50, hwnd, (HMENU)ID_MULTIPLY, NULL, NULL);
                 
    // Fila 5: Números 1, 2, 3, resta
    CreateWindow("BUTTON", "1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 10, 290, 80, 50, hwnd, (HMENU)ID_1, NULL, NULL);
    CreateWindow("BUTTON", "2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 100, 290, 80, 50, hwnd, (HMENU)ID_2, NULL, NULL);
    CreateWindow("BUTTON", "3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 190, 290, 80, 50, hwnd, (HMENU)ID_3, NULL, NULL);
    CreateWindow("BUTTON", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 280, 290, 70, 50, hwnd, (HMENU)ID_MINUS, NULL, NULL);
                 
    // Fila 6: 0, punto, suma
    CreateWindow("BUTTON", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 10, 350, 170, 50, hwnd, (HMENU)ID_0, NULL, NULL);
    CreateWindow("BUTTON", ".", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 190, 350, 80, 50, hwnd, (HMENU)ID_DECIMAL, NULL, NULL);
    CreateWindow("BUTTON", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 280, 350, 70, 50, hwnd, (HMENU)ID_PLUS, NULL, NULL);
    CreateWindow("BUTTON", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                 360, 230, 70, 170, hwnd, (HMENU)ID_EQUALS, NULL, NULL);
}

void UpdateDisplay() {
    SetWindowText(hDisplay, displayText);
}

void AppendDigit(char digit) {
    if (waitingForOperand) {
        strcpy(displayText, "");
        waitingForOperand = 0;
    }
    
    if (strcmp(displayText, "0") == 0 && digit != '.') {
        displayText[0] = digit;
        displayText[1] = '\0';
    } else {
        char temp[2] = {digit, '\0'};
        strcat(displayText, temp);
    }
    
    UpdateDisplay();
}

void SetOperator(char op) {
    if (!waitingForOperand) {
        if (operator != 0) {
            Calculate();
        }
        operand1 = atof(displayText);
    }
    
    operator = op;
    waitingForOperand = 1;
}

void Calculate() {
    if (operator == 0 || waitingForOperand) return;
    
    operand2 = atof(displayText);
    double result = 0;
    
    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                strcpy(displayText, "Error");
                UpdateDisplay();
                operator = 0;
                waitingForOperand = 1;
                return;
            }
            break;
        case '^':
            result = pow(operand1, operand2);
            break;
    }
    
    sprintf(displayText, "%.10g", result);
    UpdateDisplay();
    
    operand1 = result;
    operator = 0;
    waitingForOperand = 1;
}

void ClearAll() {
    strcpy(displayText, "0");
    operand1 = 0;
    operand2 = 0;
    operator = 0;
    waitingForOperand = 1;
    UpdateDisplay();
}

double Factorial(double n) {
    if (n <= 1) return 1;
    double result = 1;
    for (int i = 2; i <= (int)n; i++) {
        result *= i;
    }
    return result;
}