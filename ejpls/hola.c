#include <stdio.h>
#define MENSAJE "¡Hola Henry!\n"

int main() {
    printf(MENSAJE);
    return 0;
}


#include <stdio.h>

int main()
{
int contador = 1000;
while(contador>=0)
{
    contador--;
    if (contador%7==0)
    {
        printf("multiplos de 7: %d\n", contador);
    }
    if (contador%9==0)
    {
        printf("multiplos de 9: %d",contador);
    }
  
}
return 0;
}
