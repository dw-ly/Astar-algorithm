#include "gridMap.h"

gridMap::gridMap(int size, int start_x, int start_y, int end_x, int end_y)
{
    initOpenMap(MAX_MAP_SIZE);
    m_size = size;
    m_start = map_spot[make_pair(start_x, start_y)];
    m_end = map_spot[make_pair(end_x, end_y)];
    initObstacle(OBSTACLE_COUNT);

    // init();
}

void gridMap::init()
{
    printf("init gridMap\n");
    // initStartAndEnd(Spot(20,5), Spot(3,98));
    initObstacle(OBSTACLE_COUNT);
    // initOpenMap(MAX_MAP_SIZE);
}
void gridMap::initOpenMap(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // open_map_g[make_pair(i,j)] = 0;
            map_spot[make_pair(i,j)] = Spot(i,j);
        }
        
    }
    
}
void gridMap::initObstacle(int count)
{
    for (int i = 0; i < count; i++)
    {
        int r_x = rand();//TODO
        int r_y = rand();
        // obstacleSpots.emplace(Spot(r_x, r_y));  
        obstacle_locate.emplace(make_pair(r_x, r_y));  
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

void gridMap::setEnd(Spot spot)
{
    m_end = spot;
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
    // map<int, int> close_map;
    // printf("close size=%ld\n",spots.size());
    // for (auto spot : spots)
    // {
    //     if (spot.pre != nullptr)
    //     {
    //         printf("close(%d,%d) pre (%d,%d)  pre pre (%d,%d)\n",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);        
    //     }
        
    //     // close_map[spot.m_x] = spot.m_y;
    // }
    
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