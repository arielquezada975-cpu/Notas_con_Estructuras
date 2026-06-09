
void ingresarCalificaciones(float *cal, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++)
        {
            do {
                printf("  Asignatura %d: ", j + 1);
                scanf("%f", (cal + i * ASIGNATURAS + j));
                if (*(cal + i * ASIGNATURAS + j) < 0 || *(cal + i * ASIGNATURAS + j) > 10)
                    printf("  Error: debe estar entre 0 y 10\n");
            } while (*(cal + i * ASIGNATURAS + j) < 0 || *(cal + i * ASIGNATURAS + j) > 10);
        }
    }
}

