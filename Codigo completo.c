#include <stdio.h>
#include <string.h>

#define ASIGNATURAS 3

// ─── ESTRUCTURA ───────────────────────────────
struct Estudiante {
    char nombre[50];        // Nombre del estudiante
    float notas[ASIGNATURAS]; // Notas de cada asignatura
    float promedio;         // Promedio calculado
    float max;              // Nota más alta
    float min;              // Nota más baja
};

// ─── INGRESO Y VALIDACION ─────────────────────
void ingresarDatos(struct Estudiante *est, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNombre del estudiante %d: ", i + 1);
        scanf("%s", (est + i)->nombre);
        for (int j = 0; j < ASIGNATURAS; j++)
        {
            do {
                printf("  Asignatura %d: ", j + 1);
                scanf("%f", &(est + i)->notas[j]);
                if ((est + i)->notas[j] < 0 || (est + i)->notas[j] > 10)
                    printf("  Error: debe estar entre 0 y 10\n");
            } while ((est + i)->notas[j] < 0 || (est + i)->notas[j] > 10);
        }
    }
}

// ─── PROMEDIO POR ESTUDIANTE ──────────────────
void calcularPromedio(struct Estudiante *est, int n)
{
    printf("\n--- PROMEDIO POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++)
    {
        float suma = 0;
        for (int j = 0; j < ASIGNATURAS; j++)
            suma += (est + i)->notas[j];
        (est + i)->promedio = suma / ASIGNATURAS;
        printf("%s -> Promedio: %.2f\n", (est + i)->nombre, (est + i)->promedio);
    }
}

// ─── PROMEDIO POR ASIGNATURA ──────────────────
void promedioAsignatura(struct Estudiante *est, int n)
{
    printf("\n--- PROMEDIO POR ASIGNATURA ---\n");
    for (int j = 0; j < ASIGNATURAS; j++)
    {
        float suma = 0;
        for (int i = 0; i < n; i++)
            suma += (est + i)->notas[j];
        printf("Asignatura %d -> Promedio: %.2f\n", j + 1, suma / n);
    }
}

// ─── MAX Y MIN POR ESTUDIANTE ─────────────────
void calcularMaxMin(struct Estudiante *est, int n)
{
    printf("\n--- MAX Y MIN POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++)
    {
        (est + i)->max = (est + i)->notas[0];
        (est + i)->min = (est + i)->notas[0];
        for (int j = 1; j < ASIGNATURAS; j++)
        {
            if ((est + i)->notas[j] > (est + i)->max)
                (est + i)->max = (est + i)->notas[j];
            if ((est + i)->notas[j] < (est + i)->min)
                (est + i)->min = (est + i)->notas[j];
        }
        printf("%s -> Max: %.2f | Min: %.2f\n",
               (est + i)->nombre, (est + i)->max, (est + i)->min);
    }
}

// ─── APROBADOS Y REPROBADOS ───────────────────
void aprobadosReprobados(struct Estudiante *est, int n)
{
    printf("\n--- APROBADOS Y REPROBADOS ---\n");
    for (int i = 0; i < n; i++)
    {
        int aprobadas = 0, reprobadas = 0;
        for (int j = 0; j < ASIGNATURAS; j++)
        {
            if ((est + i)->notas[j] >= 6) aprobadas++;
            else reprobadas++;
        }
        printf("%s -> Aprobadas: %d | Reprobadas: %d\n",
               (est + i)->nombre, aprobadas, reprobadas);
    }
}

// ─── MAIN ─────────────────────────────────────
int main()
{
    int n;
    printf("=== SISTEMA DE GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    struct Estudiante estudiantes[n];

    ingresarDatos(estudiantes, n);
    calcularPromedio(estudiantes, n);
    promedioAsignatura(estudiantes, n);
    calcularMaxMin(estudiantes, n);
    aprobadosReprobados(estudiantes, n);

    printf("\nProceso finalizado.\n");
    return 0;
}