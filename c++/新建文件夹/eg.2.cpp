//
// Created by szy on 2021/10/25.
//
#include <iostream>
#include <vector>

using std::vector;

int main(void) {
    vector<int> v;
    std::cout << "v.size() == " << v.size() << ", v.capacity() = " << v.capacity() << std::endl;
    v.reserve(10);
    std::cout << "v.size() == " << v.size() << ", v.capacity() = " << v.capacity() << std::endl;
    v.resize(10);
    v.push_back(0);
    v.push_back(888);
    std::cout << "v.size() == " << v.size() << ", v.capacity() = " << v.capacity() << std::endl;
    std::cout << v[11] << std::endl;
    return 0;
}
