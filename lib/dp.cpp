#include "dp.hpp"
std::vector<std::vector<Pair> > dp::dist_table;
Pair dp::dp_search(const std::vector<City>& cities, const bool& plot) {
    int n = cities.size();
    dist_table = std::vector<std::vector<Pair> >(1 << n, std::vector<Pair>(n, Pair(-1, -1)));
    for (int i = 0; i < n; i++) // dist from start to other cities with start not annotated, so the salesman can go back to start in the end
        dist_table[1<<i][i] = Pair(START, euclidean_distance(cities[START], cities[i]));
    return tsp((1 << n)-1, START, cities, plot);
}
void dp::trace_path(Pair p, std::ostream& o, const std::vector<City>& cities) {
    o << "\n==========\n";
    int visited = (1 << cities.size())-1;
    int current = START;
    o << cities[current] << std::endl;
    do {
        o << cities[p.prev] << std::endl;
        visited -= (1 << current);
        current = p.prev;
        p = dist_table[visited][p.prev];
    } while(p.prev != -1);
    o << "==========\n\n";
}
Pair dp::tsp(int visited, int current, const std::vector<City>& cities, const bool& plot) {
    if (plot)
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    if (dist_table[visited][current].dist != -1)
        return dist_table[visited][current];

    int current_bit = 1 << current;
    dist_table[visited][current].dist = 1e6; // Infinity
    for (int i = 0; i < cities.size(); i++) {
        if (i != current && ((1<<i)&visited)) { // if i isn't current and ith city is visted
            float dist = tsp(visited-current_bit, i, cities, plot).dist+euclidean_distance(cities[i], cities[current]);
            if (dist < dist_table[visited][current].dist)
                dist_table[visited][current] = Pair(i, dist);
        }
    }
    return dist_table[visited][current];
}
float dp::euclidean_distance(const City& a, const City& b) {
    return sqrt(pow((a.x-b.x), 2)+pow((a.y-b.y), 2));
}
