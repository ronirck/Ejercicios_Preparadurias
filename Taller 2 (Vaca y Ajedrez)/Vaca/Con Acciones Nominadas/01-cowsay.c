#include <stdio.h>

// Función que imprime una representación ASCII de una vaca en el archivo de salida
void imprimirVaca(FILE *out)
{
    fprintf(out, "\n *\n"); // Imprime la parte superior del globo de diálogo
    fprintf(out, " :\n");    // Imprime el símbolo de diálogo
    fprintf(out, "^__^\n");  // Imprime la cabeza de la vaca
    fprintf(out, "(oo)\\________\n"); // Imprime los ojos y la parte superior del cuerpo
    fprintf(out, "(__)\\        )\\/\\\n"); // Imprime las patas de la vaca
    fprintf(out, "    ||______W |\n"); // Imprime el cuerpo de la vaca
    fprintf(out, "    ||       ||\n"); // Imprime las patas traseras
}

// Función que imprime un marco de asteriscos de longitud especificada
void imprimirMarco(FILE *out, int length)
{
    for (int i = 0; i < length; i++)
    {
        fprintf(out, "*"); // Imprime un asterisco por cada longitud
    }
}


// Función que imprime líneas de asteriscos con un espacio en el medio
void imprimirLinea(FILE *out, int count, int length)
{
    for (int i = 0; i < count; i++)
    {
        fprintf(out, "*"); // Imprime un asterisco al inicio de la línea
        for (int i = 2; i < length; i++)
        {
            fprintf(out, " "); // Imprime espacios en blanco
        }
        fprintf(out, "*\n"); // Imprime el asterisco final y un salto de línea
    }
}

int main()
{
    FILE *in, *out; // Punteros a archivos para entrada y salida
    int count = 0, max = -1, marco; // Variables para contar caracteres y determinar el tamaño del marco
    char c; // Variable para almacenar caracteres leídos

    // Abre el archivo de entrada en modo lectura y el archivo de salida en modo escritura
    in = fopen("01-mensaje.txt", "r");
    out = fopen("01-salida.txt", "w");

    // Verifica si el archivo de entrada se abrió correctamente
    if (in != NULL)
    {
        // Lee el archivo carácter por carácter
        while (!feof(in))
        {
            fscanf(in, "%c", &c); // Lee un carácter
            count++; // Incrementa el contador de caracteres

            // Si se encuentra un salto de línea, verifica si la línea es la más larga
            if (c == '\n')
            {
                if (count > max)
                {
                    max = count - 1; // Actualiza la longitud máxima
                }
                count = 0; // Reinicia el contador para la siguiente línea
            }
        }
        rewind(in); // Regresa al inicio del archivo

        marco = max + 4; // Calcula la longitud del marco (longitud máxima + 4 para el espacio adicional)
        imprimirMarco(out, marco); // Imprime el marco superior
        fprintf(out, "\n"); // Salto de línea
        imprimirLinea(out, 2, marco); // Imprime dos líneas de asteriscos

        // Lee el archivo nuevamente para imprimir el contenido enmarcado
        while (!feof(in))
        {
            fscanf(in, "%c", &c); // Lee un carácter
            fprintf(out, "* "); // Imprime el asterisco inicial
            count = 1; // Reinicia el contador de caracteres para la línea actual
            while (!feof(in) && c != '\n') // Lee hasta el final de la línea
            {
                fprintf(out, "%c", c); // Imprime el carácter leído
                fscanf(in, "%c", &c); // Lee el siguiente carácter
                count++; // Incrementa el contador
            }
            // Imprime espacios en blanco hasta completar el marco
            for (int i = count + 2; i < marco; i++)
            {
                fprintf(out, " ");
            }
            fprintf(out, "*\n"); // Imprime el asterisco final y un salto de línea
        }

        imprimirLinea(out, 1, marco); // Imprime una línea de asteriscos al final
        imprimirMarco(out, marco); // Imprime el marco inferior
        imprimirVaca(out); // Imprime la vaca en el archivo de salida

        return 0; // Finaliza el programa con éxito
    }

    // Si no se pudo abrir el archivo de entrada, imprime un mensaje de error
    printf("Error abriendo el archivo.\n");
    return 1; // Finaliza el programa con un error
}
