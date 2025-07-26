#include <stdio.h>

int main (){

    int A; // Variable para el primer número (Divisor Dinámico)
    int B; // Variable para el segundo número (Factor Acumulable)
    int suma_final = 0; // Variable para acumular el resultado de la multiplicación
    
    // Variables para almacenar los valores iniciales de A y B
    // Se usan para la impresión final del resultado, ya que A y B se modifican durante el algoritmo
    int A_inicial;
    int B_inicial;

    printf("Bienvenido al algoritmo de Multiplicacion Rusa.\n");

    // Solicitar y validar el primer número (A)
    do {
        printf("Ingrese el primer numero entero positivo (A): ");
        scanf("%d", &A);

        if (A <= 0) {
            printf("Error: A debe ser un numero positivo. Intente de nuevo.\n");
        }
    } while (A <= 0);

    // Solicitar y validar el segundo número (B)
    do {
        printf("Ingrese el segundo numero entero positivo (B): ");
        scanf("%d", &B);

        if (B <= 0) {
            printf("Error: B debe ser un numero positivo. Intente de nuevo.\n");
        }
    } while (B <= 0);

    // Guardar los valores iniciales de A y B antes de que se modifiquen
    A_inicial = A;
    B_inicial = B;

    printf("\n--- Proceso de Multiplicacion Rusa ---\n");

    // El ciclo continúa mientras A sea mayor que 0.
    while (A > 0) { 
        // Mostrar los valores actuales de A y B en cada paso
        printf("A: %d | B: %d | ", A, B); 

        // Comprobar si A es impar (A % 2 != 0) o par (A % 2 == 0)
        if (A % 2 != 0) { // (Usa el operador módulo para verificar paridad)
            suma_final = suma_final + B; // Sumar B si A es impar 
            printf("A es impar -> Sumar B\n");
        } else {
            printf("A es par   -> Ignorar\n");
        }

        A = A / 2; // Dividir A por 2 (división entera, ignora el residuo)
        B = B * 2; // Duplicar B (multiplicar por 2)
    }

    printf("\nEl resultado de la multiplicacion (%d * %d) es: %d\n", A_inicial, B_inicial, suma_final);

    return 0;
}