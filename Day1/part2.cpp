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

        count += value / 100;
        value %= 100;

        if (rotation_type == 'L') {
            if (dial == 0) dial += 100;
            dial -= value;
        } else {
            dial += value;
        }

        if (dial <= 0 || dial >= 100) {
            count++;
        }
        dial %= 100;
        if (dial < 0) dial += 100;
    }
    std::cout << count;
}