#include"sort.h"


void binaryInsertionSort(int *arr, int n, int *C, int *M)
{
    int left, right, mid, key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        left = 0;
        right = i;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            (*C)++;
            if (key < arr[mid])
                right = mid;
            else
                left = mid + 1;
        }
        for (j = i; j > left; j--)
        {
            arr[j] = arr[j - 1];
            (*M)++;
        }
        arr[j] = key;
        (*M)++;
    }
}
// сортировка методом Шелла
void shellSort(int *arr, int n, int *C, int *M)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                (*M)++;
                (*C)++;
            }
            arr[j] = temp;
            if (j != i)
            { // если перестановка произошла
                (*M)++;
            }
        }
    }
}
// Функция для шейкерной сортировки
void cocktailSort(int *arr, int n, int *C, int *M)
{
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    *C = 0; // Количество сравнений
    *M = 0; // Количество пересылок

    while (swapped)
    {
        swapped = 0;
        for (int i = start; i < end; ++i)
        {
            (*C)++;
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                (*M)++;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            (*C)++;
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                (*M)++;
            }
        }
        ++start;
    }
}