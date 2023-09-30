// Field_of_wonders.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <vector>
#include <algorithm>

bool check_hub_size(const std::vector<int>& points, const size_t hub_size) {
    const size_t n = points.size() / hub_size;
    auto sub_begin = points.begin();
    auto sub_end = points.begin() + hub_size;
    for (int i = 0; i < n; ++i) {
        auto cur_begin = points.begin() + (i * hub_size);
        auto cur_end = cur_begin + hub_size;
        auto it = std::search(cur_begin, cur_end, sub_begin, sub_end);
        if (it != cur_begin)
            return false;
    }
    return true;
}

int main() {
    std::ifstream input ("INPUT.txt");
    std::ofstream output ("OUTPUT.txt");

    int n;
    std::vector<int> points;

    input >> n;
    n = n - 1;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        input >> points[i];
    }

    size_t min_hub_size;
    for (min_hub_size = 1; min_hub_size < n; ++min_hub_size) {
        if (0 != (n % min_hub_size))
            continue;

        if (check_hub_size(points, min_hub_size))
            break;
    }

    output << min_hub_size;
}