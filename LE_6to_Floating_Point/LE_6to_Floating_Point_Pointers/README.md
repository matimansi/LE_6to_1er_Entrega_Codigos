_LE_6to_Floating_Point_Pointers_

# **IEEE 754 - Punto Flotante - Pointers**
 
## ¿Que puedo hacer con el Programa?

Este programa te permite convertir numeros flotantes a *IEEE 754*.

## ¿Cuales son las formas de conversion?

Prodras convertir un **numero en especifico** o podras convertir la **suma**, **diferencia**, **producto** y/o **cociente** entre *2 numeros flotantes*.

## ¿En que sistemas de numeracion trabaja el programa?

Podras conocer la representacion IEEE 754 en el sistema **Hexadecimal** y **Binario**.

# Concepto de funcionamiento

En este codigo se utiliza un puntero para poder representar el formato IEEE 754 en base Binaria. Basicamente tenemos una variable tipo float, la cual como ya sabemos ocupa 4 bytes, y un puntero de tipo one_byte_var (redefinicion de unsined char), 1 byte, que apunta a la variable tipo float, de esta manera, al imprimir por primera vez el contenido del puntero, podremos observar el primer byte del numero flotante, es decir, 2 digitos hexadecimales que son 8 bits bianrios lo que corresponde a 1 byte. Ahora bien, para poder ver el siguiente byte, tan solo tenemos que sumarle una unidad de datos al puntero, es decir, a puntar a siguiente byte, y asi sucesivamente.