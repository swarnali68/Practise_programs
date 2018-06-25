#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	int &b;
	int &c = b;

	cout<<c<<endl;

	return 0;
}
