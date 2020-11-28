#ifndef DP_HPP
#define DP_HPP
#include <vector>
#include <cmath>
#include <thread> //for sleep
#include "city.hpp"
/*====================================================================================================
#   TSP dynamic programing
#   dist_table[2^N][N] => [visted cities in bit representation][current city]
#          1st state: [0, 0, 0, ..... 0, 0, 0, 0][start] = 0
#      desired state: [1, 1, 1, ..... 1, 1, 1, 1][start] = shortest path
#                       0: not visited, 1: visited
#
#   top-down manner:
#   dist_table[visted][current] =
#       min(dist_table[visted(current bit to 0)][any other visited city i] + distance from i to current
====================================================================================================*/
class dp {
public:
    static double dp_search(std::vector<City>& cities, const bool& plot);
private:
    static double tsp(int visited, int current, std::vector<City>& cities, const bool& plot);
    static double euclidean_distance(const City& a, const City& b);
};

#endif
