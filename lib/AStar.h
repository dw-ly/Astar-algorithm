#include <queue>
#include <vector>
#include <set>
#include <functional>
#include <unistd.h>
#include "gridMap.h"
struct cmp
{
    bool operator ()(Spot a, Spot b)//重写仿函数
    {
        return a.fn < b.fn;
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
    bool try_next_step(Spot spot);
    void startAlgorithm();
    // function<void(Spot, Spot)> cmp;
};
