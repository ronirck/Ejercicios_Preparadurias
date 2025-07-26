#include <stdio.h>  // Incluir la biblioteca estándar de entrada/salida
#include <math.h>   // Incluir la biblioteca matemática para funciones como sqrt

// Prototipos de funciones
int raicesReales(double a, double b, double c); // Prototipo de la función que determina el tipo de raíces
void calcularRaices(double a, double b, double c, FILE *archivoSalida); // Prototipo de la función que calcula y muestra las raíces

int main() {
    // Declaración de punteros a archivos y variables
    FILE *archivoEntrada1, *archivoEntrada2, *archivoSalida1, *archivoSalida2;
    char caracter; // Variable para almacenar un carácter
    double a, b, c; // Variables para los coeficientes de la ecuación cuadrática
    int opcion; // Variable para almacenar la opción seleccionada por el usuario

    // Solicitar al usuario que seleccione una opción
    printf("Seleccione la opcion (1 o 2): ");
    scanf("%d", &opcion); // Leer la opción seleccionada

    // Estructura de control para manejar las diferentes opciones
    switch(opcion) {
        case 1: { // Opción 1: Conversión de caracteres
            archivoEntrada1 = fopen("01-entrada-1.txt", "r"); // Abrir el archivo de entrada para lectura
            archivoSalida1 = fopen("01-salida.txt", "w"); // Abrir el archivo de salida para escritura

            // Verificar si los archivos se abrieron correctamente
            if (archivoEntrada1 == NULL || archivoSalida1 == NULL) {
                printf("Error al abrir los archivos.\n"); // Mensaje de error
                return 1; // Salir del programa con error
            }

            fscanf(archivoEntrada1, " %c", &caracter); // Leer un carácter del archivo de entrada

            // Convertir a mayúscula sin usar funciones de cadenas
            if (caracter >= 'a' && caracter <= 'z') {
                caracter = caracter - 32; // Convertir a mayúscula restando 32
            }

            fprintf(archivoSalida1, "%c", caracter); // Escribir el carácter convertido en el archivo de salida

            fclose(archivoEntrada1); // Cerrar el archivo de entrada
            fclose(archivoSalida1); // Cerrar el archivo de salida
            printf("Conversion completada. Resultado en 01-salida.txt\n"); // Mensaje de éxito
            break; // Salir del case
        }

        case 2: { // Opción 2: Cálculo de raíces
            archivoEntrada2 = fopen("02-entrada-2.txt", "r"); // Abrir el archivo de entrada para lectura
            archivoSalida2 = fopen("02-salida.txt", "w"); // Abrir el archivo de salida para escritura

            // Verificar si los archivos se abrieron correctamente
            if (archivoEntrada2 == NULL || archivoSalida2 == NULL) {
                printf("Error al abrir los archivos.\n"); // Mensaje de error
                return 1; // Salir del programa con error
            }

            // Leer todos los conjuntos de coeficientes del archivo
            while (fscanf(archivoEntrada2, "%lf %lf %lf", &a, &b, &c) == 3) {
                calcularRaices(a, b, c, archivoSalida2); // Calcular las raíces y escribir en el archivo de salida
                fprintf(archivoSalida2, " "); // Agregar un espacio en el archivo de salida
            }

            fclose(archivoEntrada2); // Cerrar el archivo de entrada
            fclose(archivoSalida2); // Cerrar el archivo de salida
            printf("Calculo de raices completado. Resultados en 01-salida.txt\n"); // Mensaje de éxito
            break; // Salir del case
        }

        default: // Opción no válida
            printf("Opcion no valida. Solo 1 o 2.\n"); // Mensaje de error
            return 1; // Salir del programa con error
    }

    return 0; // Salir del programa con éxito
}

// Función para determinar el tipo de raíces
int raicesReales(double a, double b, double c) {
    double discriminante = b * b - 4 * a * c; // Calcular el discriminante

    // Determinar el tipo de raíces basado en el discriminante
    if (discriminante > 0) {
        return 1;  // Dos raíces reales distintas
    } else if (discriminante < 0) {
        return -1; // Dos raíces imaginarias
    } else {
        return 0;  // Una raíz real de multiplicidad 2
    }
}

// Función para calcular y mostrar las raíces
void calcularRaices(double a, double b, double c, FILE *archivoSalida) {
    int tipo = raicesReales(a, b, c); // Determinar el tipo de raíces
    double discriminante = b * b - 4 * a * c; // Calcular el discriminante

    // Calcular y mostrar las raíces según el tipo
    if (tipo == 1) {
        double x1 = (-b + sqrt(discriminante)) / (2 * a); // Calcular la primera raíz
        double x2 = (-b - sqrt(discriminante)) / (2 * a); // Calcular la segunda raíz
        fprintf(archivoSalida, "El Discriminante es positivo con dos (2) soluciones reales distintas. Raices x1= %.1f, x2=%.1f", x1, x2); // Escribir las raíces en el archivo
    } else if (tipo == -1) {
        fprintf(archivoSalida, "El Discriminante es negativo, con dos (2) soluciones complejas distintas y ninguna solucion real"); // Mensaje para raíces complejas
    } else {
        double x = -b / (2 * a); // Calcular la raíz única
        fprintf(archivoSalida, "El discriminante es cero con 1 raiz real de multiplicidad, Raiz: %.1f", x); // Escribir la raíz en el archivo
    }
}
