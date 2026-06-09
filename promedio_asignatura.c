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
