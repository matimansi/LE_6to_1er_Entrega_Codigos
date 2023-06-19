
#include <stdio.h>

#define CANT_CARAC 50

int Comparador_Strings (char*, char*);

int main()
{
    int retorno;
    char decision;
    char string_1[CANT_CARAC] = {0}, string_2[CANT_CARAC] = {0};
    char *p_string_1 = &string_1[0], *p_string_2 = &string_2[0];
    printf("\nBienvenido a mi programa...\n\n");
    printf("Con este programa podras comparar 2 strings (de MAX 20 caracteres)\npara saber si son iguales o distintos.\n\n");
    printf("Si se devuelve [ 0 ] los strings son IGUALES\n");
    printf("Si se devuelve [ 1 ] los strings son DISTINTOS\n");
    do
    {
        printf("\nIngrese el primer string\n>>> ");
        fflush(stdin);
        fgets(string_1, CANT_CARAC, stdin);
        printf("Ingrese el segundo string\n>>> ");
        fflush(stdin);
        fgets(string_2, CANT_CARAC, stdin);
        retorno = Comparador_Strings(p_string_1, p_string_2);
        printf("\nRetorno: %d", retorno);
        printf("\n\nDesea comparar otros strings? [S/N]\n>>> ");
        fflush(stdin);
        scanf("%c", &decision);
    } while ((decision == 'S') || (decision == 's'));
    printf("\nGracias por usar mi programa =)\n\n");
    return 0;
}

int Comparador_Strings (char *p_1, char *p_2)
{
    char x = 0;
    for(int i = 0; i < CANT_CARAC; i++)
    {
        if ((p_1[i]) != (p_2[i]))
        {
            x = 1;
            break;
        }
    }
    return (x);
}
