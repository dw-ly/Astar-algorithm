#include "gridMap.h"

gridMap::gridMap(int size)
{
    m_size = size;
    init();
}

void gridMap::init()
{
    printf("init gridMap\n");
    initStartAndEnd();
    initObstacle(OBSTACLE_COUNT);
}

void gridMap::initObstacle(int count)
{
    for (int i = 0; i < count; i++)
    {
        int r_x = rand();//TODO
        int r_y = rand();
        obstacleSpots.emplace(Spot(r_x, r_y));    
    }
}
void gridMap::initStartAndEnd(Spot start, Spot end)
{
    // printf("start(%d,%d), end(%d,%d)\n", start.m_x,start.m_y, end.m_x,end.m_y);
    m_start = move(start);
    m_end = move(end);
    printf("start(%d,%d), end(%d,%d)\n", m_start.m_x,m_start.m_y, m_end.m_x,m_end.m_y);
}

bool gridMap::checkSpot(Spot spot)
{
    return obstacleSpots.find(spot) == obstacleSpots.end();
}

Spot gridMap::getStart()
{
    return m_start;
}
Spot gridMap::getEnd()
{
    return m_end;
}

int gridMap::getEuclideanToEnd(Spot now)
{
    return abs(now.m_x - m_end.m_x) + abs(now.m_y - m_end.m_y);
}

int gridMap::getEuclideanToStart(Spot now)
{
    return abs(now.m_x - m_start.m_x) + abs(now.m_y - m_start.m_y);
}

void gridMap::printMap(set<Spot> spots)
{
    map<int, int> close_map;
    printf("close size=%ld\n",spots.size());
    for (auto spot : spots)
    {
        printf("close(%d,%d)",spot.m_x, spot.m_y);
        close_map[spot.m_x] = spot.m_y;
    }
    
    // for (int i = 0; i < MAX_MAP_SIZE; i++)
    // {
    //     for (int j = MAX_MAP_SIZE-1; j >= 0; j--)
    //     {
    //         if (close_map.find(j)!= close_map.end())
    //             printf("|%d", 1);
    //         else
    //             printf("|%d", 0);
    //     }
    //     printf("|\n");   
    // }
    // printf("\n");
    
}