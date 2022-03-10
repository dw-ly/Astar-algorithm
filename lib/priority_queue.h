#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
namespace my_space
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	//仿函数(仿函数就是一个类，在这个类里仅仅是重载了一个小括号，
	//仿函数只有一元仿函数和二元仿函数，根据参数个数确定)
	//仿函数就是用起来像函数的类
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};
	template<class T, class Cont = vector<T>, class Pred = less<T> >
	class priority_queue
	{
	public:
		typedef T value_type;
		typedef size_t size_type;
		priority_queue()
		{}
		priority_queue(const value_type *first, const value_type *last)
		{
			while (first != last)
				c.push_back(*first++);
			int root = (c.size() - 1) / 2; //找到二叉树的最后面一个需要向下调的节点
			while (root >= 0)
				adjustdown(root--);
		}
		bool empty() const
		{
			return c.empty();
		}
		size_type size() const
		{
			return c.size();
		}
		value_type& top()
		{
			assert(!empty());
			return c.front();
		}
		const value_type& top() const
		{
			assert(!empty());
			return c.front();
		}
		void push(const value_type &x)
		{
			c.push_back(x);
			adjustup(c.size() - 1);
		}
		void pop()
		{
			std::swap(c.front(), c.back());
			c.pop_back();
			adjustdown(0);
		}
	protected:
		void adjustdown(int parent)
		{
			int child = 2 * parent + 1;
			while (child < c.size())
			{
				if (child + 1 < c.size() && comp(c[child], c[child + 1]))
					++child;
				if (comp(c[parent], c[child])) //-->comp.operator(c[parent], c[chid])
				{
					std::swap(c[parent], c[child]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
					break;
			}
		}
		void adjustup(int child)
		{
			int parent = (child - 1) / 2;
			while (child)
			{
				if (comp(c[parent], c[child]))
				{
					std::swap(c[parent], c[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
	private:
		Cont c;
		Pred comp;
	};
}




