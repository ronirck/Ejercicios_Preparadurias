#include <stdio.h>
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad

int main()
{
    FILE *in, *out; // Declaración de punteros a archivos

    int countNotas = 0, aprobados = 0; // Contadores para el número de notas y aprobados
    float nota, suma = 0.0, mayor = -1, menor = 101, promedio; // Variables para almacenar notas y estadísticas

    // Abre los archivos de entrada y salida
    in = fopen("entrada.txt", "r");
    out = fopen("salida.txt", "w");

    if (in != NULL) // Verifica si el archivo se abrió correctamente
    {
        // Lee las notas del archivo hasta que no haya más
        while (fscanf(in, "%f", &nota) == 1)
        {
            countNotas++; // Incrementa el contador de notas
            suma += nota; // Suma las notas leídas

            // Verifica si la nota actual es la mayor
            if (nota > mayor)
            {
                mayor = nota; // Actualiza la mayor nota
            }

            // Verifica si la nota actual es la menor
            if (nota < menor)
            {
                menor = nota; // Actualiza la menor nota
            }

            // Verifica si la nota es aprobada (mayor o igual a 60)
            if (nota >= 60)
            {
                aprobados++; // Incrementa el contador de aprobados
            }
        }
        // Calcula el promedio de las notas
        promedio = suma / countNotas; 

        // Escribe los resultados en el archivo de salida
        fprintf(out, "Total de notas: %d\n", countNotas);                   // Escribe el total de notas
        fprintf(out, "Promedio de notas: %.2f\n", promedio);                // Escribe el promedio de notas
        fprintf(out, "Nota más alta: %.2f\n", mayor);                       // Escribe la mayor nota
        fprintf(out, "Nota más baja: %.2f\n", menor);                       // Escribe la menor nota
        fprintf(out, "Número de aprobados: %d\n", aprobados);               // Escribe el número de aprobados
        fprintf(out, "Número de reprobados: %d\n", countNotas - aprobados); // Escribe el número de reprobados
    }
    else // Si no se pudo abrir el archivo
    {
        printf("Error al abrir el archivo de entrada.\n"); // Mensaje de error
    }

    fclose(in); // Cierra el archivo de entrada
    fclose(out); // Cierra el archivo de salida
    return 0; // Fin del programa
}
