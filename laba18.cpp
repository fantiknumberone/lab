#include <iostream>
#include <vector>
#include <algorithm>

class Serial {
public:
    int numEpisodes;
    double avgDuration;
    int avgActors;

    Serial(int numEpisodes, double avgDuration, int avgActors)
        : numEpisodes(numEpisodes), avgDuration(avgDuration), avgActors(avgActors) {}
};

// Функция для вывода информации о сериале
void printSerial(const Serial& serial) {
    std::cout << "Количество серий: " << serial.numEpisodes
              << ", Средняя продолжительность серии: " << serial.avgDuration
              << ", Среднее количество актёров в серии: " << serial.avgActors << std::endl;
}

// Критерий сортировки: длина серии (по убыванию)
bool compareSerials(const Serial &a, const Serial &b) {
    return a.avgDuration > b.avgDuration;
}

int main() {
    int initialSize, numEpisodes;
    double avgDuration;
    int avgActors;

    std::cout << "Введите количество сериалов: ";
    std::cin >> initialSize;

    std::vector<Serial> serials;
    for (int i = 0; i < initialSize; ++i) {
        std::cout << "Введите параметры для сериала " << i+1 << " (количество серий, средняя продолжительность серии, среднее количество актёров в серии): ";
        std::cin >> numEpisodes >> avgDuration >> avgActors;
        serials.emplace_back(numEpisodes, avgDuration, avgActors);
    }

    std::vector<Serial> filteredSerials;

    // Критерий для фильтрации: количество серий более 5
    for (const auto& serial : serials) {
        if (serial.numEpisodes > 5) {
            filteredSerials.push_back(serial);
        }
    }

    if (filteredSerials.empty()) {
        std::cout << "Новый вектор пуст." << std::endl;
    } else {
        std::cout << "Новый вектор не пуст. Сортируем..." << std::endl;
        std::sort(filteredSerials.begin(), filteredSerials.end(), compareSerials);

        std::cout << "Отсортированный список сериалов:" << std::endl;
        for (const auto& serial : filteredSerials) {
            printSerial(serial);
        }
    }

    return 0;
}