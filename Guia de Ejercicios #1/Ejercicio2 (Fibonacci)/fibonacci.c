#include <stdio.h>   // Incluye la biblioteca estándar de entrada y salida
#include <stdlib.h>  // Incluye la biblioteca estándar de funciones generales

int main() // Función principal del programa
{
    int num1 = 0, num2 = 1, nextNum, count; // Declaración e inicialización de variables

    printf("Ingrese un numero entero y mayor que 3: "); // Solicita al usuario que ingrese un número entero mayor que 3
    scanf("%d", &count); // Lee el número ingresado y lo almacena en la variable 'count'

    // Genera la secuencia de Fibonacci hasta el número de elementos especificado por 'count'
    for (int i = 0; i < count; i++) 
    {
        printf("%d ", num1); // Imprime el número actual de la secuencia (num1)
        nextNum = num1 + num2; // Calcula el siguiente número en la secuencia de Fibonacci
        num1 = num2; // Actualiza 'num1' al valor de 'num2'
        num2 = nextNum; // Actualiza 'num2' al nuevo número calculado
    }

    return 0; // Finaliza la función principal
}