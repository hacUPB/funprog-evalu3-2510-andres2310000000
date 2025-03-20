#include <stdio.h>

int main() {
    float n1, n2, r;
    int opcion;

    do {
        printf("Ingrese el primer número: ");
        scanf("%f", &n1);
        printf("Ingrese el segundo número: ");
        scanf("%f", &n2);

        printf("Seleccione la operación a realizar:\n");
        printf("1. Suma (+)\n");
        printf("2. Resta (-)\n");
        printf("3. Multiplicación (*)\n");
        printf("4. División (/)\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                r = n1 + n2;
                printf("Resultado: %.2f + %.2f = %.2f\n", n1, n2, r);
                break;
            case 2:
                r = n1 - n2;
                printf("Resultado: %.2f - %.2f = %.2f\n", n1, n2, r);
                break;
            case 3:
                r = n1 * n2;
                printf("Resultado: %.2f * %.2f = %.2f\n", n1, n2, r);
                break;
            case 4:
                if (n2 != 0) {
                    r = n1 / n2;
                    printf("Resultado: %.2f / %.2f = %.2f\n", n1, n2, r);
                } else {
                    printf("Error: No se puede dividir por cero.\n");
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
        printf("\n"); 
    } while (opcion != 5); 

    return 0;
}