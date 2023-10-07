//
// Created by Lenovo on 2023/9/19.
//
#include "LinearEqu.h"
#include <iostream>
#include <vector>
#include <cmath>

LinearEqu::LinearEqu(int size) : Matrix(size) {
    sums.resize(size);
    solution.resize(size);
//    sums = new double[size];        // 给方程的所有向量开空间
//    solution = new double [size];
}

//LinearEqu::~LinearEqu() {
//    delete[] sums;
//    delete[] solution;
//}
//赋值给方程组
void LinearEqu::setLinearEqu(const std::vector<double> a, const std::vector<double> b) {
    setMatrix(a);
    for (int i = 0; i < getSize(); ++i){
        sums[i] = b[i];
    }
}
// 显示方程组
void LinearEqu::printLinearEqu() const {
    std::cout << "The Line equation is:" << std::endl;
    for (int i = 0; i < getSize(); ++i){
        for (int j = 0; j < getSize(); ++j){
            std::cout << element(i, j) << " ";
        }
        std::cout << "     " << sums[i] << std::endl;
    }
}
//显示答案
void LinearEqu::printSolution() const {
    std::cout << "The solution is:" << std::endl;
    for (int i = 0; i < getSize(); ++i){
        std::cout << "x["<< i <<"]=" << solution[i] << std::endl;
    }
}
// 交换两个实数
inline void swap(double &v1, double &v2){
    double temp = v1;
    v1 = v2;
    v2 = temp;
}

bool LinearEqu::solve() {
//    int *js = new int[getSize()];   //存最大主元素的列号
    std::vector<int> js(getSize());
    for (int k = 0; k < getSize() - 1; ++k){
        // 选主元素
        int is;     // 主元素所在行号
        double max = 0;     // 最大值
        for (int i = k; i < getSize(); ++i){
            for (int j = k; j < getSize(); ++j){
                double t = fabs(element(i, j));
                if (t > max){
                    max = t;
                    js[k] = j;
                    is = i;
                }
            }
        }
        if (max == 0){
            return false;
        }
        else{
            //通过行列交换，把主元素换到第k行k列
            if (js[k] != k){
                for (int i = 0; i < getSize(); ++i){
                    swap(element(i, k), element(i, js[k]));
                }
            }
            if (is != k){
                for (int j = k; j < getSize(); ++j){
                    swap(element(k, j), element(is, j));
                }
                swap(sums[k], sums[is]);
            }
        }
        // 归一化过程
        double major = element(k, k);
        for (int j = k + 1; j < getSize(); ++j){
            element(k, j) /= major;
        }
        sums[k] /= major;
        // 消去运算
        for (int i = k + 1; i < getSize(); ++i){
            for (int j = k + 1; j < getSize(); ++j){
                element(i,  j) = element(i, j) - element(i, k) * element(k, j);
            }
            sums[i] = sums[i] - element(i, k) * sums[k];
        }
    }
    // 判断剩下的一个元素是否等于0
    double d = element(getSize() - 1, getSize() - 1);
    if (fabs(d) < 1e-15){
        return false;
    }
    // 回代过程
    solution[getSize() - 1] = sums[getSize() - 1] / d;
    for (int i = getSize() - 2; i >= 0; --i){
        double t = 0.0;
        for (int j = i + 1; j <= getSize() - 1; ++j){
            t += element(i, j) * solution[j];
        }
        solution[i] = sums[i] - t;
    }
    js[getSize() - 1] = getSize() - 1;
    for (int k = getSize() - 1; k >= 0; --k){
        if (js[k] != k){
            swap(solution[k], solution[js[k]]);
        }
    }
    return true;
}