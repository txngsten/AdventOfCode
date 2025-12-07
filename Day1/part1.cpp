#include <iostream>

int main() {
    std::string input;
    int dial = 50;
    int count = 0;
    int range = 4432;

    for (int i {}; i < range; i++) {
        std::cin >> input;
        char rotation_type = input[0];
        int value = std::stoi(input.substr(1));

        if (rotation_type == 'L') {
            dial -= value;
        } else {
            dial += value;
        }

        dial %= 100;

        if (dial == 0) {
            count++;
        }
    }
    std::cout << count;
}