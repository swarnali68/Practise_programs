#include<iostream>

using namespace std;

class A
{
};

class B: virtual public A
{
};


int main()
{
	cout<<sizeof(A)<<endl<<sizeof(B);
	return 0;
}
