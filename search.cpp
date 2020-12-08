#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <ctime>
#include "lib/city.hpp"
#include "lib/dp.hpp"
void arg_handler(int argc, const char *argv[], std::string& algo, std::string& file);
void read_file(const std::string& file, std::vector<City>& cities);

int main(int argc, const char *argv[]){
    srand(1);
    std::string algo, file;
    std::vector<City> cities;

    arg_handler(argc, argv, algo, file);
    read_file(file, cities);

    Pair final_node;
    clock_t start=0, end=0;
    if (algo=="dp"){
        start = clock();
        final_node = dp::dp_search(cities, PLOT);
        end = clock();
    }
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "\nExecution time: "<< cpu_time_used <<"s"<< std::endl;

    std::cout << "Shortest distance: " << final_node.dist << std::endl;
    std::cout << "\n==========\n";
    dp::trace_path(final_node, (1 << cities.size())-1, START, std::cout, cities);
    std::cout << "==========\n";
    std::ofstream fout("output.txt");
    dp::trace_path(final_node, (1 << cities.size())-1, START, fout, cities);
    fout.close();
    return 0;
}

void arg_handler(int argc, const char *argv[], std::string& algo, std::string& file) {
    if (argc != 3) {
        std::cout << "usage: #./search [algo] [filename]\n";
        exit(1);
    }
    algo = argv[1];
    file = argv[2];
}
void read_file(const std::string& file, std::vector<City>& cities) {
    std::ifstream fin(file);
    int name,x,y;
    while(fin >> name){
        name--; // annotation modify(start from 0 to start from 1)
        fin >> x >> y;
        City city(name, x, y);
        cities.push_back(city);
    }
    fin.close();
}
