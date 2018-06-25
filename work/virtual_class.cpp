#include<iostream>

using namespace std;

class A
{
/*	public:
		virtual void show(){}*/
};

class B: virtual public A
{
	/*public:
	virtual void show(){}*/
};

class c: virtual public A 
{
};

class D: virtual public B,c
{
	public:
		void show(){}
};

int main()
{
	D b;
	cout<<sizeof(b)<<endl<<sizeof(D);
	return 0;
}
