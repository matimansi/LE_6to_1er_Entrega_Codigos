_LE_6to_Floating_Point_Campo_de_Bits_

# **IEEE 754 - Punto Flotante - Campo de Bits**
 
## ¿Que puedo hacer con el Programa?

Este programa te permite convertir numeros flotantes a *IEEE 754*.

## ¿Cuales son las formas de conversion?

Prodras convertir un **numero en especifico** o podras convertir la **suma**, **diferencia**, **producto** y/o **cociente** entre *2 numeros flotantes*.

## ¿En que sistemas de numeracion trabaja el programa?

Podras conocer la representacion IEEE 754 en el sistema **Hexadecimal** y **Binario**.

# Concepto de funcionamiento

En este codigo se utiliza un campo de bits para poder representar el formato IEEE 754 en base Binaria y Hexadecimal. Basicamente el campo de bits esta formado por una estructura, cada campo de dicha estructura tiene una cantidad de bits asigandos, los cuales respetan la cantidad de bits del signo, exponente y mantisa del formato IEEE 754. Al colocar el campo de bits dentro de una union con una varible tipo float, logramos que al escribir en la variable tipo float, los bits leidos se "dividan" o "distribuyan" en cada uno de los campos. Si lo pensamos con embudos y lluvia, podemos decir que la lluvia es el numero flotante ingresado, dicha lluvia posee 32 gotas o 32 bits, los cuales caen hacia unos embudos de distintos tamaños, en uno solo entra 1 gota o 1 bit (Signo), en el otro entran 8 gotas o 8 bits (Exponente) y en el ultimo entran 23 gotas o 23 bits (Mantisa). De esta manera, podemos acceder a cada embudo o campo de la estructura para poder imprimir las partes del formato IEEE 754 o directamente imprimir la estructura.