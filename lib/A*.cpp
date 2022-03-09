
#include "A*.h"
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
    if (spot == mmap->getEnd())
    {
        return;
    }
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
    if (spot == mmap->getStart())
    {
        open_list.push(spot);
    }
    else
    {
        spot.fn = mmap->getEuclideanToEnd(spot) + mmap->getEuclideanToStart(spot);
        open_list.push(spot);
    }
}

void A_Star::try_next_push(Spot spot)
{    
    open_push(Spot(spot.m_x, spot.m_y+1, &spot));
    open_push(Spot(spot.m_x+1, spot.m_y, &spot));
    open_push(Spot(spot.m_x-1, spot.m_y, &spot));
    open_push(Spot(spot.m_x, spot.m_y-1, &spot));
}
void A_Star::startAlgorithm()
{
    Spot start = mmap->getStart();
    open_push(start);
    while (close_list.find(mmap->getEnd()) == close_list.end())
    {
        try_next_step(open_list.top());
    }
}

void A_Star::close_push(Spot spot)
{
    close_list.insert(spot);
}