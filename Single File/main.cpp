#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
    int a[] = {1,2,3,4,5,6,7};
    const int size = sizeof (a) / sizeof (int);
    std::vector<int> vec(a, a + size);
    std::cout << "before sorting:" << std::endl;
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "after sorting:" << std::endl;
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
