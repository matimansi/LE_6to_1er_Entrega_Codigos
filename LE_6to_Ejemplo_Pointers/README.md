_LE_6to_Ejemplo_Punteros_

## ¿Que es un puntero?

Un puntero es un tipo de variable que contiene una dirección y que nos otorga la posibilidad de trabajar con la dirección tanto como con el contenido de dicha posición (apuntada)

## ¿Como se declara un puntero?

La sintaxis para declarar un puntero es la siguiente:

tipo * nombre_del_puntero

En donde tipo se refiere sl tipo de dato al que apuntara el puntero.

Por ejemplo, si queremos crear una variable que apunte a una variable de tipo int, escribimos lo siguiente:
```c
int *puntero_a_char;
```
Siempre que se crea un puntero, debemos darle una variable para que la apunte, ya que es peligroso que un puntero apunte a una direccion de memoria aleatoria. Para hacer esto, existen 2 formas.

-  Crear una variable y un puntero que apunte a dicha variable.
```c
int var;
int *puntero = &var;
```
-  Crear el puntero y que no apunte a nada.
```c
int *puntero = NULL;
```

## Operador Ampersand [ **&** ] 

El operador **&** obtiene la dirección de la variable que está al lado. Lo utilizamos anteriormente cuando le asignamos al puntero la dirección de la variable var. Tambien lo utilizamos cuando usamos el _scanf()_ y le damos como parámetro la dirección donde se encuentra la variable para que almacene lo que se ingrese.

## Operador Asterisco [ __*__ ] 

El operador * utilizado junto a una variable del tipo puntero devuelve el contenido de la variable apuntada por dicho puntero.

```c
int var;
int *puntero = &var;
printf("%d", *puntero);
```
Si no lo utilizamos, nos devuelve la direccion de memoria de var

```c
int var;
int *puntero = &var;
printf("%d", puntero);
```
Es decir, que el operador __*__ nos permite trabajar con el contenido de la variable a la que apunta var, y si no lo utilizamos, estaremos trabajando con el contenido del puntero, el cual contiene la direccion de la variable apuntada.

## Aritmetica de los Punteros

Los punteros son variables, entonces pueden incrementarse, decrementarse, sumarse, etc.
Cuando hacemos lo siguiente:

```c
int var;
int *puntero = &var;
puntero++;
```
El puntero se incrementa 4 bytes. Esto sucede ya que se incrementa de acuerdo a que tipo es, si fuese un puntero de tipo char, se incrementaria 1 Byte.

En Cambio si hacemos lo siguiente:

```c
int var;
int x;
int *puntero = &var;
x = *(puntero++);
```
Recordemos que se esta ejecutando un post incremento, por lo tanto la sintaxis *(puntero++) es una abreviatura de *puntero, seguida de la operación puntero++. Por lo tanto, lo que hacemos con esas lineas de codigo es asignar a la variable x el valor del contenido de la variable a la que apunta puntero, y luego incrementamos el valor de puntero en una unidad, es decir 4 bytes.

## Punteros Indexados

Los punteros indexados nos otorgan la capacidad de acceder a un elemento de un vector utilizando un puntero y un indice, entonces, si existe un vector y un puntero que apunta a la direccion de memoria del primer elemento del vector, se puede acceder a los elementos del arreglo sumando o restando un indice al puntero.

Por ejemplo:

```c
int vector[4] = {1, 2, 3, 4};
int *puntero = &vector[0];
```
Para acceder a el primer elemento del vector
```c
int x = *puntero;
```
Ya que inicialmente el puntero apunta al primer elemento. Y si queremos acceder al contenido en el indice 2, escribimos lo siguiente:
```c
x = *(puntero + 2);
```
Tambien, podemos usar los corchetes [ ] para acceder a los elementos del vector a traves del puntero. En el siguiente caso, accederemos al ultimo elemento del vector:
```c
x = puntero[3];
```

_En conlusion, lo punteros indexados son una forma conveniente y eficiente de acceder a los elementos de un vector._

# Pasaje por Valor y por Referencia

Cuando utilizamos funciones que reciben al menos 1 argumento, por ejemplo, la siguiente:

```c
#include <stdio.h>

void pasaje_valor (int);

int main()
{
    int x = 10;
    pasaje_valor(x);
    printf("%d\n", x);
    return 0;
}

void pasaje_valor (int x)
{
    x++;
    printf("%d\n", x);
}
```

Lo que sucede es que la funcion copia el valor de la variable x, crea una nueva variable tipo entero llamada x y pega el valor copiado, de esta manera obtenemos 2 variables con el **mismo nombre** que **NO poseen el mismo contenido**, ya que cada una de estas es una variable local de cada funcion, una del _main()_ y la otra de *pasaje_valor*(), por esta razon, al imprimir los valores de x en la funcion _main()_ y *pasaje_valor()* obtenemos 10 y 11 respectivamente.

Dicho proceso se denomina **Pasaje por Valor**.

¿Pero como hacemos para modificar la variable original, es decir, la variable x de la funcion _main()_?

Para esto utilizamos los punteros.

```c
#include <stdio.h>

void pasaje_referencia (int *);

int main()
{
    int x = 10;
    int *puntero_x = &x;
    pasaje_referencia(puntero_x);
    printf("%d", x);
    return 0;
}

void pasaje_referencia (int *puntero_x)
{
    (*puntero_x)++;
    printf("%d\n", *puntero_x);
}
```
De esta manera el puntero_x almacena la direccion de memoria de x, y al usarlo como argumento en una funcion lo que sucede es que la funcion *pasaje_referencia()* copia el contenido del arguemnto, es decir, el contenido de puntero_x que es la direccion de memoria de x, crea una variable llamada puntero_x y pega lo copiado, de esta manera, tenemos 2 punteros distintos, ya que son locales (uno de la funcion _main()_ y el otro de la funcion *pasaje_referencia()*) los cuales apuntan a la misma direccion de memoria, es decir, los dos apuntan a x. Entonces, como en la funcion *pasaje_referencia()* se incrementea en 1 el contenido de puntero_x, el contenido de x se incrementara en 1. Por esta razon, al imprimir los valores de x en la funcion _main()_ y *pasaje_valor()* obtenemos la misma salida, es decir, 11.
