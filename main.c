#include <stdio.h>
#include "calificaciones.h"   // Archivo de cabecera propio

int main()
{
    int n;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    float calificaciones[n][ASIGNATURAS];   // Matriz de calificaciones

    ingresarCalificaciones((float *)calificaciones, n);
    promedioEstudiante((float *)calificaciones, n);
    promedioAsignatura((float *)calificaciones, n);
    maxMinEstudiante((float *)calificaciones, n);
    maxMinAsignatura((float *)calificaciones, n);
    aprobadosReprobados((float *)calificaciones, n);

    return 0;
}

// ---- FUNCIONES CON PUNTEROS ----

// Ingreso y validacion de calificaciones
void ingresarCalificaciones(float *cal, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++)
        {
            do {
                printf("  Asignatura %d: ", j + 1);
                scanf("%f", (cal + i * ASIGNATURAS + j));  // Puntero para acceder a la matriz
                if (*(cal + i * ASIGNATURAS + j) < 0 || *(cal + i * ASIGNATURAS + j) > 10)
                    printf("  Error: debe estar entre 0 y 10\n");
            } while (*(cal + i * ASIGNATURAS + j) < 0 || *(cal + i * ASIGNATURAS + j) > 10);
        }
    }
}

// Promedio por estudiante
void promedioEstudiante(float *cal, int n)
{
    printf("\n--- PROMEDIO POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++)
    {
        float suma = 0;
        for (int j = 0; j < ASIGNATURAS; j++)
            suma += *(cal + i * ASIGNATURAS + j);
        printf("Estudiante %d -> Promedio: %.2f\n", i + 1, suma / ASIGNATURAS);
    }
}

// Promedio por asignatura
void promedioAsignatura(float *cal, int n)
{
    printf("\n--- PROMEDIO POR ASIGNATURA ---\n");
    for (int j = 0; j < ASIGNATURAS; j++)
    {
        float suma = 0;
        for (int i = 0; i < n; i++)
            suma += *(cal + i * ASIGNATURAS + j);
        printf("Asignatura %d -> Promedio: %.2f\n", j + 1, suma / n);
    }
}

// Max y min por estudiante
void maxMinEstudiante(float *cal, int n)
{
    printf("\n--- MAX Y MIN POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++)
    {
        float max = *(cal + i * ASIGNATURAS);
        float min = *(cal + i * ASIGNATURAS);
        for (int j = 1; j < ASIGNATURAS; j++)
        {
            if (*(cal + i * ASIGNATURAS + j) > max) max = *(cal + i * ASIGNATURAS + j);
            if (*(cal + i * ASIGNATURAS + j) < min) min = *(cal + i * ASIGNATURAS + j);
        }
        printf("Estudiante %d -> Max: %.2f | Min: %.2f\n", i + 1, max, min);
    }
}

// Max y min por asignatura
void maxMinAsignatura(float *cal, int n)
{
    printf("\n--- MAX Y MIN POR ASIGNATURA ---\n");
    for (int j = 0; j < ASIGNATURAS; j++)
    {
        float max = *(cal + j);
        float min = *(cal + j);
        for (int i = 1; i < n; i++)
        {
            if (*(cal + i * ASIGNATURAS + j) > max) max = *(cal + i * ASIGNATURAS + j);
            if (*(cal + i * ASIGNATURAS + j) < min) min = *(cal + i * ASIGNATURAS + j);
        }
        printf("Asignatura %d -> Max: %.2f | Min: %.2f\n", j + 1, max, min);
    }
}

// Aprobados y reprobados por asignatura
void aprobadosReprobados(float *cal, int n)
{
    printf("\n--- APROBADOS Y REPROBADOS POR ASIGNATURA ---\n");
    for (int j = 0; j < ASIGNATURAS; j++)
    {
        int aprobados = 0, reprobados = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(cal + i * ASIGNATURAS + j) >= 6) aprobados++;
            else reprobados++;
        }
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
               j + 1, aprobados, reprobados);
    }
}