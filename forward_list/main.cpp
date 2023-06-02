#include <iostream>
#include <vector>
#include "Forward_List.hpp"
#include <forward_list>
#include <chrono>

class A {
    int x;
    int y;
    public:
        A(int x, int y) :
        x(x), y(y) {}
        friend std::ostream& operator<<(std::ostream& os, const A& ob) {
            os << ob.x << " " << ob.y ;
            return os;
        }
};

int main() {
    using namespace my;
    std::vector<int> v{1, 2, 3, 7};
    Forward_List<int> b(v.begin(), v.end());
    Forward_List<int> ob{4, 5, 6};
    // ob.splice_after(ob.before_begin(), b);
    ob.merge(b);
    // std::cout << b.empty() << std::endl;
    for (auto i : ob) {
        std::cerr << i << " ";
    }
}