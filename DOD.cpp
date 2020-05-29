#include <iostream>
#include <string>
#include <cstdlib>
#include <tuple>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>

struct Coords
{
    int x;
    int y;
    int z;

    Coords()
    {
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        z = rand() % 10 + 1;
    } 

};


struct ShapeEntities
{
    std::vector<std::string> Names;
    std::vector<Coords> pos;
    std::vector<std::string> Colours;
    std::vector<bool> aBool;
    std::vector<bool> bBool;
    std::vector<std::string> descriptions; 
    
    size_t count = 0;

    ShapeEntities() 
    {
        Names = std::vector<std::string>();
        pos = std::vector<Coords>();
        Colours = std::vector<std::string>();
    }

    void add_entity(std::string name = "Default", std::string col = "None")
    {
        Names.push_back(name);
        pos.push_back(Coords());
        Names.push_back(col);
        count++;
    }
};

struct ShapeManager
{
    ShapeManager(){}

    void print_position(std::vector<Coords>& PosVector, size_t count)
    {
        for(size_t i = 0; i < count; i++)
        {
            std::cout << "Shape: " << PosVector[i].x << ", " << PosVector[i].y << ", " << PosVector[i].z << "\n";
        }
    }


};


int main()
{
    srand(time(NULL));
    ShapeEntities Shapes;
    ShapeManager smanager;

    for(int i = 0; i < 100000; i++)
    {
        Shapes.add_entity("Shape Name", "Colour");
    }

    auto timer = std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::system_clock> first_time = timer;
    
    smanager.print_position(Shapes.pos, Shapes.count);

    timer = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTime = timer - first_time;

    std::cout << "**************************************\n";
    std::cout << "Load Time: "<< (deltaTime.count()) << "\n";
    std::cout << "**************************************\n";
    
    return EXIT_SUCCESS;
}
