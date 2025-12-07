#include <iostream>
#include <vector>

int main() {
    std::vector<int> voltage;
    int sum = 0;
    std::string input;

    while (!std::cin.eof()) {
        std::cin >> input;
        std::pair<int, int> best;
        int index = -1;

        best.first = 0;
        best.second = 0;

        for (int i {}; i < input.size() - 1; i++) {
            if (input[i] - '0' > best.first) {
                best.first = input[i] - '0';
                index = i;
            }
        }
        for (int i = index; i < input.size(); i++) {
            if (input[i] - '0' > best.second && i != index) {
                best.second = input[i] - '0';
            }
        }
        std::string best_voltage;
        best_voltage += std::to_string(best.first);
        best_voltage += std::to_string(best.second);
        voltage.push_back(std::stoi(best_voltage));
    }
    for (int i {}; i < voltage.size(); i++) {
        sum += voltage[i];
    }
    std::cout << sum;
}