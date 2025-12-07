#include <iostream>
#include <string>
#include <array>

int main() {
    constexpr int n = 140;
    constexpr int m = 140;
    std::array<std::array<bool, n+2>, m+2> grid {};

    while (!std::cin.eof()) {
        for (int i = 1; i <= n; i++) {
            std::string input;
            std::cin >> input;
            for (int j = 1; j <= m; j++) {
                if (input[j-1] == '.') {
                    grid[i][j] = false;
                } else {
                    grid[i][j] = true;
                }
            }
        }
    }
    int sum {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            short count {};
            if (grid[i][j]) {
                if (grid[i+1][j+1]) count++;
                if (grid[i+1][j]) count++;
                if (grid[i+1][j-1]) count++;
                if (grid[i-1][j]) count++;
                if (grid[i-1][j-1]) count++;
                if (grid[i-1][j+1]) count++;
                if (grid[i][j+1]) count++;
                if (grid[i][j-1]) count++;
                if (count < 4) {
                    sum++;
                }
            }
        }
    }
    std::cout << sum << std::endl;
}