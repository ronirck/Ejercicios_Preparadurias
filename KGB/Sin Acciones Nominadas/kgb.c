#include <stdio.h>
#include <math.h> // Incluye la biblioteca matemática para usar la función pow()

int main()
{
    FILE *in, *out; // Declaración de punteros a archivos

    // Abre los archivos de entrada y salida
    in = fopen("in3.txt", "r");
    out = fopen("out3.txt", "w");

    char c; // Variable para almacenar caracteres leídos
    int n, flag = 1, countVar = -1, first, variabilidad; // Variables para control de flujo y conteo
    int startX, endX, startO, endO; // Variables para los límites de las figuras
    int auxDigit, acum, countBin, auxNum; // Variables auxiliares para cálculos

    if (in != NULL) // Verifica si el archivo se abrió correctamente
    {
        // Lee caracteres del archivo de entrada
        while (fscanf(in, "%c", &c) == 1 && flag)
        {
            // Si el carácter es una letra minúscula, la convierte a mayúscula
            if (c > 91 && c < 123)
            {
                c -= 32; // Convierte a mayúscula

                // Lee hasta el final de la línea
                while (c != '\n' && !feof(in))
                {
                    fprintf(out, "%c", c); // Imprime el carácter
                    fscanf(in, "%c", &c); // Lee el siguiente carácter
                }
                fprintf(out, "%c\n", 63); // Imprime '?' al final de la línea
            }
            // Si el carácter es '1' o '0', procesa el número binario
            else if (c == '1' || c == '0')
            {
                fscanf(in, "%d", &n); // Lee el número
                auxNum = n; // Almacena el número original
                n = 0; // Reinicia n para el cálculo
                countBin = -1; // Inicializa el contador de dígitos binarios

                // Convierte el número binario (en forma de cadena) a decimal
                while (auxNum > 0)
                {
                    auxDigit = auxNum % 10; // Obtiene el último dígito
                    auxNum /= 10; // Elimina el último dígito
                    countBin++; // Incrementa el contador de posición
                    if (auxDigit == 1) // Si el dígito es 1, suma su valor decimal
                    {
                        n += pow(2, countBin); // Calcula la potencia de 2 y la suma
                    }
                }

                // Inicializa la primera variable si es la primera vez
                if (countVar == -1)
                {
                    first = n; // Almacena el primer número
                    countVar = 0; // Inicializa el contador de variabilidad
                }

                // Verifica la variabilidad del número
                if (n - first != 0)
                {
                    countVar++; // Incrementa el contador si hay variabilidad
                }
                else
                {
                    countVar = 0; // Reinicia el contador si no hay variabilidad
                }

                // Si hay demasiada variabilidad, termina el proceso
                if (n - first >= 2 || countVar > 1)
                {
                    flag = 0; // Cambia el flag para salir del bucle
                }
                else
                {
                    // Imprime la figura correspondiente
                    if (c == '1') // Si el carácter es '1', imprime 'X'
                    {
                        startX = 0; // Inicializa el límite de inicio para 'X'
                        endX = n; // Inicializa el límite de fin para 'X'
                        for (int i = 0; i < n; i++) // Itera sobre cada fila
                        {
                            for (int j = 0; j < endX; j++) // Itera sobre cada columna
                            {
                                // Imprime '*' en los bordes de la figura
                                if (j == startX || j == endX - 1)
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
                                if (startX + 1 != endX - 1) // Evita que se crucen los límites
                                {
                                    startX++;
                                    endX--;
                                }
                            }
                            else
                            {
                                startX--; // Expande los límites hacia afuera
                                endX++;
                            }
                        }
                        fprintf(out, "\n"); // Salto de línea después de la figura
                    }
                    else // Si el carácter es '0', imprime 'O'
                    {
                        endO = n / 2; // Establece el límite inicial para 'O'
                        startO = n % 2 == 0 ? endO - 1 : endO; // Ajusta el inicio según si n es par o impar
                        for (int i = 0; i < n; i++) // Itera sobre cada fila
                        {
                            for (int j = 0; j < n; j++) // Itera sobre cada columna
                            {
                                // Imprime '*' en los bordes de la figura
                                if (j == startO || j == endO)
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
                                if (startO - 1 >= 0) // Asegura que no se salga del rango
                                {
                                    startO--;
                                    endO++;
                                }
                            }
                            else
                            {
                                startO++; // Expande los límites hacia afuera
                                endO--;
                            }
                        }
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
        if (flag == 0)
        {
            fprintf(out, "ALERTA ROJA: CANAL COMPROMETIDO\n");
        }
    }
    else
    {
        printf("error de apertura de archivo\n"); // Mensaje de error si no se pudo abrir el archivo
    }

    fclose(in); // Cierra el archivo de entrada
    fclose(out); // Cierra el archivo de salida
    return 0; // Fin del programa
}
