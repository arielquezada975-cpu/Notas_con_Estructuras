#include <stdio.h>
#include <string.h>
#define MAX_ESTUDIANTES 100

int main()
{
    int n;
    printf("=== SISTEMA DE GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    struct Estudiante estudiantes[n];

    ingresarDatos(estudiantes, n);
    calcularPromedio(estudiantes, n);
    calcularMaxMin(estudiantes, n);
    aprobadosReprobados(estudiantes, n);

    printf("\nProceso finalizado.\n");
    return 0;
}
