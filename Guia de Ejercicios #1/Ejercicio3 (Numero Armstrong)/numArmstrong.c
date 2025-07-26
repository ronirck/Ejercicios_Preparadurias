#include <stdio.h>  // Incluye la biblioteca estándar de entrada y salida
#include <stdlib.h> // Incluye la biblioteca estándar de funciones generales

int main() // Función principal del programa
{
    int num, aux, isArmstrong, digitCount, acumSum, acumPot, pot; // Declaración de variables

    printf("Ingrese un numero entero: "); // Solicita al usuario que ingrese un número entero
    scanf("%d", &num);                    // Lee el número ingresado y lo almacena en la variable 'num'

    if (num < 10) // Verifica si el número es menor que 10
    {
        printf("El numero %d es un numero Armstrong.\n", num); // Si es menor que 10, es un número Armstrong
    }
    else // Si el número es 10 o mayor
    {
        aux = num;      // Almacena el valor original de 'num' en 'aux' para usarlo más tarde
        digitCount = 0; // Inicializa el contador de dígitos

        // Cuenta el número de dígitos en 'num'
        while (num > 0)
        {
            digitCount++;   // Incrementa el contador de dígitos
            num = num / 10; // Elimina el último dígito de 'num'
        }

        acumSum = 0; // Inicializa la suma acumulada
        num = aux;   // Restaura 'num' a su valor original

        // Calcula la suma de las potencias de los dígitos
        while (aux > 0)
        {
            acumPot = 1;                     // Inicializa la acumulación de la potencia
            pot = aux % 10;                  // Obtiene el último dígito de 'aux'
            aux = aux / 10;                  // Elimina el último dígito de 'aux'

            // Calcula potencias del dígito
            for (int i = 1; i <= digitCount; i++)
            {
                acumPot = acumPot * pot; // Eleva el dígito a la potencia 'digitCount'
            }
            acumSum = acumSum + acumPot;                                                    // Suma la potencia acumulada a 'acumSum'
        }

        // Verifica si la suma acumulada es igual al número original
        if (acumSum == num)
        {
            printf("El numero %d es un numero Armstrong.\n", num); // Si son iguales, es un número Armstrong
        }
        else
        {
            printf("El numero %d no es un numero Armstrong.\n", num); // Si no son iguales, no es un número Armstrong
        }
    }

    return 0;
}
