#include <stdio.h>

int main() {
    FILE *in, *out; // Declaración de punteros a archivos para entrada y salida
    int count = 0, max = -1, marco; // Inicialización de contadores y variables
    char c; // Variable para almacenar caracteres leídos

    // Abrir el archivo de entrada en modo lectura y el archivo de salida en modo escritura
    in = fopen("mensaje.txt", "r");
    out = fopen("salida.txt", "w");

    // Verificar si el archivo de entrada se abrió correctamente
    if (in != NULL) {
        // Leer el archivo carácter por carácter hasta el final
        while (!feof(in)) {
            fscanf(in, "%c", &c); // Leer un carácter
            count++; // Incrementar el contador de caracteres

            // Si se encuentra un salto de línea, verificar la longitud de la línea
            if (c == '\n') {
                if (count > max) {
                    max = count - 1; // Actualizar la longitud máxima de la línea
                }
                count = 0; // Reiniciar el contador para la siguiente línea
            }
        }
        rewind(in); // Volver al inicio del archivo para leerlo nuevamente

        // Calcular el tamaño del marco (longitud máxima de la línea + 4 para los bordes)
        marco = max + 4;

        // Imprimir la parte superior del marco
        for (int i = 0; i < marco; i++) {
            fprintf(out, "*");
        }
        fprintf(out, "\n*");

        // Imprimir los espacios en blanco a la izquierda y derecha del texto
        for (int i = 2; i < marco; i++) {
            fprintf(out, " ");
        }
        fprintf(out, "*\n*");
        for (int i = 2; i < marco; i++) {
            fprintf(out, " ");
        }
        fprintf(out, "*\n");

        // Leer el archivo nuevamente y escribir el contenido dentro del marco
        while (!feof(in)) {
            fscanf(in, "%c", &c); // Leer un carácter
            fprintf(out, "* "); // Imprimir el borde izquierdo del marco
            count = 1; // Reiniciar el contador para la línea actual
            while (!feof(in) && c != '\n') {
                fprintf(out, "%c", c); // Imprimir el carácter leído
                fscanf(in, "%c", &c); // Leer el siguiente carácter
                count++; // Incrementar el contador de caracteres
            }
            // Imprimir espacios en blanco a la derecha del texto
            for (int i = count + 2; i < marco; i++) {
                fprintf(out, " ");
            }
            fprintf(out, "*\n"); // Imprimir el borde derecho del marco
        }

        // Imprimir la parte inferior del marco
        fprintf(out, "*");
        for (int i = 2; i < marco; i++) {
            fprintf(out, " ");
        }
        fprintf(out, "*\n");

        // Imprimir la parte inferior del marco
        for (int i = 0; i < marco; i++) {
            fprintf(out, "*");
        }
        fprintf(out, "\n *\n"); // Espacio para el dibujo de la vaca

        // Dibujo de la vaca que parece estar hablando
        fprintf(out, " :\n");
        fprintf(out, "^__^\n");
        fprintf(out, "(oo)\\________\n");
        fprintf(out, "(__)\\        )\\/\\\n");
        fprintf(out, "    ||______W |\n");
        fprintf(out, "    ||       ||\n");
    }
    else
    {
        printf("error de apertura de archivo\n");
    }
    return 0; // Fin del programa
}
