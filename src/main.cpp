#include <iostream>
#include "AStar.h"
// #include "priority_queue.h"
// #include "gridMap.h"
using namespace std;
int main()
{
    printf("main A Star start\n");
    A_Star a_star(MAX_MAP_SIZE);
    if(a_star.startAlgorithm())
        printf("success\n");
    else
        printf("fail\n");
}
// struct TT
// {
// 	int a;
// 	int b;
// 	TT(int aa, int bb):a(aa),b(bb){};
// };
// struct mcmp
// {
//     bool operator ()(TT aa, TT bb)//重写仿函数
//     {
//         return aa.a < bb.b;
//     }
// };
// int main()
// {
// 	TT t(1,2);
// 	my_space::priority_queue<TT,vector<TT>, mcmp> pq;
// 	pq.push(t);
// 	pq.push(TT(3,4));
// 	//pq.push(2);
// 	//pq.push(3);
// 	//pq.push(9);
// 	//pq.push(4);
// 	//pq.push(5);
// 	cout << pq.top().a << endl;
// 	pq.pop();
// 	cout << pq.top().a << endl;
// 	return 0;
// }