#include "gridMap.h"

gridMap::gridMap(int size)
{
    m_size = size;
    init();
}

void gridMap::init()
{
    initStartAndEnd();
    initObstacle(OBSTACLE_COUNT);
}

void gridMap::initObstacle(int count)
{
    for (int i = 0; i < count; i++)
    {
        int r_x = rand();
        int r_y = rand();
        obstacleSpots.emplace(Spot(r_x, r_y));    
    }
}
void gridMap::initStartAndEnd(Spot start, Spot end)
{
    m_start = move(start);
    m_end = move(end);
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