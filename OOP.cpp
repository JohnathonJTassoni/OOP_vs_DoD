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

struct ShapeEntity
{
    std::string Name;
    Coords pos;
    std::string Colour;
    bool aBool = false;
    bool bBool = true;
    std::string descrp = "This is a default description"; 


    ShapeEntity(std::string name, std::string col) : pos(Coords())
    {
        Name = name;
        Colour = col;
    }

};



int main()
{
    srand(time(NULL));
    std::vector<ShapeEntity> shapes;

    for(int i = 0; i < 100000; i++)
    {
        shapes.emplace_back(ShapeEntity("Shape Name", "Colour"));
    }

    auto timer = std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::system_clock> first_time = timer;
    
    for(auto& shape : shapes)
    {
        std::cout << "Shape pos: " <<shape.pos.x << ", " << shape.pos.y << ", " << shape.pos.z << "\n";
    }
    
    timer = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTime = timer - first_time;

    std::cout << "**************************************\n";
    std::cout << "Load Time: "<< (deltaTime.count()) << "\n";
    std::cout << "**************************************\n";

    return EXIT_SUCCESS;
}
