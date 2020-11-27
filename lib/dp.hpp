#ifndef DP_HPP
#define DP_HPP
#include <vector>
#include <cmath>
#include "city.hpp"
/*====================================================================================================
#   TSP dynamic programing
#   dist_table[2^N][N] => [visted cities, in bit representation][current city]
#          1st state: [0, 0, 0, ..... 0, 0, 0, 0][start] = 0
#        final state: [1, 1, 1, ..... 1, 1, 1, 1][start] = shortest path
====================================================================================================*/
class dp {
public:
    static double dp_search(std::vector<City*>& cities);
private:
    static double tsp(int visited, int current, std::vector<City*>& cities);
    static double euclidean_distance(const City& a, const City& b);
};

#endif
