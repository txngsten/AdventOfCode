#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::vector<long long> invalid;
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
            for (long long j {}; j < num.size()/2; j++) {
                pattern += num[j];
            }
            pattern += pattern;
            if (std::stoll(pattern) == i) {
                invalid.push_back(i);
            }
        }
    }
    for (int i {}; i < invalid.size(); i++) {
        sum += invalid[i];
    }
    std::cout << sum;
}