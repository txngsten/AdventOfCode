#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<long long> voltage;
    long long sum = 0;
    std::string input;

    while (!std::cin.eof()) {
        std::cin >> input;
        std::string current;
        std::unordered_set<int> used_index;

        int count = 0;
        int index = 0;
        while (count < 12) {
            int best = -1;
            for (int i = index; i < input.size() - 11 + count; i++) {
                if (input[i] - '0' > best && used_index.find(i) == used_index.end()) {
                    best = input[i] - '0';
                    index = i;
                }
            }
            used_index.insert(index);
            current += std::to_string(best);
            count++;
        }
        voltage.push_back(std::stoll(current));
    }
    for (int i {}; i < voltage.size(); i++) {
        sum += voltage[i];
    }
    std::cout << sum ;
}