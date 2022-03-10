
#include "AStar.h"
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

bool A_Star::try_next_step(Spot spot)
{
    // Spot newSpot;    
    //printf("try next step open_list size=%ld\n", open_list.size());
    // if (open_list.size() == 10)
    // {
    //     return true;
    // }

    if (spot == mmap->getEnd())
    {
        printf("get end\n");
        close_push(spot);
        return true;
    }
    if(close_list.find(spot) == close_list.end())
    {
        close_push(spot);
    }
    spot = move(open_pop());
    try_next_push(spot);
    return false;
}
void A_Star::open_push(Spot spot)
{
    if (spot.m_x < 0 || 
        spot.m_y < 0 || 
        spot.m_x > MAX_MAP_SIZE - 1 || 
        spot.m_y > MAX_MAP_SIZE - 1 ||
        spot == mmap->getStart() ||
        spot == open_list.top())
    {
        return;
    }
    //printf("open push x=%d, y=%d\n", spot.m_x, spot.m_y);
    // if (spot == mmap->getStart())
    // {
    //     open_list.push(spot);
    // }
    // else
    // {

        spot.fn = mmap->getEuclideanToEnd(spot) + mmap->getEuclideanToStart(spot) + close_list.size();
        open_list.push(spot);
    // }
    //printf("open push open_list size=%ld\n", open_list.size());

}

void A_Star::try_next_push(Spot spot)
{   
    Spot end = mmap->getEnd();
    if (spot.m_x > end.m_x)
    {
        open_push(Spot(spot.m_x-1, spot.m_y, &spot));
    }
    if (spot.m_x < end.m_x)
    {
        open_push(Spot(spot.m_x+1, spot.m_y, &spot));
    }
    if (spot.m_y > end.m_y)
    {
        open_push(Spot(spot.m_x, spot.m_y-1, &spot));
    }
    if (spot.m_x < end.m_x)
    {
        open_push(Spot(spot.m_x, spot.m_y+1, &spot));
    }
    // open_push(Spot(spot.m_x-1, spot.m_y, &spot));
    // open_push(Spot(spot.m_x+1, spot.m_y, &spot));
    // open_push(Spot(spot.m_x, spot.m_y-1, &spot));
    // open_push(Spot(spot.m_x, spot.m_y+1, &spot));

}
void A_Star::startAlgorithm()
{
    //printf("start Algorithm\n");
    Spot start = mmap->getStart();
    open_list.push(start);
    open_push(start);
    while (1)
    {
        if(try_next_step(open_list.top()))
            break;
    }
    // mmap->printMap(close_list);

    // try_next_step(open_list.top());
    printf("check is it end (%d,%d)\n",open_list.top().m_x, open_list.top().m_y);

}

void A_Star::close_push(Spot spot)
{
    mmap->printMap(close_list);
    sleep(1);
    close_list.insert(spot);
    //printf("close push close_list size=%ld\n", close_list.size());
}