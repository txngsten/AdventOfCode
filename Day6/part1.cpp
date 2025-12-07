#include <iostream>
#include <string>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

int main() {
    std::vector<std::vector<int>> grid(4);
    std::vector<char> operations;

    for (int i {}; i < 5; i++) {
        if (i == 4) {
            std::string input;
            std::getline(std::cin, input);
            for (char c: input) {
                if (c != ' ') {
                    operations.push_back(c);
                }
            }
        }
        std::string input;
        std::getline(std::cin,input);
        std::string curr;
        for (int k {}; k < input.size(); k++) {
            if (input[k] != ' ') {
                curr += input[k];
            } else if (!curr.empty()) {
                grid[i].push_back(std::stoi(curr));
                curr.clear();
            }
        }
        if (!curr.empty()) {
            grid[i].push_back(std::stoi(curr));
        }
    }
    cpp_int sum {};

    for (int i {}; i < grid[0].size(); i++) {
        if (operations[i] == '+') {
            sum += cpp_int(grid[0][i]) + cpp_int(grid[1][i]) + cpp_int(grid[2][i]) + cpp_int(grid[3][i]);
        } else {
            sum += cpp_int(grid[0][i]) * cpp_int(grid[1][i]) * cpp_int(grid[2][i]) * cpp_int(grid[3][i]);
        }
    }
    std::cout << sum << std::endl;
}