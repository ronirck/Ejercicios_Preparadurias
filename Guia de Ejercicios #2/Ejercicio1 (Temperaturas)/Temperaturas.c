#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivoEntrada, *archivoSalida; // Punteros para los archivos
    double temperatura; // Variable para almacenar la temperatura
    double sumaTemperaturas = 0.0; // Suma de las temperaturas
    int totalDias = 0; // Contador de días
    int diasAltos = 0; // Contador de días con temperatura alta
    int diasBajos = 0; // Contador de días con temperatura baja
    double tempMax = -9999.0; // Inicializar temperatura máxima
    double tempMin = 9999.0; // Inicializar temperatura mínima
    int diaMax = 0; // Día de la temperatura máxima
    int diaMin = 0; // Día de la temperatura mínima
    int diaActual = 0; // Contador para el día actual

    // Abrir el archivo de entrada
    archivoEntrada = fopen("temperaturas_registradas.txt", "r");
    // Abrir el archivo de salida
    archivoSalida = fopen("informe_climatico.txt", "w");

    // Verificar si los archivos se abrieron correctamente
    if (archivoEntrada == NULL || archivoSalida == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1; // Salir del programa con error
    }

    // Leer las temperaturas del archivo
    while (fscanf(archivoEntrada, "%lf", &temperatura) == 1) {
        totalDias++; // Incrementar el contador de días
        sumaTemperaturas += temperatura; // Sumar la temperatura

        // Contar días con temperaturas extremas
        if (temperatura >= 28.0) {
            diasAltos++; // Contar día con temperatura alta
        }
        if (temperatura <= 15.0) {
            diasBajos++; // Contar día con temperatura baja
        }

        // Verificar si es la temperatura máxima o mínima
        if (temperatura > tempMax) {
            tempMax = temperatura; // Actualizar temperatura máxima
            diaMax = totalDias; // Guardar el día (1-indexado)
        }
        if (temperatura < tempMin) {
            tempMin = temperatura; // Actualizar temperatura mínima
            diaMin = totalDias; // Guardar el día (1-indexado)
        }
        diaActual++; // Incrementar el día actual
    }

    // Calcular la temperatura promedio
    double promedioTemperaturas = sumaTemperaturas / totalDias;

    // Escribir el informe en el archivo de salida
    fprintf(archivoSalida, "--- Informe Climático Diario ---\n");
    fprintf(archivoSalida, "Total de Días Registrados: %d\n", totalDias);
    fprintf(archivoSalida, "Temperatura Promedio: %.2f °C\n", promedioTemperaturas);
    fprintf(archivoSalida, "Días con Temperatura Alta (>= 28°C): %d\n", diasAltos);
    fprintf(archivoSalida, "Días con Temperatura Baja (<= 15°C): %d\n", diasBajos);
    fprintf(archivoSalida, "--- Detalles de Temperaturas Extremas ---\n");
    fprintf(archivoSalida, "Temperatura Más Alta: %.2f °C (Día %d)\n", tempMax, diaMax);
    fprintf(archivoSalida, "Temperatura Más Baja: %.2f °C (Día %d)\n", tempMin, diaMin);

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);
    printf("Informe climático generado en informe_climatico.txt\n");

    return 0; // Salir del programa con éxito
}
