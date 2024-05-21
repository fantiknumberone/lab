#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения информации о рейсе
typedef struct {
    int raceNumber;
    int freeSeats;
} Aeroflot;

void createFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Не удалось создать файл");
        exit(EXIT_FAILURE);
    }

    // Заполняем файл примерными данными
    Aeroflot flights[] = {
        {101, 50},
        {202, 30},
        {303, 15},
        {404, 45},
        {505, 20}
    };

    for (int i = 0; i < sizeof(flights)/sizeof(Aeroflot); ++i) {
        fwrite(&flights[i], sizeof(Aeroflot), 1, file);
    }

    fclose(file);
}

void findFlight(const char *filename, int raceNumber) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    Aeroflot flight;
    int found = 0;

    while (fread(&flight, sizeof(Aeroflot), 1, file)) {
        if (flight.raceNumber == raceNumber) {
            printf("Рейс номер: %d, Свободных мест: %d\n", flight.raceNumber, flight.freeSeats);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Рейс с номером %d не найден.\n", raceNumber);
    }

    fclose(file);
}

int main() {
    const char *filename = "AEROFLOT.dat";

    // Создаем файл с данными
    createFile(filename);

    // Ввод номера рейса для поиска
    int raceNumber;
    printf("Введите номер рейса для поиска: ");
    scanf("%d", &raceNumber);

    // Ищем и выводим информацию о рейсе
    findFlight(filename, raceNumber);

    return 0;
}