#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct point {
    long long x;
    long long y;
    long long z;
};

int find(int x, std::vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void merge(int x, int y, std::vector<int>& parent, std::vector<int>& size,const std::vector<point>& boxes) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (size[rootY] > size[rootX]) {
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
        if (size[rootY] == 1000) std::cout << boxes[x].x * boxes[y].x << std::endl;
    } else {
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        if (size[rootX] == 1000) std::cout << boxes[x].x * boxes[y].x << std::endl;
    }

}

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
            long long x_1 = boxes[i].x;
            long long y_1 = boxes[i].y;
            long long z_1 = boxes[i].z;

            long long x_2 = boxes[j].x;
            long long y_2 = boxes[j].y;
            long long z_2 = boxes[j].z;

            long long dx = x_1 - x_2;
            long long dy = y_1 - y_2;
            long long dz = z_1 - z_2;

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

    for (const auto& d: distances) {
        if (find(parent[d.i], parent) != find(parent[d.j], parent)) {
            merge(d.i, d.j, parent, sizes, boxes);
        }
    }
}