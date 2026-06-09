#ifndef CALIFICACIONES_H
#define CALIFICACIONES_H

// Constante de asignaturas
#define ASIGNATURAS 3

// Declaracion de funciones con punteros
void ingresarCalificaciones(float *calificaciones, int n);
void promedioEstudiante(float *calificaciones, int n);
void promedioAsignatura(float *calificaciones, int n);
void maxMinEstudiante(float *calificaciones, int n);
void maxMinAsignatura(float *calificaciones, int n);
void aprobadosReprobados(float *calificaciones, int n);

#endif
