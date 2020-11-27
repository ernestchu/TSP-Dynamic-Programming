#ifndef CITY_HPP
#define CITY_HPP
#include <iostream>
struct City {
    const int name;
    const int x;
    const int y;
    City();
    City(int n, int x, int y) : name(n), x(x), y(y) {}
    friend std::ostream& operator<<(std::ostream& o, const City& x);
};
#endif
