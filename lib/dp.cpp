#include "dp.hpp"
static std::vector<std::vector<double> > dist_table;
double dp::dp_search(std::vector<City*>& cities) {
    int start = 0;
    int n = cities.size();
    dist_table = std::vector<std::vector<double> >(1 << n, std::vector<double>(n, -1));
    for (int i = 0; i < n; i++) // dist from start to other cities with start not annotated, so the salesman can go back to start in the end
        dist_table[1<<i][i] = euclidean_distance(*cities[start], *cities[i]);
    return tsp((1 << n)-1, start, cities);
}
double dp::tsp(int visited, int current, std::vector<City*>& cities) {
    if (dist_table[visited][current] != -1)
        return dist_table[visited][current];

    int current_bit = 1 << current;
    dist_table[visited][current] = 1e6; // Infinity
    for (int i = 0; i < cities.size(); i++) {
        if (i != current && ((1<<i)&visited)) { // if i isn't current and ith city is visted
            double other_path = tsp(visited-current_bit, i, cities)+euclidean_distance(*cities[i], *cities[current]);
            if (other_path < dist_table[visited][current])
                dist_table[visited][current] = other_path;
        }
    }
    return dist_table[visited][current];
}
double dp::euclidean_distance(const City& a, const City& b) {
    return sqrt(pow((a.x-b.x), 2)+pow((a.y-b.y), 2));
}
