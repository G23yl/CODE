#include <bits/stdc++.h>
#include <iostream>

class a{
private:
    int size;
public:
    a(){}
    a(int s) : size(s){}
    int getSize() const;
};

int a::getSize() const{
    return size;
}

int main() {
    a A(3);
    auto lma = []{return 90;};
    std::cout << A.getSize() << std::endl;
    std::cout << lma() << std::endl;
    return 0;
}
