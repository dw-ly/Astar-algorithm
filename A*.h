#include <queue>
#include <vector>
#include <set>
#include <functional>
#include "gridMap.h"
struct cmp
{
    bool operator ()(Spot a, Spot b)//重写仿函数
    {
        return a.g + a.h > b.g + b.h;
    }
};

class A_Star
{
private:
    gridMap *mmap;
    priority_queue<Spot, vector<Spot>, cmp> open_list;
    set<Spot> close_list;

    Spot open_pop();
    void open_push(Spot spot);
    void close_push(Spot spot);
public:
    A_Star(int map_size);
    ~A_Star();

    void try_next_push(Spot spot);
    void try_next_step(Spot spot);
    void start();
    // function<void(Spot, Spot)> cmp;
};

A_Star::A_Star(int map_size)
{
    mmap = new gridMap(map_size);//TODO
}

A_Star::~A_Star()
{
    delete mmap;
}

Spot A_Star::open_pop()
{
    Spot top(open_list.top());
    open_list.pop();
    return top; 
}

void A_Star::try_next_step(Spot spot)
{
    // Spot newSpot;    
    if(close_list.find(spot) == close_list.end())
    {
        close_push(spot);
    }
    spot = move(open_pop());
    try_next_push(spot);
}
void A_Star::open_push(Spot spot)
{
    if (spot.m_x < 0 || 
        spot.m_y < 0 || 
        spot.m_x > MAX_MAP_SIZE - 1 || 
        spot.m_y > MAX_MAP_SIZE - 1)
    {
        return;
    }
    
    spot.g = mmap->getEuclideanToStart(spot);
    spot.h = mmap->getEuclideanToEnd(spot);
    open_list.push(spot);
}

void A_Star::try_next_push(Spot spot)
{    
    open_push(Spot(spot.m_x, spot.m_y+1, &spot));
    open_push(Spot(spot.m_x+1, spot.m_y, &spot));
    open_push(Spot(spot.m_x-1, spot.m_y, &spot));
    open_push(Spot(spot.m_x, spot.m_y-1, &spot));
}
void A_Star::start()
{
    Spot start = mmap->getStart();
}

void A_Star::close_push(Spot spot)
{
    close_list.insert(spot);
}