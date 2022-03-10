
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

    if (spot == mmap->getEnd() /*|| open_list.size() == 0*/)
    {
        printf("get end\n");
        close_push(spot);
        return true;
    }

    spot = move(open_pop());
    // if(close_list.find(spot) == close_list.end())
    // {
        
    // }
    close_push(spot);
    try_next_push(spot);

    return false;
}
void A_Star::try_next_push(Spot spot)
{   
    Spot end = mmap->getEnd();
    // if (spot.m_x > end.m_x)
    // {
    //     open_push(Spot(spot.m_x-1, spot.m_y), spot);
    // }
    // if (spot.m_x < end.m_x)
    // {
    //     open_push(Spot(spot.m_x+1, spot.m_y), spot);
    // }
    // if (spot.m_y > end.m_y)
    // {
    //     open_push(Spot(spot.m_x, spot.m_y-1), spot);
    // }
    // if (spot.m_x < end.m_x)
    // {
    //     open_push(Spot(spot.m_x, spot.m_y+1), spot);
    // }
    
    open_push(Spot(spot.m_x-1, spot.m_y), spot);
    open_push(Spot(spot.m_x+1, spot.m_y), spot);
    open_push(Spot(spot.m_x, spot.m_y-1), spot);
    open_push(Spot(spot.m_x, spot.m_y+1), spot);
}
void A_Star::open_push(Spot spot, Spot &f_spot)
{
    if (spot.m_x < 0 || 
        spot.m_y < 0 || 
        spot.m_x > MAX_MAP_SIZE - 1 || 
        spot.m_y > MAX_MAP_SIZE - 1 ||
        spot == mmap->getStart()
        )
    {
        return;
    }
    // if (spot == mmap->getStart())
    // {
    //     open_list.push(spot);
    // }
    // else
    // {
    pair<int, int> open_key = make_pair(spot.m_x, spot.m_y);
    if (mmap->open_map_g.find(open_key) == mmap->open_map_g.end())
    {
        spot.h = close_list.size() + 1;//mmap->getEuclideanToEnd(spot);
        spot.g = mmap->getEuclideanToStart(spot);
        //close_list.size() + 1;//
        spot.fn = spot.g + spot.h;
        spot.pre = &f_spot;
        mmap->open_map_g.emplace(open_key, spot.g);
        open_list.push(spot);
        printf("open push 1 x=%d, y=%d\n", spot.m_x, spot.m_y);

    }
    else
    {
        if (spot.g < mmap->open_map_g[open_key])
        {
            priority_queue<Spot, vector<Spot>, cmp> new_open_list;
            for (int i = 0; i < open_list.size(); i++)
            {
                Spot open_spot = open_list.top();
                if (open_spot.m_x == spot.m_x && open_spot.m_y == spot.m_y)
                {
                    spot.h = close_list.size() + 1;//mmap->getEuclideanToEnd(spot);
                    spot.g = mmap->getEuclideanToStart(spot);
                    //close_list.size() + 1;//
                    spot.fn = spot.g + spot.h;
                    spot.pre = &f_spot;
                    new_open_list.push(open_spot);
                    open_list.pop();
                }
                else
                {
                    new_open_list.push(open_spot);
                    open_list.pop();
                }
            }
            mmap->open_map_g[open_key] = spot.g;
            open_list = std::move(new_open_list);
            printf("open push 2 x=%d, y=%d\n", spot.m_x, spot.m_y);

        }
        
    }
    

        // spot.fn = mmap->getEuclideanToEnd(spot) + mmap->getEuclideanToStart(spot) + close_list.size();
        // open_list.push(spot);
    // }
    //printf("open push open_list size=%ld\n", open_list.size());

}


bool A_Star::startAlgorithm()
{
    //printf("start Algorithm\n");
    Spot start = mmap->getStart();
    open_list.push(start);
    // open_push(start, start);
    while (1)
    {
        if(try_next_step(open_list.top()))
            break;
    }
    // mmap->printMap(close_list);

    // try_next_step(open_list.top());
    printf("check is it end (%d,%d)\n",open_list.top().m_x, open_list.top().m_y);
    // close_push(open_list.top());
    printf("open %ld\n", open_list.size());
    mmap->printMap(close_list);
    return true;
    // if (open_list.size() == 0)
    //     return false;
    // else
    //     return true;
}

void A_Star::close_push(Spot spot)
{
    mmap->printMap(close_list);
    sleep(1);
    printf("close push(%d,%d)\n", spot.m_x, spot.m_y);
    close_list.emplace(spot);
    //printf("close push close_list size=%ld\n", close_list.size());
}
