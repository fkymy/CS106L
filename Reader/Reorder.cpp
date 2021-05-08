#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <random>

struct placeT {
    int x, y;
};

bool ComparePlaces(placeT one, placeT two) {
    if (one.x != two.x)
        return one.x < two.x;
    return one.y < two.y;
}

int main() {
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);

    std::cout << "before: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;

    // shuffle
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::shuffle(v.begin(), v.end(), engine);

    std::cout << "after: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;

    std::sort(v.begin(), v.end());
    std::cout << "after sort: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;
}
