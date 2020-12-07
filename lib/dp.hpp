#ifndef DP_HPP
#define DP_HPP
#include <vector>
#include <cmath>
#include <thread> //for sleep
#include <cstdlib>
#include "city.hpp"

const int START = 2-1; //annotation adjustment
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
struct Pair { //previous city + distance
    int prev;
    float dist;
    Pair() : prev(-1), dist(-1) {}
    Pair(int p, float d) : prev(p), dist(d) {}
};

class dp {
public:
    static Pair dp_search(const std::vector<City>& cities, const bool& plot);
    static void trace_path(Pair p, std::ostream& o, const std::vector<City>& cities);
private:
    static Pair tsp(int visited, int current, const std::vector<City>& cities, const bool& plot);
    static float euclidean_distance(const City& a, const City& b);
    static std::vector<std::vector<Pair> > dist_table;
};

#endif
