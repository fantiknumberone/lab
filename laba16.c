#include <stdio.h>
#include <stdlib.h>

// Определение структуры элемента списка.
typedef struct Node {
    int data;            // Информационное поле.
    struct Node* link1;  // Ссылка на элемент другого списка.
    struct Node* link2;  // Ссылка на следующий элемент в текущем списке.
} Node;

// Функция создания нового элемента списка.
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->link1 = NULL;
    newNode->link2 = NULL;
    return newNode;
}

// Функция вывода списка.
void printList(Node* head, const char* listName) {
    printf("Список %s: ", listName);
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link2;
    }
    printf("NULL\n");
}

int main() {
    Node* list1 = NULL;  // Голова первого списка.
    Node* list2 = NULL;  // Голова второго списка.
    Node* tail1 = NULL;  // Хвост первого списка, чтобы добавлять элементы в конец.
    Node* tail2 = NULL;  // Хвост второго списка, чтобы добавлять элементы в конец.

    int count = 0;  // Для подсчета количества введенных чисел.
    int input;
    
    printf("Введите последовательность целых чисел (0 для завершения ввода):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }

        Node* newNode = createNode(input);

        // Чередуем списки.
        if (count % 2 == 0) {  // Четное количество введенных чисел.
            if (list1 == NULL) {  // Если первый список еще пуст.
                list1 = newNode;
                tail1 = newNode;
            } else {
                tail1->link2 = newNode;
                tail1 = newNode;
            }
        } else {  // Нечетное количество введенных чисел.
            if (list2 == NULL) {  // Если второй список еще пуст.
                list2 = newNode;
                tail2 = newNode;
            } else {
                tail2->link2 = newNode;
                tail2 = newNode;
            }
        }
        
        count++;
    }

    // Устанавливаем ссылку между списками.
    Node* temp1 = list1;
    Node* temp2 = list2;
    while (temp1 != NULL && temp2 != NULL) {
        temp1->link1 = temp2;
        temp1 = temp1->link2;
        temp2 = temp2->link2;
    }

    // Выводим списки.
    printList(list1, "1");
    printList(list2, "2");

    // Освобождаем память.
    while (list1 != NULL) {
        Node* temp = list1;
        list1 = list1->link2;
        free(temp);
    }
    while (list2 != NULL) {
        Node* temp = list2;
        list2 = list2->link2;
        free(temp);
    }

    return 0;
}