#include <iostream>
#include <string>
#include <vector>

size_t depth = 0;
size_t width = 0;
int count = 0;

void traverse(int i, int j, std::vector<std::string>& matrix) {
    if (i == depth - 1) {
        return;
    }

    if (matrix[i][j] == '.') {
        traverse(i+1, j, matrix);
    } else {
        if (matrix[i][j] == '~') return;
        matrix[i][j] = '~';

        count++;
        traverse(i+1, j+1, matrix);
        traverse(i+1, j-1, matrix);
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

    int start = 0;
    for (int i {}; i < grid[0].size(); i++) {
        if (grid[0][i] == 'S') {
            start = i;
        }
    }
    traverse(1, start, grid);
    std::cout << count << std::endl;
}