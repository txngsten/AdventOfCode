#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::vector<std::pair<long long, long long>> ranges;
    std::vector<long long> values;
    std::string input;

    bool next_part = false;
    while (!std::cin.eof()) {
        std::getline(std::cin, input);

        if (input.empty()) {
            next_part = true;
            continue;
        }

        if (next_part) {
            values.push_back(std::stoll(input));
        } else {
            std::pair<long long, long long> range_vals;
            int i {};
            std::string low;

            while (input[i] != '-') {
                low += input[i];
                i++;
            }
            std::string high = input.substr(i+1, input.length()-i);

            range_vals.first = std::stoll(low);
            range_vals.second = std::stoll(high);
            ranges.push_back(range_vals);
        }
    }
    int count {};

    for (int i {}; i < values.size(); i++) {
        for (int j {}; j < ranges.size(); j++) {
            if (!(values[i] < ranges[j].first || values[i] > ranges[j].second)) {
                count++;
                break;
            }
        }
    }
    std::cout << count << std::endl;
}