#include<iostream>

using namespace std;

class example
{
	public:
		example()
		{
			cout<<"Default"<<endl;
		}
		example(int x)
		{
			cout<<"Parameter"<<endl;
		}
};
int main()
{
	example e0; 
	e0(8);
}
