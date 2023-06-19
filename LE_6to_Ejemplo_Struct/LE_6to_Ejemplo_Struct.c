
#include <stdio.h>
#define LIM 30
#define CANT 5

void print_info (int);
void input_info (int);

struct info
{
    char nombre[LIM];
    char apellido[LIM];
    int edad;
    int dni;
    char localidad[LIM];
};

struct info alumno[CANT];

int main()
{
    char decision;
    int alumno;
    printf("\nBienvenido a mi programa...\n");
    do
    {
        printf("\nCant. de Alumnos: %d\n", CANT);
        printf("Que desea hacer?\n");
        printf("\t- INGRESAR informacion [I]\n\t- VER informacion [V]\n>>> ");
        fflush(stdin);
        scanf("%c", &decision);
        printf("\nIngrese un N de Alumno\n>>> ");
        scanf("%d", &alumno);
        alumno--;
        if ((decision == 'I') || (decision == 'i')) input_info(alumno);
        if ((decision == 'V') || (decision == 'v')) print_info(alumno);
    }while (1);
    return 0;
}

void input_info (int num)
{
    printf("\n\tAlumno Numero %d\n", num + 1);
    printf("Ingrese el nombre del alumno\n>>> ");
    scanf("%s", alumno[num].nombre);
    fflush(stdin);
    printf("Ingrese el apellido del alumno\n>>> ");
    scanf("%s", alumno[num].apellido);
    fflush(stdin);
    printf("Ingrese la edad del alumno\n>>> ");
    scanf("%d", &alumno[num].edad);
    fflush(stdin);
    printf("Ingrese el D.N.I. del alumno (sin puntos)\n>>> ");
    scanf("%d", &alumno[num].dni);
    fflush(stdin);
    printf("Ingrese la localidad del alumno\n>>> ");
    scanf("%s", alumno[num].localidad);
    fflush(stdin);
}

void print_info (int num)
{
    printf("\n\tAlumno Numero %d\n", num + 1);
    printf("Nombre: %s\n", alumno[num].nombre);
    printf("Apellido: %s\n", alumno[num].apellido);
    printf("Edad: %d\n", alumno[num].edad);
    printf("D.N.I.: %d\n", alumno[num].dni);
    printf("Localidad: %s\n", alumno[num].localidad);
}
