
#include "AStar.h"
A_Star::A_Star()
{
    mmap = new gridMap(MAX_MAP_SIZE, START_X, START_Y, END_X, END_Y);//TODO
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

bool A_Star::startAlgorithm()
{
    printf("start Algorithm\n");
    Spot start = mmap->getStart();
    open_list.push(start);
    while (1)
    {
        if (open_list.top().pre != nullptr)
        {
            printf("try_next_step open_list top=(%d,%d)\n", open_list.top().pre->m_x, open_list.top().pre->m_y);

        }    
        // printf("try_next_step open_list top=(%d,%d)\n", open_list.top().pre->m_x, open_list.top().pre->m_y);
        if(try_next_step(open_list.top()))
            break;
    }
    printf("open %ld\n", open_list.size());
    // mmap->printMap(close_list);
    Spot spot = mmap->getEnd();
    // printList(spot);

    return true;
}

bool A_Star::try_next_step(Spot spot)
{
    printf("try_next_step start\n");

    if (spot == mmap->getEnd() /*|| open_list.size() == 0*/)
    {
        printf("get end (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
        close_push(spot);
        // mmap->setEnd(spot);
        printList(spot);
        return true;
    }
    open_list.pop();
    if (spot.pre != nullptr)
    {
        printf("before close_push (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
    }
    

    close_push(spot);
    try_next_push(spot);
    printf("try_next_step end\n");

    return false;
}
void A_Star::try_next_push(Spot spot)
{   
    //四个方向
    // open_push(Spot(spot.m_x-1, spot.m_y, &spot), spot);
    // open_push(Spot(spot.m_x+1, spot.m_y, &spot), spot);
    // open_push(Spot(spot.m_x, spot.m_y-1, &spot), spot);
    // open_push(Spot(spot.m_x, spot.m_y+1, &spot), spot);
    // //八个方向
    // open_push(Spot(spot.m_x-1, spot.m_y-1, &spot), spot);
    // open_push(Spot(spot.m_x+1, spot.m_y+1, &spot), spot);
    // open_push(Spot(spot.m_x+1, spot.m_y-1, &spot), spot);
    // open_push(Spot(spot.m_x-1, spot.m_y+1, &spot), spot);

    open_push(make_pair(spot.m_x-1, spot.m_y), make_pair(spot.m_x, spot.m_y));
    open_push(make_pair(spot.m_x+1, spot.m_y), make_pair(spot.m_x, spot.m_y));
    open_push(make_pair(spot.m_x, spot.m_y-1), make_pair(spot.m_x, spot.m_y));
    open_push(make_pair(spot.m_x, spot.m_y+1), make_pair(spot.m_x, spot.m_y));
    //八个方向
    open_push(make_pair(spot.m_x-1, spot.m_y-1), make_pair(spot.m_x, spot.m_y));
    open_push(make_pair(spot.m_x+1, spot.m_y+1), make_pair(spot.m_x, spot.m_y));
    open_push(make_pair(spot.m_x+1, spot.m_y-1), make_pair(spot.m_x, spot.m_y));
    open_push(make_pair(spot.m_x-1, spot.m_y+1), make_pair(spot.m_x, spot.m_y));
}
void A_Star::open_push(pair<int, int> locate, pair<int, int> f_locate)
{
    if (locate.first < 0 ||
        locate.second < 0 ||
        locate.first > MAX_MAP_SIZE - 1 ||
        locate.second > MAX_MAP_SIZE - 1 ||
        close_map.find(locate) != close_map.end()
    )
    {
        return;
    }
    Spot &spot = mmap->map_spot[locate];
    Spot &f_spot = mmap->map_spot[f_locate];
    pair<int, int> open_key = make_pair(spot.m_x, spot.m_y);
    if (mmap->open_map_g.find(open_key) == mmap->open_map_g.end())
    {
        spot.h = mmap->getEuclideanToEnd(spot);
        spot.g = close_list.size() + 1;//mmap->getEuclideanToStart(spot);
        //close_list.size() + 1;//
        spot.fn = spot.g + spot.h;
        // printf("f_spot--------(%d,%d)(%d,%d)",spot.m_x, spot.m_y, f_spot.m_x, f_spot.m_y);
        spot.pre = &f_spot;
        if (spot.pre->pre != nullptr)
        {
            printf("f_spot--------(%d,%d)(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);

        }
        
        // printf("f_spot--------(%d,%d)(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);

        mmap->open_map_g.emplace(open_key, spot.g);
        open_list.push(spot);

        // Spot start = mmap->getStart();
        // if (spot.pre != nullptr)
        // {
        //     printf("open push 1 (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
        // }
        return;
    }
    // else
    {
        spot.g = f_spot.g + 1;
        if (spot.g < mmap->open_map_g[open_key])
        {
            priority_queue<Spot, vector<Spot>, cmp> new_open_list;
            for (int i = 0; i < open_list.size(); i++)//全部出队，修改对应点g值和指针后重新入队
            {
                Spot open_spot = open_list.top();
                open_list.pop();
                if (open_spot.m_x == spot.m_x && open_spot.m_y == spot.m_y)//需要修改的spot
                {
                    spot.h = mmap->getEuclideanToEnd(spot);
                    // spot.g = close_list.size() + 1;//mmap->getEuclideanToStart(spot);
                    //close_list.size() + 1;//
                    spot.fn = spot.g + spot.h;
                    // printf("f_spot--------(%d,%d)(%d,%d)",spot.m_x, spot.m_y, f_spot.m_x, f_spot.m_y);
                    spot.pre = &f_spot;
                    // printf("f_spot--------(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
                    if (spot.pre->pre != nullptr)
                    {
                        // printf("f_spot--------(%d,%d)(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);
                    }
                    


                    new_open_list.push(spot);
                    // open_list.pop();
                    mmap->open_map_g[open_key] = spot.g;
                }
                else
                {
                    new_open_list.push(open_spot);
                    // open_list.pop();
                }
            }
            // mmap->open_map_g[open_key] = spot.g;
            open_list = std::move(new_open_list);

            // Spot start = mmap->getStart();
            // if (spot.pre != nullptr)
            // {
            //     printf("open push 2 (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
            // }
        }
    }
    if (open_list.top().pre != nullptr)
    {
        printf("------------------(%d,%d) (%d,%d)-------------\n", open_list.top().m_x, open_list.top().m_y,open_list.top().pre->m_x, open_list.top().pre->m_y);
    }
}
void A_Star::open_push(Spot spot, Spot &f_spot)
{
    printf("open_push---------(%d,%d) (%d,%d)\n",spot.m_x,spot.m_y, f_spot.m_x, f_spot.m_y);
    if (spot.m_x < 0 || 
        spot.m_y < 0 ||
        //(spot.m_x == mmap->getStart().m_x && spot.m_y == mmap->getStart().m_y) ||
        spot.m_x > MAX_MAP_SIZE - 1 || 
        spot.m_y > MAX_MAP_SIZE - 1 ||
        //spot == mmap->getStart() ||
        spot.pre != nullptr 
        /*添加障碍物判断*/)
    {
        return;
    }
    if (spot == mmap->getStart())
    {
        mmap->open_map_g.emplace(make_pair(mmap->getStart().m_x, mmap->getStart().m_y), 0);
        return;
    }
    
    // if (spot == mmap->getEnd())
    // {
    //     spot.pre = &f_spot;
    //     printf("open push end (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
    //     // return;
    // }
    
    pair<int, int> open_key = make_pair(spot.m_x, spot.m_y);
    if (mmap->open_map_g.find(open_key) == mmap->open_map_g.end())
    {
        spot.h = mmap->getEuclideanToEnd(spot);
        spot.g = close_list.size() + 1;//mmap->getEuclideanToStart(spot);
        //close_list.size() + 1;//
        spot.fn = spot.g + spot.h;
        // printf("f_spot--------(%d,%d)(%d,%d)",spot.m_x, spot.m_y, f_spot.m_x, f_spot.m_y);
        spot.pre = &f_spot;
        if (spot.pre->pre != nullptr)
        {
            printf("f_spot--------(%d,%d)(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);

        }
        
        // printf("f_spot--------(%d,%d)(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);

        mmap->open_map_g.emplace(open_key, spot.g);
        open_list.push(spot);

        // Spot start = mmap->getStart();
        // if (spot.pre != nullptr)
        // {
        //     printf("open push 1 (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
        // }
        return;
    }
    // else
    {
        spot.g = f_spot.g + 1;
        if (spot.g < mmap->open_map_g[open_key])
        {
            priority_queue<Spot, vector<Spot>, cmp> new_open_list;
            for (int i = 0; i < open_list.size(); i++)//全部出队，修改对应点g值和指针后重新入队
            {
                Spot open_spot = open_list.top();
                open_list.pop();
                if (open_spot.m_x == spot.m_x && open_spot.m_y == spot.m_y)//需要修改的spot
                {
                    spot.h = mmap->getEuclideanToEnd(spot);
                    // spot.g = close_list.size() + 1;//mmap->getEuclideanToStart(spot);
                    //close_list.size() + 1;//
                    spot.fn = spot.g + spot.h;
                    // printf("f_spot--------(%d,%d)(%d,%d)",spot.m_x, spot.m_y, f_spot.m_x, f_spot.m_y);
                    spot.pre = &f_spot;
                    // printf("f_spot--------(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
                    if (spot.pre->pre != nullptr)
                    {
                        // printf("f_spot--------(%d,%d)(%d,%d)(%d,%d)",spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y, spot.pre->pre->m_x, spot.pre->pre->m_y);
                    }
                    


                    new_open_list.push(spot);
                    // open_list.pop();
                    mmap->open_map_g[open_key] = spot.g;
                }
                else
                {
                    new_open_list.push(open_spot);
                    // open_list.pop();
                }
            }
            // mmap->open_map_g[open_key] = spot.g;
            open_list = std::move(new_open_list);

            // Spot start = mmap->getStart();
            // if (spot.pre != nullptr)
            // {
            //     printf("open push 2 (%d,%d) (%d,%d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
            // }
        }
    }
    if (open_list.top().pre != nullptr)
    {
        printf("------------------(%d,%d) (%d,%d)-------------\n", open_list.top().m_x, open_list.top().m_y,open_list.top().pre->m_x, open_list.top().pre->m_y);
    }
    
}

void A_Star::close_push(Spot spot)
{
    // sleep(1);
    printf("close push(%d,%d)\n", spot.m_x, spot.m_y);
    close_list.emplace(spot);
    mmap->printMap(close_list);
    close_map.emplace(make_pair(spot.m_x, spot.m_y), spot);
}

void A_Star::printList(Spot &spot)
{
    // printf("\n");
    // printf("printList (%d, %d) (%d, %d)\n", spot.m_x, spot.m_y, spot.pre->m_x, spot.pre->m_y);
    printf("printList (%d, %d)\n", spot.m_x, spot.m_y);
    if (spot.pre != nullptr)
    {
        printList(*spot.pre);
    }
    
}