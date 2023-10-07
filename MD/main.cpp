#include <iostream>
#include "LinearEqu.h"
#include <vector>

int main() {
    double a1[] = {
            0, 70, 0, 5, 0,
            0, 70, 10, 0, 8,
            25, 0, -10, 5, 0,
            1, 0, 1, 0, -1,
            0, 1, -1, -1, 0
    };
    std::vector<double> a;
    for (auto x : a1){
        a.emplace_back(x);
    }
    double b1[] = {-180, 0, 0, 0, 0};
    std::vector<double> b;
    for (auto x : b1){
        b.emplace_back(x);
    }
    LinearEqu equ(5);
    equ.setLinearEqu(a, b);
    equ.printLinearEqu();
    if (equ.solve()){
        equ.printSolution();
    }
    else{
        std::cout << "Fail" << std::endl;
    }
    return 0;
}

