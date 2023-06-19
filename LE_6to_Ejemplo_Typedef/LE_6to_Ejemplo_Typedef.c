
#include <stdio.h>

typedef unsigned char one_byte_var;
typedef int four_byte_var;

struct puntos
{
    four_byte_var coord_x;
    four_byte_var coord_y;
};

typedef struct type_puntos
{
    four_byte_var coord_x;
    four_byte_var coord_y;
}type_puntos;

//-------------------------//

union primera
{
    four_byte_var a;
    four_byte_var b;
};

typedef union segunda
{
    four_byte_var a;
    four_byte_var b;
}segunda;

//-------------------------//

int main()
{
    struct puntos punto_1;
    punto_1.coord_x = 15;
    punto_1.coord_y = 10;

    type_puntos type_punto_1;
    type_punto_1.coord_x = 5;
    type_punto_1.coord_y = 1;

    union primera x;
    x.a = 40;

    segunda y;
    y.a = 20;

    printf("\nTypdef me permite cambiar el nombre de un tipo de dato...\n");
    printf("La variable unsigned char ocupa %d byte\n", sizeof(unsigned char));
    printf("La variable one_bit_var ocupa %d byte\n", sizeof(one_byte_var));
    printf("La variable int ocupa %d bytes\n", sizeof(int));
    printf("La variable four_byte_var ocupa %d bytes\n\n", sizeof(four_byte_var));

    printf("La coord x de punto 1 de puntos = %d\n", punto_1.coord_x);
    printf("La coord y de punto 1 de puntos = %d\n", punto_1.coord_y);
    printf("La coord x de type_punto_1 de type_puntos = %d\n", type_punto_1.coord_x);
    printf("La coord y de type_punto_1 de type_puntos = %d\n\n", type_punto_1.coord_y);
    
    printf("a de x = %d\n", x.a);
    printf("b de x = %d\n", x.b);
    printf("a de y = %d\n", y.a);
    printf("b de y = %d\n\n", y.b);
    return 0;
}
