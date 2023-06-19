_LE_6to_Floating_Point_

# **IEEE 754 - Punto Flotante**
 
## ¿Que puedo hacer con el Programa?

Este programa te permite convertir numeros flotantes a *IEEE 754*.

## ¿Cuales son las formas de conversion?

Prodras convertir un **numero en especifico** o podras convertir la **suma**, **diferencia**, **producto** y/o **cociente** entre *2 numeros flotantes*.

## ¿En que sistemas de numeracion trabaja el programa?

Podras conocer la representacion IEEE 754 en el sistema **Hexadecimal** y **Binario**.

# Concepto de Funcionamiento

En este codigo se utiliza una union para poder representar el formato IEEE 754 en base Binaria. Basicamente tenemos una union que contiene una variable float, que ocupa 4 bytes, y un vector de 4 posiciones de tipo one_byte_var (redefinicion de unsigned char) que cada posicion ocupa 1 byte, es decir, 4 bytes en total. De esta manera, el dato que se escriba en la varaible tipo float, se sobreescribira en cada posicion del vector, debido al funcionamiento de la union. De esta manera, podemos acceder a cada una de las 4 posiciones del vector obteniendo 2 digitos hexadecimales, que son 8 bits binarios que corresponden a 1 byte del numero flotante.