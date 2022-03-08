#include <queue>
#include "gridMap.h"
class A_Star
{
private:
    gridMap *mmap;
    priority_queue<Spot> open_list;
    queue<Spot> close_list;
public:
    A_Star(int map_size);
    ~A_Star();
};

A_Star::A_Star(int map_size)
{
    mmap = new gridMap(map_size);//TODO
}

A_Star::~A_Star()
{
    delete mmap;
}
