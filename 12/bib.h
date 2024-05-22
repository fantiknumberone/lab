// bib.h
#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    float x0; // Центр окружности по оси X
    float y0; // Центр окружности по оси Y
    float R;  // Радиус окружности
} Circle;

// Прототипы функций
void inputCircles(Circle *circles, int n);
void computeAndPrintCircleInfo(Circle *circles, int n);

#endif