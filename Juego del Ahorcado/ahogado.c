// Juego del Ahorcado
// Este programa implementa un juego del ahorcado en C, donde el usuario debe adivinar una palabra oculta ingresando letras.
// El programa lee las palabras desde un archivo de texto y permite al usuario jugar múltiples rondas.
// El usuario tiene un número limitado de intentos para adivinar la palabra antes de perder.
// El juego finaliza cuando el usuario decide no seguir jugando o se quedan sin palabras en el archivo.

#include <stdio.h>
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad

int main()
{
    FILE *in;                                                                      // Declaración de puntero a archivo
    char palabra[100], letra, descubierto[100];                                    // Variables para almacenar la palabra, la letra ingresada y la palabra descubierta
    int countPalabra, countPisos, victoria = 0, flag, numIntentos = 6, seguir = 1; // Variables para conteo y control del juego

    // Abre el archivo de entrada
    in = fopen("in.txt", "r");

    if (in != NULL) // Verifica si el archivo se abrió correctamente
    {
        // Lee palabras del archivo hasta que no haya más o el usuario decida dejar de jugar
        while (fscanf(in, "%s", palabra) == 1 && seguir)
        {
            countPalabra = 0; // Inicializa el contador de letras en la palabra

            // Inicializa la palabra descubierta con guiones bajos
            while (palabra[countPalabra] != '\0') // Recorre la palabra hasta el final
            {
                descubierto[countPalabra] = '_'; // Asigna '_' a cada letra de la palabra
                countPalabra++;                  // Incrementa el contador de letras
            }
            printf("Palabra: "); // Muestra la palabra oculta
            for (int i = 0; i < countPalabra; i++)
            {
                printf("%c", descubierto[i]); // Imprime la representación oculta de la palabra
            }
            printf("(%d letras)\n", countPalabra); // Muestra la cantidad de letras en la palabra

            // Ciclo principal del juego, se repite mientras haya intentos y no se haya ganado
            while (numIntentos > 0 && !victoria)
            {
                printf("Ingrese una letra: "); // Solicita al usuario que ingrese una letra
                scanf(" %c", &letra);          // Lee la letra ingresada

                flag = 0;                              // Inicializa el flag para verificar si la letra es correcta
                countPisos = 0;                        // Inicializa el contador de letras no descubiertas
                for (int i = 0; i < countPalabra; i++) // Recorre cada letra de la palabra
                {
                    // Verifica si la letra ingresada coincide con alguna letra de la palabra (considerando mayúsculas y minúsculas)
                    if (palabra[i] == letra || palabra[i] == letra - 32 || palabra[i] == letra + 32)
                    {
                        flag = 1;               // Marca que se encontró una letra correcta
                        descubierto[i] = letra; // Actualiza la letra descubierta
                    }

                    // Cuenta cuántas letras aún no han sido descubiertas
                    if (descubierto[i] == '_')
                    {
                        countPisos++; // Incrementa el contador de letras no descubiertas
                    }
                }

                // Si se encontró una letra correcta
                if (flag)
                {
                    printf("Correcto! "); // Mensaje de acierto
                    for (int i = 0; i < countPalabra; i++)
                    {
                        printf("%c", descubierto[i]); // Muestra la palabra descubierta hasta el momento
                    }
                    printf("\n");
                }
                else // Si la letra no es correcta
                {
                    numIntentos -= 1;                                                    // Decrementa el número de intentos restantes
                    printf("Letra incorrecta. Intentos restantes: %d/6\n", numIntentos); // Muestra intentos restantes
                }

                // Verifica si se ha descubierto la palabra completa
                if (countPisos == 0)
                {
                    victoria = 1; // Marca que se ha ganado
                }
            }

            // Mensajes finales según el resultado del juego
            if (victoria)
            {
                printf("Felicidades, descubriste la palabra\n"); // Mensaje de victoria
            }
            else
            {
                printf("Perdiste. Te has quedado sin intentos.\n"); // Mensaje de derrota
            }

            // Pregunta al usuario si desea seguir jugando
            printf("\nDesea seguir jugando ?(s/n): ");
            scanf(" %c", &letra); // Lee la respuesta del usuario

            // Si el usuario elige no seguir, termina el juego
            if (letra == 'n')
            {
                seguir = 0; // Cambia el flag para salir del bucle
            }
            else // Si el usuario desea seguir
            {
                victoria = 0;    // Reinicia el estado de victoria
                numIntentos = 6; // Reinicia el número de intentos
            }
        }

        // Mensaje si se han agotado las palabras en el archivo
        if (seguir)
        {
            printf("Lo siento, nos hemos quedado sin palabras.");
        }
    }
    else // Si no se pudo abrir el archivo
    {
        printf("Error, archivo de entrada no encontrado."); // Mensaje de error
    }

    fclose(in); // Cierra el archivo de entrada
    return 0;   // Fin del programa
}
