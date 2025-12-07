#include <iostream>
#include <string>
#include <array>
#include <vector>

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
    int total {};
    std::vector<std::pair<int, int>> pairs;
    bool cond = true;
    while (cond) {
        int sum {};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j]) {
                    short count {};
                    if (grid[i+1][j+1]) count++;
                    if (grid[i+1][j]) count++;
                    if (grid[i+1][j-1]) count++;
                    if (grid[i-1][j]) count++;
                    if (grid[i-1][j-1]) count++;
                    if (grid[i-1][j+1]) count++;
                    if (grid[i][j+1]) count++;
                    if (grid[i][j-1]) count++;
                    if (count < 4) {
                        std::pair<int, int> removed;
                        removed.first = i;
                        removed.second = j;
                        pairs.push_back(removed);
                        sum++;
                    }
                }
            }
        }
        total += sum;
        for (int i {}; i < pairs.size(); i++) {
            int x = pairs[i].first;
            int y = pairs[i].second;
            grid[x][y] = false;
        }
        if (sum <= 0) {
            cond = false;
        }
    }
    std::cout << total << std::endl;
}