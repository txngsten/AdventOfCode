#include <iostream>
#include <string>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

int main() {
    std::vector<char> operations;
    std::vector<std::string> inputs;

    for (int i {}; i < 5; i++) {
        if (i == 4) {
            std::string input;
            std::getline(std::cin, input);
            for (char c: input) {
                if (c != ' ') {
                    operations.push_back(c);
                }
            }
        } else {
            std::string input;
            std::getline(std::cin,input);
            inputs.push_back(input);
        }
    }
    cpp_int sum;
    cpp_int curr_sum;
    for (int i = static_cast<int>(inputs[2].size()-1); i >= 0; i--) {
        if (inputs[0][i] != ' ' || inputs[1][i] != ' ' || inputs[2][i] != ' ' || inputs[3][i] != ' ') {
            std::string num;
            if (inputs[0][i] != ' ') num += inputs[0][i];
            if (inputs[1][i] != ' ') num += inputs[1][i];
            if (inputs[2][i] != ' ') num += inputs[2][i];
            if (inputs[3][i] != ' ') num += inputs[3][i];

            cpp_int digit;
            digit.assign(num);
            if (operations.back() == '+') {
                curr_sum += digit;
            } else {
                if (curr_sum == 0) {
                    curr_sum = digit;
                } else {
                    curr_sum *= digit;
                }
            }
        } else {
            sum += curr_sum;
            curr_sum = 0;
            operations.pop_back();
        }
    }
    sum += curr_sum;
    std::cout << sum << std::endl;
}