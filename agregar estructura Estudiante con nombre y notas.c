#include <stdio.h>
#include <string.h>

#define ASIGNATURAS 3

// Estructura que agrupa los datos de cada estudiante
struct Estudiante {
    char nombre[50];
    float notas[ASIGNATURAS];
    float promedio;
    float max;
    float min;
};