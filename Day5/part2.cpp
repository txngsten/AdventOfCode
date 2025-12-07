#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::vector<std::pair<long long, long long>> ranges;
    std::string input;

    while (!std::cin.eof()) {
        std::getline(std::cin, input);

        if (input.empty()) {
            break;
        }

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
    std::sort(ranges.begin(), ranges.end());
    std::pair<long long, long long> union_range;

    union_range.first = ranges[0].first;
    union_range.second = ranges[0].second;

    long long length {};

    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i].first <= union_range.second + 1) {
            union_range.first = std::min(union_range.first, ranges[i].first);
            union_range.second = std::max(union_range.second, ranges[i].second);
        } else {
            length += union_range.second - union_range.first + 1;
            union_range.first = ranges[i].first;
            union_range.second = ranges[i].second;
        }
    }
    length += union_range.second - union_range.first + 1;
    std::cout << length << std::endl;
}