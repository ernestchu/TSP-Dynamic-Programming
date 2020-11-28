#include "city.hpp"
std::ostream& operator<<(std::ostream& o, const City& c) {
    o << c.name+1 /*annotation modify*/ << ' ' << c.x << ' ' << c.y;
    return o;
}
