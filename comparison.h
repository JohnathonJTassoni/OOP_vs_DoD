#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <fstream>
#include <boost/tokenizer.hpp>

const int INIT_VALUE = 1;
const std::string fileName = "50000.txt";

const std::string wordA = "water";
const std::string wordB = "Programming";

struct OOP_Dictionary
{
    size_t count;
    std::map<std::string, int> data_map;

    OOP_Dictionary();

    bool add(std::string);
    bool find(const std::string);
    void print_map();

};



struct DoD_Dictionary
{
    size_t count;
    std::vector<std::string> Keys;
    std::vector<int> Values;

    DoD_Dictionary();

};

struct DoD_Manager
{
    DoD_Manager();   
    bool add(std::vector<std::string>&, std::vector<int>&, size_t&, std::string);
    int find(const std::string, const std::vector<std::string>, const size_t);
    void get(const std::vector<int>, const int index);
    void print_map(const std::vector<std::string>, const std::vector<int>, const size_t);
};
