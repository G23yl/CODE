//
// Created by Lenovo on 2023/9/19.
//

#ifndef MD_MATRIX_H
#define MD_MATRIX_H
#include <vector>
class Matrix
{
public:
    Matrix(int size = 2);   //构造函数
//    ~Matrix();      //析构函数
    void setMatrix(const std::vector<double> value);    //矩阵赋初值
    void printMatrix() const;       //打印矩阵
    int getSize() const{
        return size;
    }        //获得矩阵的大小
    double element(int i, int j) const{
        return elements[i * size + j];
    }
    double &element(int i, int j){
        return elements[i * size + j];
    }
private:
    int size;
    std::vector<double> elements;
//    double* elements;    //用一维数组来存放数据
};
#endif //MD_MATRIX_H
