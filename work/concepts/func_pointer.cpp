#include<iostream>

using namespace std;

void HelloWorld()
{
	cout<<"Hello world"<<endl;
}

int main()
{
	auto fun = HelloWorld;
	
	fun();
}
