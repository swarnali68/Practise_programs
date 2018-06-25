#include<iostream>

using namespace std;

class A
{
	public:
		int &a;
		int b;

	private:
		A():a(b){}
		A(int ax):a(ax){}

};

int main()
{
}
