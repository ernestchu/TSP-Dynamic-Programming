#ifndef CITY_HPP
#define CITY_HPP
#include <iostream>
struct City {
    const int name;
    const int x;
    const int y;
    City* next;
    City();
    City(int n, int x, int y) : name(n), x(x), y(y), next(nullptr) {}
    friend std::ostream& operator<<(std::ostream& o, const City& x);
};
#endif
