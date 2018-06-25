#include<iostream>

using namespace std;

class A
{
	private:
		int p;

	public:
		//A(){}
		A(int v = 0)
		{
			cout<<"In paramterised constructor";
			p = v;
			cout<<p;
		}
};

int main()
{
	A b;
	//A a(20);
	return 0;	
}
