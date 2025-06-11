#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

void printVector(const std::vector<int>& vec) {
    std::cout << "Вектор: ";

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}

void CheckAndPrintResult(const int& sumLeft, const int& sumRight, const std::vector<int>& vec) {
    assert(sumLeft <= 0 && "А должно было быть меньше 0, думай лучше");
    assert(sumRight >= 0 && "А должно было быть больше 0, думай лучше");

    printVector(vec);

    std::cout << "Сумма слева: " << sumLeft << "\n";
    std::cout << "Сумма справа: " << sumRight << "\n";
}

void processVector(std::vector<int>& vec) {
    auto comp = [](int x) { return x < 0; };
    auto middle = std::partition(vec.begin(), vec.end(),comp);

    std::sort(middle, vec.end());

    int sumLeft = std::accumulate(vec.begin(), middle, 0);
    int sumRight = std::accumulate(middle, vec.end(), 0);

    CheckAndPrintResult(sumLeft, sumRight, vec);
}

int main() {
    std::vector<int> numbers = {4, -2, 0, -1, 3, -5, 7, 0, -3};
    processVector(numbers);

    return 0;
}
