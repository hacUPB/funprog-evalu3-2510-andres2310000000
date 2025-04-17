#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ley_de_ohm(float *V, float *I, float *R);
void factor_de_potencia(float *P, float *S, float *Q, float *FP, float *angulo);
void resistencia_conductor(float *ro, float *alfa, float *L, float *A, float *T, float *R20, float *R);
void resistencia_led();

int main() 
{
    int menu;
    float voltaje=0, corriente=0, resistencia=0;
    float p_activa=0, p_aparente=0, p_reactiva=0,fa_po=0,ang=0;
    float p=0, a=0, L_1=0, A_1=0, Temp=0, R20_1=0, Res=0; 
    do{
    printf("\nElija lo que desea calcular:\n");
    printf("1. Ley de Ohm\n");
    printf("2. Factor de Potencia\n");
    printf("3. Resistencia de un Conductor\n");
    printf("4. Resistencia para un LED\n");
    printf("5. Salir\n\n");
     scanf("%d", &menu);

        switch (menu)
         {
            case 1:
                ley_de_ohm(&voltaje, &corriente, &resistencia);
                break;
            case 2:
                factor_de_potencia(&p_activa, &p_aparente, &p_reactiva, &fa_po, &ang);
                break;
            case 3:
                resistencia_conductor(&p, &a, &L_1, &A_1, &Temp, &R20_1, &Res);
                break;
            case 4:
                resistencia_led();
                break;
            case 5:
                printf("Se cerro el programa con exito. \n");
                break;
            default:
                printf("Opción no válida, intente nuevamente.\n");
        }

    } 
    while (menu!= 5);
    return 0;
}

void ley_de_ohm(float *V, float *I, float *R) 
{
    int menu_ley_ohm;
    printf("\nHas seleccionado calcular la Ley de Ohm.\n");
    printf("1. Calcular Tensión \n");
    printf("2. Calcular Corriente\n");
    printf("3. Calcular Resistencia\n");
    printf("Seleccione una opción: ");
    scanf("%d", &menu_ley_ohm);

    switch (menu_ley_ohm) 
    {
        case 1:
            printf("Ingrese la corriente (A): ");
            scanf("%f", I);
            printf("Ingrese la resistencia (Ohm): ");
            scanf("%f", R);
            (*V)=(*I)*(*R);
            printf("Voltaje = %.2f V\n", *V);
            break;
        case 2:
            printf("Ingrese el voltaje (V): ");
            scanf("%f", V);
            printf("Ingrese la resistencia (Ohm): ");
            scanf("%f", R);
            if (R != 0) {
                *I = *V / *R;
                printf("Corriente = %.2f A\n", *I);
            } else {
                printf("Error: La resistencia no puede ser cero.\n");
            }
            break;
        case 3:
            printf("Ingrese el voltaje (V): ");
            scanf("%f", V);
            printf("Ingrese la corriente (A): ");
            scanf("%f", I);
            if (I != 0) {
                *R = *V / *I;
                printf("Resistencia = %.2f Ohm\n", *R);
            } else {
                printf("Error: La corriente no puede ser cero.\n");
            }
            break;
        default:
            printf("Opción no válida.\n");
    }
}
    
    void factor_de_potencia( float *P, float *S, float *Q, float *FP, float *angulo) 
    {
    int menu_factor_de_potencia;

    printf("\nHas seleccionado calcular el Factor de Potencia.\n");
    printf("Seleccione una opción: \n");
    printf("1. Calcular FP usando P y S\n");
    printf("2. Calcular FP usando P y Q\n");
    printf("3. Calcular FP usando el Q y S\n");
    printf("4. Calcular FP usando el ángulo de fase\n");;
     scanf("%d", &menu_factor_de_potencia);

    switch (menu_factor_de_potencia) 
     {
        case 1:
            printf("Ingrese la potencia activa (W): ");
            scanf("%f", P);
            printf("Ingrese la potencia aparente (VA): ");
            scanf("%f", S);
            if (S != 0) {
                *FP = *P / *S;
                printf("Factor de Potencia = %.2f\n", *FP);
            } else {
                printf("Error: La potencia aparente no puede ser cero.\n");
            }
            break;
            
        case 2: // U
            printf("Ingrese la potencia activa (W): ");
            scanf("%f", P);
            printf("Ingrese la potencia reactiva (VAR): ");
             scanf("%f", Q);
            *S = sqrt((*P)*(*P)+(*Q)*(*Q));
            if (S!=0) 
            {
                (*FP) = *P / *S;
                printf("Factor de Potencia = %f\n", *FP);
                printf("Potencia Aparente = %f VA\n", *S);
            } else 
            {
                printf("Error: La potencia aparente no puede ser cero.\n");
            }
            break;
            
        case 3:
        printf("\nHas seleccionado calcular el Factor de Potencia usando Q y S.\n");
        printf("Ingrese la potencia reactiva (VAR): ");
        scanf("%f", Q);
        printf("Ingrese la potencia aparente (VA): ");
         scanf("%f", S);

             if (S!=0 && Q<=S) 
             { 
             *FP = sqrt(1-((*Q) / (*S))*( (*Q) / (*S))); 
             printf("Factor de Potencia = %f\n", *FP);
             }        
             else 
             {
             printf("Error: La potencia aparente no puede ser cero y Q debe ser menor o igual a S.\n");
             }
             break;
    
        case 4:
            printf("Ingrese el ángulo de desfase (en grados): ");
             scanf("%f", angulo);
            *FP = cos(*angulo); 
            printf("Factor de Potencia = %f\n", *FP);
            break;
            
        default:
            printf("Opción no válida.\n");
    } 
  }
  
  void resistencia_conductor(float *ro, float *alfa, float *L, float *A, float *T, float *R20, float *R) 
{
    int menu_resistencia_conductor;

    printf("\nResistencia de un Conductor.\n");
    printf("Seleccione el material del conductor: \n");
    printf("1. Cobre\n");
    printf("2. Aluminio\n");
    printf("3. Oro\n");
    printf("4. Otro\n");
    scanf("%d", &menu_resistencia_conductor);

    switch (menu_resistencia_conductor) 
    {
        case 1: 
        *ro=1.68e-8;
            *alfa=0.00393;
            break;
        case 2:
            *ro=2.82e-8;
            *alfa=0.00390;
            break;
        case 3:
            *ro=2.44e-8;
            *alfa=0.00340;
            break;
        case 4:
            printf("Ingrese la resistividad del material a 20°C (Ohm·m): ");
            scanf("%f", ro);
            printf("Ingrese el coeficiente de temperatura (1/°C): ");
            scanf("%f", alfa);
            break;
        default:
            printf("Opción no válida.\n");
            return;
    }

    printf("Ingrese la longitud del conductor (m): ");
    scanf("%f", L);
    printf("Ingrese el área de la sección transversal (m^2): ");
    scanf("%f", A);
    printf("Ingrese la temperatura de operación (°C): ");
    scanf("%f", T);

    if (A>0) 
    {
        *R20 = (*ro)*((*L) / (*A));
        *R = (*R20)*(1+(*alfa)*((*T)-20));
        printf("La resistencia del conductor a %f°C es: %f Ohm\n", *T, *R);
    } else {
        printf("Error: El área debe ser mayor que cero.\n");
    }
}
 
void resistencia_led() 
{
    double V_fuente, V_L, I_L, R, P_R, P_Total, I_Total;
    int num_leds, tipo_conexion;
    
    printf("\nResistencia para un LED.\n");
    printf("Ingrese la tensión de la fuente (V): ");
    scanf("%lf", &V_fuente);
    printf("Ingrese el número de ledes en el circuito: ");
    scanf("%d", &num_leds);
    printf("Seleccione el tipo de conexión:\n1. Serie\n2. Paralelo\nOpción: ");
    scanf("%d", &tipo_conexion);
    printf("Ingrese la tensión nominal del LED (V): ");
    scanf("%lf", &V_L);
    printf("Ingrese la corriente nominal del LED (A): ");
    scanf("%lf", &I_L);
    
    if (tipo_conexion==1) 
    { 
        double V_total_leds=num_leds*V_L;
        if (V_fuente>V_total_leds) 
        {
            R=(V_fuente-V_total_leds)/I_L;
            I_Total = I_L;
        } else {
            printf("Error: La tensión de la fuente debe ser mayor que la suma de las tensiones de los LEDs en serie.\n");
            return;
        }
    } 
    
    else if (tipo_conexion==2) 
    { 
        if (V_fuente>V_L) 
        {
            R=(V_fuente-V_L)/(num_leds*I_L);
            I_Total=num_leds*I_L;
        } else {
            printf("Error: La tensión de la fuente debe ser mayor que la tensión de un solo LED en paralelo.\n");
            return;
        }
    } 
    
          else 
        {
        printf("Error: Opción no válida para la conexión.\n");
        return;
        }
    
    P_R = I_Total * I_Total * R; 
    P_Total = V_fuente * I_Total; 
    
    printf("\nResultados:\n");
    printf("Valor de la resistencia: %f Ohm\n", R);
    printf("Potencia disipada en la resistencia: %f W\n", P_R);
    printf("Potencia total del circuito: %f W\n", P_Total);
    printf("Corriente total suministrada por la fuente: %f A\n", I_Total);
    return;
}