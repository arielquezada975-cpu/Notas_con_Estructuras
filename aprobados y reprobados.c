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
