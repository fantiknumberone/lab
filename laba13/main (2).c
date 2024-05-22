#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"massive.h"
#include"sort.h"
int main()
{
    int n, choice, sortChoice;
    int C = 0, M = 0;

    printf("Введите размер массива n: ");
        // Используем цикл для надежного ввода n
    while (scanf("%d", &n) != 1 || n <= 0)
    {                                      // Проверяем, что введенное значение - положительное число
                while (getchar() != '\n'); // Очищаем буфер ввода
                printf("Ошибка: n должно быть целым положительным числом.\nВведите размер массива n: ");
           
    }

    int arr[n];

    printf("Выберите способ формирования массива (1 - случайные, 2 - убывание, 3 - возрастание): ");
    scanf("%d", &choice);
    generateArray(arr, n, choice);

    printf("Исходный массив:\n");
    printArray(arr, n);

    printf("Выберите метод сортировки (1 - Бинарное включение, 2 -метод Шелла, 3 - Шейкерная сорт.): ");
    scanf("%d", &sortChoice);

    switch (sortChoice)
    {
    case 1:
        binaryInsertionSort(arr, n, &C, &M);
        break;
    case 2:
        shellSort(arr, n, &C, &M);
        break;
    case 3:
        cocktailSort(arr, n, &C, &M);
        break;
    default:
        printf("Неверный выбор сортировки!\n");
        return -1;
    }

    printf("Отсортированный массив:\n");
    printArray(arr, n);

    printf("Количество сравнений: %d\n Количество перестановок: %d\n", C, M);

    return 0;
}
