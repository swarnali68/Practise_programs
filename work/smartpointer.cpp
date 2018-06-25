#include<iostream>

using namespace std;

class smartpointer
{
	private:
		int* ptr;
	public:
		explicit smartpointer(int  *p = 0)
		{
			cout<<"Inside constructor"<<endl;
			ptr = p;
		}
		int& operator*()
		{
			cout<<"At *"<<endl;
			return *ptr;
		}
		int* operator->()
		{
			cout<<"At ->"<<endl;
			return ptr;
		}
		~smartpointer()
		{
			delete ptr;
		}
};

int main()
{
	//smartpointer sp(new int());
	smartpointer sp =new int();
	cout<<"Calling *sp=20"<<endl;
	*sp = 20;
	//cout<<*sp;
	return 0;
}
