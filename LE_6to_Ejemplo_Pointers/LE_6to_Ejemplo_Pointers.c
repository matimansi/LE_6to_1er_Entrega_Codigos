
#include <stdio.h>

void pasaje_valor (int);
void pasaje_referencia(int *);

int main()
{
    int var = 10;
    int *puntero = &var;

    printf("\nvar = %d\n", *puntero);
    printf("La direccion de memoria de var es 0x%X\n", puntero);
    
    puntero++;
    printf("La direccion a la que apunta puntero es 0x%X\n", puntero);
    puntero--;

    (*puntero)++;
    printf("El contenido de puntero vale %d\n\n", *puntero);

    // Puntero Indexado

    int vector[3] = {1, 2, 3};
    int *puntero_indexado = &vector[0];

    printf("vector = {");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("%d", puntero_indexado[i]);
            break;
        }
        printf("%d, ", puntero_indexado[i]);
    }
    printf("}\n");

    puntero_indexado[2] = 10;

    printf("vector = {");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("%d", puntero_indexado[i]);
            break;
        }
        printf("%d, ", puntero_indexado[i]);
    }
    printf("}\n\n");

    // Pasaje por valor

    int x = 50;
    pasaje_valor(x);
    printf("X en la funcion main vale %d\n\n", x);

    // Pasaje por referencia

    int *puntero_x = &x;
    pasaje_referencia(puntero_x);
    printf("X en la funcion main vale %d", x);
    return 0;
}

void pasaje_valor (int x)
{
    x++;
    printf("X en la funcion pasaje_valor vale %d\n", x);
}

void pasaje_referencia (int *puntero_x)
{
    (*puntero_x)++;
    printf("X en la funcion pasaje_referencia vale %d\n", *puntero_x);
}
