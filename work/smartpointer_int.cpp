#include<iostream>

using namespace std;

template <class T>
class smartpointer
{
	private:
		T *ptr;
	public:
		smartpointer(T *p = NULL)
		{
			ptr = p;
		}
		
		int* operator->()
		{
			return ptr;
		}
		
		int& operator*()
		{
			return *ptr;
		}
		
		~smartpointer()
		{
			delete ptr;
		}
};

int main()
{
	smartpointer<int> sp(new int());
	*sp = 20;
	cout<<*sp;	
	
}
