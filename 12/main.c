// main.c
#include "bib.h"

int main() {
    int n;
    printf("Введите количество окружностей: ");
    scanf("%d", &n);
    
    Circle *circles = malloc(n * sizeof(Circle));
    
    inputCircles(circles, n);
    computeAndPrintCircleInfo(circles, n);
    
    free(circles);
    
    return 0;
}