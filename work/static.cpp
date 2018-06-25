#include<iostream>	

using namespace std;

class A
{
	static int a;
	public:
		int b;
		static void display()
		{
			cout<<a;
		}
};

int A:: a;

int main()
{
	//A aobj;
	//cout<<aobj.a;	
	A::display();
	return 0;
}

