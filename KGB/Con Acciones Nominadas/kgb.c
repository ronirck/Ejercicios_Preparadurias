#include <stdio.h>

// Función para imprimir una figura en forma de 'X'
void printX(FILE *out, int n)
{
    int start = 0, end = n;     // Inicializa los límites de la figura
    for (int i = 0; i < n; i++) // Itera sobre cada fila
    {
        for (int j = 0; j < end; j++) // Itera sobre cada columna
        {
            // Imprime '*' en los bordes de la figura
            if (j == start || j == end - 1)
            {
                fprintf(out, "*");
            }
            else
            {
                fprintf(out, " "); // Imprime espacio en el interior
            }
        }
        fprintf(out, "\n"); // Salto de línea al final de cada fila

        // Ajusta los límites para la siguiente fila
        if (i < n / 2)
        {
            if (start + 1 != end - 1) // Evita que se crucen los límites
            {
                start++;
                end--;
            }
        }
        else
        {
            start--; // Expande los límites hacia afuera
            end++;
        }
    }
    fprintf(out, "\n"); // Salto de línea después de la figura
}

// Función para imprimir una figura en forma de 'O'
void printO(FILE *out, int n)
{
    int start, end;

    end = n / 2;                        // Establece el límite inicial
    start = n % 2 == 0 ? end - 1 : end; // Ajusta el inicio según si n es par o impar
    for (int i = 0; i < n; i++)         // Itera sobre cada fila
    {
        for (int j = 0; j < n; j++) // Itera sobre cada columna
        {
            // Imprime '*' en los bordes de la figura
            if (j == start || j == end)
            {
                fprintf(out, "*");
            }
            else
            {
                fprintf(out, " "); // Imprime espacio en el interior
            }
        }
        fprintf(out, "\n"); // Salto de línea al final de cada fila
        // Ajusta los límites para la siguiente fila
        if (i < n / 2)
        {
            if (start - 1 >= 0) // Asegura que no se salga del rango
            {
                start--;
                end++;
            }
        }
        else
        {
            start++; // Expande los límites hacia afuera
            end--;
        }
    }
    fprintf(out, "\n"); // Salto de línea después de la figura
}

// Función para convertir un número binario (en forma de cadena) a decimal
int bin(int n)
{
    int aux, count = -1, result = 0, acum;

    while (n > 0) // Mientras haya dígitos en el número
    {
        aux = n % 10; // Obtiene el último dígito
        n /= 10;      // Elimina el último dígito
        count++;      // Incrementa el contador de posición

        // Si el dígito es 1, calcula su valor decimal
        if (aux == 1)
        {
            acum = 1;
            for (int i = 0; i < count; i++)
            {
                acum *= 2; // Calcula la potencia de 2
            }
            result += acum; // Suma al resultado
        }
    }
    return result; // Devuelve el resultado decimal
}

int main()
{
    FILE *in, *out;

    // Abre los archivos de entrada y salida
    in = fopen("./../in1.txt", "r");
    out = fopen("out3.txt", "w");

    char c;
    int n, flag = 1, countVar = -1, first, variabilidad;

    if (in != NULL) // Verifica si el archivo se abrió correctamente
    {
        // Lee caracteres del archivo de entrada
        while (fscanf(in, "%c", &c) == 1 && flag)
        {
            // Si el carácter es una letra minúscula, la convierte a mayúscula
            if (c > 91 && c < 123)
            {
                c -= 32;                       // Convierte a mayúscula
                fprintf(out, "¿");             // Imprime '¿' al inicio de la línea
                while (c != '\n' && !feof(in)) // Lee hasta el final de la línea
                {
                    fprintf(out, "%c", c); // Imprime el carácter
                    fscanf(in, "%c", &c);  // Lee el siguiente carácter
                }
                fprintf(out, "%c\n", 63); // Imprime '?' al final de la línea
            }
            // Si el carácter es '1' o '0', procesa el número binario
            else if (c == '1' || c == '0')
            {
                fscanf(in, "%d", &n); // Lee el número
                n = bin(n);           // Convierte de binario a decimal
                if (countVar == -1)   // Inicializa la primera variable
                {
                    first = n;
                    countVar = 0;
                }

                // Verifica la variabilidad del número
                if (n - first != 0)
                {
                    countVar++;
                }
                else
                {
                    countVar = 0;
                }

                // Si hay demasiada variabilidad, termina el proceso
                if (n - first >= 2 || countVar > 1)
                {
                    flag = 0;
                }
                else
                {
                    // Imprime la figura correspondiente
                    if (c == '1')
                    {
                        printX(out, n); // Imprime 'X'
                    }
                    else
                    {
                        printO(out, n); // Imprime 'O'
                    }
                    fscanf(in, "%c", &c); // Lee el siguiente carácter
                }
            }
            else
            {
                flag = 0; // Termina el proceso si se encuentra un carácter no válido
            }
        }

        // Si se detectó un problema, imprime un mensaje de alerta
        if (!flag)
        {
            fprintf(out, "ALERTA ROJA: CANAL COMPROMETIDO\n");
        }
    }
    else
    {
        printf("error de apertura de archivo\n"); // Mensaje de error si no se pudo abrir el archivo
    }

    fclose(in);  // Cierra el archivo de entrada
    fclose(out); // Cierra el archivo de salida
    return 0;    // Fin del programa
}
