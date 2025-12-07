#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<long long> invalid;
    long long sum = 0;

    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string range;

    while (std::getline(ss, range, ',')) {
        std::stringstream rs(range);
        std::string a, b;
        std::getline(rs, a, '-');
        std::getline(rs, b, '-');

        long long left  = std::stoll(a);
        long long right = std::stoll(b);

        for (long long i = left; i <= right; i++) {
            std::string num = std::to_string(i);
            if (num.size() < 2) {
                continue;
            }
            std::string pattern;
            for (int j = 1; j <= num.size()/2; j++) {
                std::string test_pattern;
                pattern = num.substr(0, j);

                while (test_pattern.size() < num.size()) {
                    test_pattern += pattern;
                }
                if (std::stoll(test_pattern) == i) {
                    invalid.insert(i);
                }
            }
        }
    }
    for (long long value: invalid) {
        sum += value;
    }
    std::cout << sum;
}
