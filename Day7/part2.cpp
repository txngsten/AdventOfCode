#include <iostream>
#include <string>
#include <vector>

size_t depth = 0;
size_t width = 0;

long long traverse(int i, int j, const std::vector<std::string>& matrix, std::vector<std::vector<long long>>& memo) {
    if (i == depth -1) {
        return 1;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (matrix[i][j] == '.') {
        memo[i][j] = traverse(i+1, j, matrix, memo);
        return memo[i][j];
    }

    if (matrix[i][j] == '^') {
        memo[i][j] = traverse(i+1, j+1, matrix, memo) + traverse(i+1, j-1, matrix, memo);
        return memo[i][j];
    }
}

int main() {
    std::vector<std::string> grid;

    while (!std::cin.eof()) {
        std::string input;
        std::cin >> input;
        grid.push_back(input);
        depth++;
    }
    width = grid[0].size();
    std::vector<std::vector<long long>> memo(depth, std::vector<long long>(width, -1));

    int start = 0;
    for (int i {}; i < grid[0].size(); i++) {
        if (grid[0][i] == 'S') {
            start = i;
        }
    }
    long long count = traverse(1, start, grid, memo);
    std::cout << count << std::endl;
}