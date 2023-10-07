//
// Created by Lenovo on 2023/9/19.
//

#ifndef MD_LINEAREQU_H
#define MD_LINEAREQU_H
#include "Matrix.h"
#include <vector>
class LinearEqu : public Matrix
{
public:
    LinearEqu(int size = 2);
//    ~LinearEqu();
    // 方程的赋值
    void setLinearEqu(const std::vector<double> a, const std::vector<double> b);
    // 全选主元高斯消去法
    bool solve();
    void printLinearEqu() const;  // 打印方程
    void printSolution() const;     //打印解

private:
    std::vector<double> sums;
//    double * sums;  //方程等号右边的向量
//    double * solution;  //方程的解向量
    std::vector<double> solution;
};
#endif //MD_LINEAREQU_H
