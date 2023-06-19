_LE_6to_Ejemplo_Struct_

## ¿Que es una estructura?

Una estructura es un tipo de dato el cual permite almacenar diferentes tipos de datos bajo un mismo nombre, cada uno de estos se denominan campos.

## ¿Para que sirve?

Este tipo de dato nos sirve para encapsualar y vincular informacion.

## ¿Como se declara una estructura?

La declaracion de una estructura no genera codigo, debido a que la estructura no fue asiganada a ninguna variable.

```c
#include <stdio.h>

struct nombre
{
    int campo_1;
    int campo_2;
    int campo_x;
};
```

## ¿Como generar variables de nuestra estructura?

La generacion de una variable de la estructura si genera codigo. Podemos generar variables locales como globales. Ademas, dichas variables pueden ser vectores.

*Global:*

```c
#include <stdio.h>

struct nombre
{
    int campo_1;
    int campo_2;
    int campo_x;
}mi_struct;
```

*Local:*

```C
int main()
{
    struct nombre mi_struct;
}
```

*Vector Global:*

```c
#include <stdio.h>

struct nombre
{
    int campo_1;
    int campo_2;
    int campo_x;
}mi_struct[2];
```

*Vector Local:*

```C
int main()
{
    struct nombre mi_struct[2];
}
```

## ¿Como se trabaja con los campos de una estructura?

Para trabajar con los campos de una estructura se utiliza el operador punto [ . ]

```c
#include <stdio.h>

struct nombre
{
    int campo_1;
    int campo_2;
    int campo_x;
};

int main()
{
    struct nombre mi_struct;

    mi_struct.campo_1 = 10;
    mi_struct.campo_2 = 5;

    printf("Campo_1 = %d\n", mi_struct.campo_1);
    printf("Campo_2 = %d", mi_struct.campo_2);
}
```
*Si la variable fuese un vector:*
```c
#include <stdio.h>

struct nombre
{
    int campo_1;
    int campo_2;
    int campo_x;
};

int main()
{
    struct nombre mi_struct[2];

    mi_struct[0].campo_1 = 15;
    mi_struct[0].campo_2 = 10;
    mi_struct[1].campo_1 = 5;
    mi_struct[1].campo_2 = 1;

    printf("Campo_1 en posicion 0 = %d\n", mi_struct[0].campo_1);
    printf("Campo_2 en posicion 0 = %d\n", mi_struct[0].campo_2);
    printf("Campo_1 en posicion 1 = %d\n", mi_struct[1].campo_1);
    printf("Campo_2 en posicion 1 = %d", mi_struct[1].campo_2);
}
```

