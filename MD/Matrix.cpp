//
// Created by Lenovo on 2023/9/19.
//
#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int size) : size(size) {
    elements.resize(size * size);
}

//Matrix::~Matrix() {
//    delete [] elements;
//}

void Matrix::setMatrix(const std::vector<double> value) {
    for (int i = 0; i < size * size; ++i){
        elements[i] = value[i];
    }
}

void Matrix::printMatrix() const {
    std::cout << "The matrix is:" << std::endl;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            std::cout << element(i, j) << " ";
        }
        std::cout << std::endl;
    }
}


