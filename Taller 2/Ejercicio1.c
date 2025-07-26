#include <stdio.h>
#include <math.h>

// Prototipos de funciones
int raicesReales(double a, double b, double c);
void calcularRaices(double a, double b, double c, FILE *archivoSalida);

int main() {
    FILE *archivoEntrada1, *archivoEntrada2, *archivoSalida1, *archivoSalida2;
    char caracter;
    double a, b, c;
    int opcion;
    
    printf("Seleccione la opcion (1 o 2): ");
    scanf("%d", &opcion);
    
    switch(opcion) {
        case 1: {
            // Opción 1: Conversión de caracteres
            archivoEntrada1 = fopen("01-entrada-1.txt", "r");
            archivoSalida1 = fopen("01-salida.txt", "w");
            
            if (archivoEntrada1 == NULL || archivoSalida1 == NULL) {
                printf("Error al abrir los archivos.\n");
                return 1;
            }
            
            fscanf(archivoEntrada1, " %c", &caracter);
            
            // Convertir a mayúscula sin usar funciones de cadenas
            if (caracter >= 'a' && caracter <= 'z') {
                caracter = caracter - 32;
            }
            
            fprintf(archivoSalida1, "%c", caracter);
            
            fclose(archivoEntrada1);
            fclose(archivoSalida1);
            printf("Conversion completada. Resultado en 01-salida.txt\n");
            break;
        }
        
        case 2: {
            // Opción 2: Cálculo de raíces
            archivoEntrada2 = fopen("02-entrada-2.txt", "r");
            archivoSalida2 = fopen("02-salida.txt", "w");
            
            if (archivoEntrada2 == NULL || archivoSalida2 == NULL) {
                printf("Error al abrir los archivos.\n");
                return 1;
            }
            
            // Leer todos los conjuntos de coeficientes del archivo
            while (fscanf(archivoEntrada2, "%lf %lf %lf", &a, &b, &c) == 3) {
                calcularRaices(a, b, c, archivoSalida2);
                fprintf(archivoSalida2, " ");
            }
            
            fclose(archivoEntrada2);
            fclose(archivoSalida2);
            printf("Calculo de raices completado. Resultados en 01-salida.txt\n");
            break;
        }
        
        default:
            printf("Opcion no valida. Solo 1 o 2.\n");
            return 1;
    }
    
    return 0;
}

// Función para determinar el tipo de raíces
int raicesReales(double a, double b, double c) {
    double discriminante = b * b - 4 * a * c;
    
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
    int tipo = raicesReales(a, b, c);
    double discriminante = b * b - 4 * a * c;
    
    if (tipo == 1) {
        double x1 = (-b + sqrt(discriminante)) / (2 * a);
        double x2 = (-b - sqrt(discriminante)) / (2 * a);
        fprintf(archivoSalida, "El Discriminante es positivo con dos (2) soluciones reales distintas. Raices x1= %.1f, x2=%.1f", x1, x2);
    } else if (tipo == -1) {
        fprintf(archivoSalida, "El Discriminante es negativo, con dos (2) soluciones complejas distintas y ninguna solucion real");
    } else {
        double x = -b / (2 * a);
        fprintf(archivoSalida, "El discriminante es cero con 1 raiz real de multiplicidad, Raiz: %.1f", x);
    }
}