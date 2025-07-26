#include <stdio.h>
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad

int main()
{
    FILE *in, *out; // Declaración de punteros a archivos

    // Variables para almacenar datos de la encuesta
    int countRespuestas = 0, pregunta, mayor = 0, menor = 6, puntAlta = 0, puntBaja = 0;
    float promedio, respuesta, suma = 0.0; // Variables para cálculos de puntuaciones

    // Abre los archivos de entrada y salida
    in = fopen("datos_encuesta.txt", "r");
    out = fopen("informe_encuesta.txt", "w");

    if (in != NULL) // Verifica si el archivo se abrió correctamente
    {
        // Lee las preguntas y respuestas del archivo hasta que no haya más
        while (fscanf(in, "%d", &pregunta) == 1) // Lee el número de la pregunta
        {
            fscanf(in, "%f", &respuesta); // Lee la respuesta correspondiente
            countRespuestas++;            // Incrementa el contador de respuestas
            suma += respuesta;            // Suma las respuestas para calcular el promedio

            // Verifica si la respuesta actual es la mayor
            if (respuesta > mayor)
            {
                mayor = respuesta; // Actualiza la mayor respuesta
            }

            // Verifica si la respuesta actual es la menor
            if (respuesta < menor)
            {
                menor = respuesta; // Actualiza la menor respuesta
            }

            // Cuenta cuántas respuestas son consideradas altas (4 o más)
            if (respuesta >= 4)
            {
                puntAlta++; // Incrementa el contador de puntuaciones altas
            }

            // Cuenta cuántas respuestas son consideradas bajas (2 o menos)
            if (respuesta <= 2)
            {
                puntBaja++; // Incrementa el contador de puntuaciones bajas
            }
        }

        // Calcula el promedio de las respuestas
        promedio = suma / countRespuestas;

        // Escribe los resultados en el archivo de salida
        fprintf(out, "Total de Respuestas Procesadas: %d\n", countRespuestas); // Total de respuestas
        fprintf(out, "Suma Total de Puntuaciones: %.0f\n", suma);              // Suma total de puntuaciones
        fprintf(out, "Puntación Promedio General: %.2f\n\n", promedio);        // Promedio de puntuaciones
        fprintf(out, "Respuestas con Puntuación Alta: %d\n", puntAlta);        // Total de respuestas altas
        fprintf(out, "Respuestas con Puntuación Baja: %d\n\n", puntBaja);      // Total de respuestas bajas
        fprintf(out, "Puntuación Máxima Registrada: %d\n", mayor);             // Máxima puntuación registrada
        fprintf(out, "Puntuación Mínima Registrada: %d\n", menor);             // Mínima puntuación registrada
    }
    else // Si no se pudo abrir el archivo
    {
        printf("Error al abrir el archivo de entrada.\n"); // Mensaje de error
    }

    fclose(in);  // Cierra el archivo de entrada
    fclose(out); // Cierra el archivo de salida
    return 0;    // Fin del programa
}
