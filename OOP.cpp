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

    for(auto& shape : shapes)
    {
        std::cout << "Shape pos: " <<shape.pos.x << ", " << shape.pos.y << ", " << shape.pos.z << "\n";
    }
    
    return EXIT_SUCCESS;
}
