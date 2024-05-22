#include <stdio.h>
#include <math.h>

double series_sum(double x, double precision, int n) {
    if (fabs(pow(x-1,n)/n) < precision) {
        return pow(-1,n+1)*pow(x-1,n)/n;
    }
    return pow(-1,n+1)*pow(x-1,n)/n + series_sum(x, precision, n+1);
}

int main() {
    double x = 1.5; // значение x, для которого вычисляем ln(x)
    double precision = 1e-3; // точность
    int count = 1;
    double series_value = series_sum(x, precision, count);
    double math_value = log(x);

    printf("Значение ln(%.2f) с точностью %.3f: %f\n", x, precision, series_value);
    printf("Число членов ряда, вошедших в сумму: %d\n", count);
    printf("Значение ln(%.2f) из библиотеки math.h: %f\n", x, math_value);

    return 0;
}