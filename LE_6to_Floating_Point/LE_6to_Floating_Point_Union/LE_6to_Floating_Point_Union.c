
#include <stdio.h>

#define CANT 4
#define CANT_FOR 3
#define MASCARA_7_BITS_LSB 6
#define MASCARA_1_BYTE 7
#define MASCARA 1
#define CONVERSOR_DIRECTO 1
#define CALCULADORA_CONVERSORA 2
#define SALIR 3
#define FALSE 0
#define TRUE 1

typedef unsigned char one_byte_var;

void conversor (void);
float calculadora (int *);
void imprimir (void);

union analisis
{
    float num;
    one_byte_var byte[CANT];
}analisis;

int main()
{
    float resultado;
    one_byte_var op, perfil, decision_perfil_1, decision_perfil_2;
    int error = FALSE;
    int *p_error = &error;
    printf("\nBienvenido a mi Programa...\n\n");
    printf("En este programa podras:\n\t- Convertir a IEEE 754 numeros de punto flotante (Conversor Directo)\n");
    printf("\t- Convertir a IEEE 754 SUMAS | DIFERENCIAS | PRODUCTOS | COCIENTES\n\t  entre 2 numeros de punto flotante (Calculadora Conversora)\n");
    printf("\n-------------------------------------------------------------------------------------");
    printf("\n\t\t\t\tADVERTENCIA\n\nAl momento de ingresar los numeros flotantes, debera utilizar el caracter PUNTO [ . ]\n");
    printf("-------------------------------------------------------------------------------------\n");
    do
    {
        printf("\nPerfiles: [ 1 ] Conversor Directo\n\t  [ 2 ] Calculadora Conversora\n\t  [ 3 ] Salir\n");
        printf("Seleccione un Perfil\n>>> ");
        scanf("%d", &perfil);
        if (perfil == CONVERSOR_DIRECTO)
        {
            printf("\n--- Convertir a IEEE 754 numeros de punto flotante --- \n");
            do
            {
                conversor();
                printf("\n\nDesea convertir otro numero? [S/N]\n>>> ");
                fflush(stdin);
                scanf("%c", &decision_perfil_1);
            }while ((decision_perfil_1 == 's') || (decision_perfil_1 == 'S'));
        }
        else if (perfil == CALCULADORA_CONVERSORA)
        {
            printf("\n--- Convertir a IEEE 754 resultados operaciones entre 2 numeros de punto flotante ---\n");
            printf("\nPosibles Operaciones: Sumas [+], Restas [-], Multiplicaciones [*] y Divisiones [/]\n");
            do
            {
                resultado = calculadora(p_error);
                if (error == FALSE) imprimir();
                printf("\n\nDesea realizar otro calculo? [S/N]\n>>> ");
                fflush(stdin);
                scanf("%c", &decision_perfil_2);
            }while ((decision_perfil_2 == 's') || (decision_perfil_2 == 'S'));
        }
    }while (perfil != SALIR);
    printf("\nGracias por usar mi programa =)\n\n");
    return 0;
}

void conversor (void)
{
    float numero;
    int j, i;
    printf("\nIngrese el numero de punto flotante\n>>> ");
    scanf("%f", &numero);
    analisis.num = numero;
    printf("\n%f = 0x", numero);
    for (i = CANT_FOR; i >= 0; i--) printf("%.2X", analisis.byte[i]);
    printf(" = 0b");
    for (i = CANT_FOR; i >= 0; i--) for (j = MASCARA_1_BYTE; j >= 0; j--) printf("%d", ((analisis.byte[i] >> j) & MASCARA));
    printf("\n\n--- Partes del IEEE 754 ---\n\n");
    printf("Signo = 0b%d", ((analisis.byte[3] >> MASCARA_1_BYTE) & MASCARA));
    printf("\nExponente = 0b");
    for (i = MASCARA_7_BITS_LSB; i >= 0; i--) printf("%d", ((analisis.byte[3] >> i) & MASCARA));
    printf("%d", ((analisis.byte[2] >> MASCARA_1_BYTE) & 1));
    printf("\nMantisa = 0b");
    for (i = MASCARA_7_BITS_LSB; i >= 0; i--) printf("%d", ((analisis.byte[2] >> i) & MASCARA));
    for (i = MASCARA_1_BYTE; i >= 0; i--) printf("%d", ((analisis.byte[1] >> i) & MASCARA));
    for (i = MASCARA_1_BYTE; i >= 0; i--) printf("%d", ((analisis.byte[0] >> i) & MASCARA));
}

float calculadora (int *p)
{
    *p = FALSE;
    float numero_1, numero_2, resultado;
    one_byte_var op, error;
    printf("\nIngrese el primer numero de punto flotante\n>>> ");
    scanf("%f", &numero_1);
    printf("Ingrese el segundo numero de punto flotante\n>>> ");
    scanf("%f", &numero_2);
    if (numero_2 != 0)
    {
        printf("\nIngrese que operacion desea realizar --> [+] | [-] | [*] | [/]<--\n>>> ");
        fflush(stdin);
        scanf("%c", &op);
        switch (op)
        {
            case '+':
                resultado = numero_1 + numero_2;
                break;
            case '-':
                resultado = numero_1 - numero_2;
                break;
            case '*':
                resultado = numero_1 * numero_2;
                break;
            case '/':
                resultado = numero_1 / numero_2;
                break;
            default:
                printf("El caracter de operacion no es valido");
                break;
        }
    }
    else
    {
        printf("\nIngrese que operacion desea realizar --> [+] | [-] | [*] <--\n>>> ");
        fflush(stdin);
        scanf("%c", &op);
        switch (op)
        {
            case '+':
                resultado = numero_1 + numero_2;
                break;
            case '-':
                resultado = numero_1 - numero_2;
                break;
            case '*':
                resultado = numero_1 * numero_2;
                break;
            case '/':
                *p = TRUE;
            default:
                printf("\nEl caracter de operacion no es valido");
                break;
        }
    }
    if (*(p) == FALSE)
    {
        analisis.num = resultado;
        if (numero_2 >= 0) printf("\n%f %c %f = %f ", numero_1, op, numero_2, resultado);
        else printf("\n%f %c (%f) = %f ", numero_1, op, numero_2, resultado);
    }
    return (resultado);
}

void imprimir (void)
{
    int i;
    printf("= 0x");
    for (int i = CANT_FOR; i >= 0; i--) printf("%.2X", analisis.byte[i]);
    printf(" = 0b");
    for (int i = CANT_FOR; i >= 0; i--) for (int j = MASCARA_1_BYTE; j >= 0; j--) printf("%d", ((analisis.byte[i] >> j) & MASCARA));
    printf("\n\n--- Partes del IEEE 754 ---\n\n");
    printf("Signo = 0b%d", ((analisis.byte[3] >> MASCARA_1_BYTE) & MASCARA));
    printf("\nExponente = 0b");
    for (i = MASCARA_7_BITS_LSB; i >= 0; i--) printf("%d", ((analisis.byte[3] >> i) & MASCARA));
    printf("%d", ((analisis.byte[2] >> MASCARA_1_BYTE) & 1));
    printf("\nMantisa = 0b");
    for (i = MASCARA_7_BITS_LSB; i >= 0; i--) printf("%d", ((analisis.byte[2] >> i) & MASCARA));
    for (i = MASCARA_1_BYTE; i >= 0; i--) printf("%d", ((analisis.byte[1] >> i) & MASCARA));
    for (i = MASCARA_1_BYTE; i >= 0; i--) printf("%d", ((analisis.byte[0] >> i) & MASCARA));
}
