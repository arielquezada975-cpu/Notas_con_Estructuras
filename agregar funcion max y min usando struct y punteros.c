#include <stdio.h>
#include <string.h>

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