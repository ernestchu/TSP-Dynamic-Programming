#include "city.hpp"
std::ostream& operator<<(std::ostream& o, const City& c) {
    o << c.name << ' ' << c.x << ' ' << c.y;
    return o;
}
