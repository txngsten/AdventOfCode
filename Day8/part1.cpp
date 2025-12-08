#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

int find(int x, std::vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void merge(int x, int y, std::vector<int>& parent, std::vector<int>& size) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (size[rootY] > size[rootX]) {
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
    } else {
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

struct point {
    int x;
    int y;
    int z;
};

struct edge {
    int i;
    int j;
    long long d;
};

bool compare_edge(const edge& a, const edge& b) {
    return a.d < b.d;
}

int main() {
    std::vector<point> boxes;

    while (!std::cin.eof()) {
        std::string input;
        std::cin >> input;

        point curr {};
        std::string temp;
        int helper {};
        for (char c: input) {
            if (c == ',') {
                if (helper == 0) {
                    curr.x = std::stoi(temp);
                    temp.clear();
                }
                if (helper == 1) {
                    curr.y = std::stoi(temp);
                    temp.clear();
                }
                helper++;
            } else {
                temp += c;
            }
        }
        curr.z = std::stoi(temp);
        boxes.push_back(curr);
    }
    std::vector<edge> distances;

    for (int i {}; i < boxes.size(); i++) {
        for (int j = i+1; j < boxes.size(); j++) {
            int x_1 = boxes[i].x;
            int y_1 = boxes[i].y;
            int z_1 = boxes[i].z;

            int x_2 = boxes[j].x;
            int y_2 = boxes[j].y;
            int z_2 = boxes[j].z;

            auto dx = static_cast<long long>(x_1 - x_2);
            auto dy = static_cast<long long>(y_1 - y_2);
            auto dz = static_cast<long long>(z_1 - z_2);

            dx *= dx;
            dy *= dy;
            dz *= dz;

            long long distance = dx + dy + dz;

            edge curr {};
            curr.i = i;
            curr.j = j;
            curr.d = distance;
            distances.push_back(curr);
        }
    }
    std::sort(distances.begin(), distances.end(), compare_edge);

    std::vector<int> parent(boxes.size());
    std::vector<int> sizes(boxes.size(), 1);

    for (int i {}; i < parent.size(); i++) {
        parent[i] = i;
    }

    int connected = 0;

    for (const auto& d: distances) {
        if (connected == 1000) break;

        if (find(parent[d.i], parent) != find(parent[d.j], parent)) {
            merge(d.i, d.j, parent, sizes);
        }
        connected++;
    }

    std::vector<int> comp_sizes;
    for (int i = 0; i < parent.size(); ++i) {
        if (parent[i] == i) {
            comp_sizes.push_back(sizes[i]);
        }
    }

    std::sort(comp_sizes.begin(), comp_sizes.end(), std::greater<int>());
    int total = comp_sizes[0] * comp_sizes[1] * comp_sizes[2];

    std::cout << total << std::endl;
}