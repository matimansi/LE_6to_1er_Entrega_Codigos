_LE_6to_Ejemplo_Typedef_

## ¿Para que sirve typdef?

Typdef sirve para redefinir nuevos tipos de datos, es decir, reemplazar el nombre de un tipo de dato por otro.

## ¿Como es la sintaxis de typedef?

```c
typedef tipo_de_dato nuevo_tipo_de_dato
```

De manera que tipo_de_dato es el tipo de dato existente al que se desea crear un alias, como por ejemplo int, char o float y nuevo_tipo_de_dato es el nombre alternativo que se le desea asignar.

## Ejemplos

A continuacion, se representaran ejemplos de utilizacion de typedef.

### Tipo de variable: int 
Ejemplo de typedef en una variable int.

```c
typedef int four_byte_var;
```
De ahora en adelante, puedo crear variables de tipo int utilizando la palabra int o el nuevo nombre asignado, el cual es four_byte_var.

```c
int mi_var_1;
four_byte_var mi_var_2;
```

## Estructuras/Uniones

Si no uso typdef en una estructura/union, cada vez que quiera generar una varible de la estructura, deberemos usar la palabra struct/union, lo que genera un codigo menos legible y dificil de entender.

Si creamos una variable de una estructura sin typedef, lo hariamos de la siguiente manera:

```c
struct mi_estructura
{
    int campo_1;
    int campo_2;
};

int main()
{
    struct mi_estructura a;
}
```

En cambio, si utilizamos typedef, lo hariamos de la siguiente manera:

```c
typedef struct mi_estructura
{
    int campo_1;
    int campo_2;
}mi_estructura;

int main()
{
    mi_estructura a;
}
```

Lo mismo sucede en las uniones, si queremos crear una variable de una union sin typedef, lo hariamos de la siguiente manera:

```c
union mi_estructura
{
    int campo_1;
    int campo_2;
};

int main()
{
    union mi_estructura a;
}
```

En cambio, si utilizamos typedef, lo hariamos de la siguiente manera:

```c
typedef union mi_estructura
{
    int campo_1;
    int campo_2;
}mi_estructura;

int main()
{
    mi_estructura a;
}
```