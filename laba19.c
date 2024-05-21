#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrainNode {
    int number;                      // Номер поезда
    char destination[50];            // Станция назначения
    char departure_time[6];          // Время отправления (формат HH:MM)
    struct TrainNode* next;          // Указатель на следующий узел
} TrainNode;

void addTrain(TrainNode** head, int number, char* destination, char* departure_time) {
    TrainNode* new_train = (TrainNode*)malloc(sizeof(TrainNode));
    new_train->number = number;
    strncpy(new_train->destination, destination, 50);
    strncpy(new_train->departure_time, departure_time, 6);
    new_train->next = *head;
    *head = new_train;
}

void printAllTrains(TrainNode* head) {
    TrainNode* current = head;
    while (current != NULL) {
        printf("Номер: %d, Назначение: %s, Время отправления: %s\n",
               current->number, current->destination, current->departure_time);
        current = current->next;
    }
}

void findTrainByNumber(TrainNode* head, int number) {
    TrainNode* current = head;
    while (current != NULL) {
        if (current->number == number) {
            printf("Номер: %d, Назначение: %s, Время отправления: %s\n",
                   current->number, current->destination, current->departure_time);
            return;
        }
        current = current->next;
    }
    printf("Поезд с номером %d не найден.\n", number);
}

void findTrainsByDestination(TrainNode* head, char* destination) {
    TrainNode* current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->destination, destination) == 0) {
            printf("Номер: %d, Назначение: %s, Время отправления: %s\n",
                   current->number, current->destination, current->departure_time);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Поезда по направлению %s не найдены.\n", destination);
    }
}

int main() {
    TrainNode* head = NULL;
    int choice, number;
    char destination[50];
    char departure_time[6];

    while (1) {
        printf("\n1. Добавить поезд\n2. Показать все поезда\n3. Найти поезд по номеру\n4. Найти поезда по направлению\n5. Выйти\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите номер поезда: ");
                scanf("%d", &number);
                printf("Введите направление: ");
                scanf("%s", destination);
                printf("Введите время отправления (HH:MM): ");
                scanf("%s", departure_time);
                addTrain(&head, number, destination, departure_time);
                break;
            case 2:
                printAllTrains(head);
                break;
            case 3:
                printf("Введите номер поезда: ");
                scanf("%d", &number);
                findTrainByNumber(head, number);
                break;
            case 4:
                printf("Введите направление: ");
                scanf("%s", destination);
                findTrainsByDestination(head, destination);
                break;
            case 5:
                exit(0);
            default:
                printf("Неправильный выбор, попробуйте снова.\n");
        }
    }

    return 0;
}