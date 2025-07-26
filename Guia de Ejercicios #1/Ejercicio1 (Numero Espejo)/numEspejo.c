#include <stdio.h>  // Incluye la biblioteca estándar de entrada y salida
#include <stdlib.h> // Incluye la biblioteca estándar de funciones generales

int main() // Función principal del programa
{
    int n, aux, mirror; // Declaración de variables

    printf("Ingrese un numero entero: "); // Solicita al usuario que ingrese un número entero
    scanf("%d", &n);                      // Lee el número ingresado y lo almacena en la variable 'n'

    if (n < 10) // Verifica si el número es menor que 10
    {
        mirror = n; // Si es menor que 10, el número espejo es el mismo número
    }
    else // Si el número es 10 o mayor
    {
        mirror = n % 10; // Inicializa 'mirror' con el último dígito de 'n'
        n = n / 10;      // Elimina el último dígito de 'n'

        // Invierte el número
        while (n > 0)
        {
            aux = n % 10; // Obtiene el último dígito de 'n'
            n = n / 10;   // Elimina el último dígito de 'n'

            mirror = mirror * 10 + aux; // Agrega el dígito obtenido al final de 'mirror'
        }
    }
    printf("El numero espejo es: %d\n", mirror); // Imprime el número espejo

    return 0; // Finaliza la función principal
}
