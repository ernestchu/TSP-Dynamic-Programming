#include "dp.hpp"
std::vector<std::vector<Pair> > dp::dist_table;
Pair dp::dp_search(const std::vector<City>& cities, const bool& plot) {
    int n = cities.size();
    dist_table = std::vector<std::vector<Pair> >(1 << n, std::vector<Pair>(n, Pair(-1, -1)));
    for (int i = 0; i < n; i++) // dist from start to other cities with start not annotated, so the salesman can go back to start in the end
        dist_table[1<<i][i] = Pair(START, euclidean_distance(cities[START], cities[i]));
    return tsp((1 << n)-1, START, cities, plot);
}
void dp::trace_path(Pair p, int visited, int current, std::ostream& o, const std::vector<City>& cities) {
    o << cities[current] << std::endl;
    do {
        o << cities[p.prev] << std::endl;
        visited -= (1 << current);
        current = p.prev;
        p = dist_table[visited][p.prev];
    } while(p.prev != -1);


}
Pair dp::tsp(int visited, int current, const std::vector<City>& cities, const bool& plot) {
    if (dist_table[visited][current].dist != -1)
        return dist_table[visited][current];

    int current_bit = 1 << current;
    dist_table[visited][current].dist = 1e6; // Infinity
    for (int i = 0; i < cities.size(); i++) {
        if (i != current && ((1<<i)&visited)) { // if i isn't current and ith city is visited
            float dist = tsp(visited-current_bit, i, cities, plot).dist+euclidean_distance(cities[i], cities[current]);
            if (dist < dist_table[visited][current].dist)
                dist_table[visited][current] = Pair(i, dist);
        }
    }
    if (plot) {
        // count the number of visted cities
        int count = 0, n = visited;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        if (count > cities.size()-5) { // threshold of minimum number of cities visited
            std::this_thread::sleep_for(std::chrono::milliseconds(10)); // delay
            std::ofstream fout("output.txt");
            trace_path(dist_table[visited][current], visited, current, fout, cities);
            fout.close();
        }
    }
    return dist_table[visited][current];
}
float dp::euclidean_distance(const City& a, const City& b) {
    return sqrt(pow((a.x-b.x), 2)+pow((a.y-b.y), 2));
}
