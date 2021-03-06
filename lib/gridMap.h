#include <iostream>
#include <set>
#include <map>
#define MAX_MAP_SIZE 100
#define START_X 5
#define START_Y 18
#define END_X 77
#define END_Y 9
#define OBSTACLE_COUNT 5

using namespace std;
struct Spot
{
    int fn;
    int g;
    int h;
    int m_x;
    int m_y;
    Spot *pre;
    // bool is_obstacle;
    Spot(int x, int y):m_x(x), m_y(y), fn(0), g(0), h(0), pre(nullptr)/*, is_obstacle(false)*/{};
    Spot(int x, int y, Spot* spot):m_x(x), m_y(y), fn(0), g(0), h(0), pre(spot)/*, is_obstacle(false)*/{};
    Spot():m_x(0), m_y(0), fn(0), g(0), h(0), pre(nullptr){};//默认构造函数
    bool operator == (Spot spot) const{return spot.m_x == m_x && spot.m_y == m_y;};
    bool operator != (Spot spot) const{return spot.m_x != m_x || spot.m_y != m_y;};
    // Spot operator = (Spot &spot) {return spot;};
    bool operator>(Spot spot) const{return /*spot.fn > fn ||*/ spot.m_x > m_x || spot.m_y > m_y;};
    bool operator<(Spot spot) const{return /*spot.fn < fn ||*/ spot.m_x < m_x || spot.m_y < m_y;};
};

class gridMap
{
public:
    gridMap(int size, int start_x, int start_y, int end_x, int end_y);
    ~gridMap() = default;
    bool checkSpot(Spot spot);
    void initObstacle(int count);
    void initStartAndEnd(Spot start = Spot(0, 0), Spot end = Spot(MAX_MAP_SIZE - 1, MAX_MAP_SIZE - 1));
    void initOpenMap(int map_size);
    void init();
    Spot getStart();
    Spot getEnd();
    void setEnd(Spot spot);
    int getEuclideanToEnd(Spot now);
    int getEuclideanToStart(Spot now);
    void printMap(set<Spot> spots);
    map<pair<int, int>, int> open_map_g;
    map<pair<int, int>, int> close_map;
    map<pair<int, int>, Spot> map_spot;
private:
    int m_size;
    Spot m_start;//不带参数会提示没有默认构造函数，或者添加一个默认构造函数
    Spot m_end;
    set<Spot> obstacleSpots;
    set<pair<int, int>> obstacle_locate;
};

