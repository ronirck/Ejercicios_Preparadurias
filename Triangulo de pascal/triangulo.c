#include <stdio.h> // Incluir la biblioteca estándar de entrada/salida

// Función para imprimir el Triángulo de Pascal
void imprimirTrianguloPascal(int filas) {
    // Bucle para iterar sobre cada fila
    for (int i = 0; i < filas; i++) {
        int coeficiente = 1; // Coeficiente inicial para cada fila

        // Imprimir espacios para centrar el triángulo
        for (int j = 0; j < filas - i - 1; j++) {
            printf(" "); // Imprimir un espacio
        }

        // Bucle para calcular y mostrar los coeficientes en la fila actual
        for (int j = 0; j <= i; j++) {
            printf("%d ", coeficiente); // Imprimir el coeficiente actual
            // Calcular el siguiente coeficiente usando la fórmula del coeficiente binomial
            coeficiente = coeficiente * (i - j) / (j + 1);
        }
        printf("\n"); // Nueva línea después de cada fila
    }
}

// Función principal del programa
int main() {
    int filas; // Variable para almacenar el número de filas

    // Solicitar al usuario el número de filas del Triángulo de Pascal
    printf("Ingrese el número de filas del Triángulo de Pascal: ");
    scanf("%d", &filas); // Leer el número de filas ingresado por el usuario

    // Llamar a la función para imprimir el triángulo
    imprimirTrianguloPascal(filas);

    return 0; // Indicar que el programa terminó correctamente
}
