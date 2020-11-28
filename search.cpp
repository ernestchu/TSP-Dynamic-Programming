//
//  search.cpp
//
//  Created by WU,MENG-TING on 2020/10/6.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include "lib/city.hpp"
#include "lib/dp.hpp"
void arg_handler(int argc, const char *argv[], std::string& algo, std::string& file);
void read_file(const std::string& file, std::vector<City>& cities);

int main(int argc, const char *argv[]){
    std::string algo, file;
    std::vector<City> cities;

    arg_handler(argc, argv, algo, file);
    read_file(file, cities);

    double shortest=-1;
    if (algo=="dp")
        shortest = dp::dp_search(cities, false);

    std::cout << shortest << std::endl;
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
        fin >> x >> y;
        City city(name, x, y);
        cities.push_back(city);
    }
    fin.close();
}
