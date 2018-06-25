#include<iostream>

using namespace std;

class A
{
	protected:
		int a;

};

class B: virtual public A
{
	private: 
		int b;
};

class C: virtual public A
{
	private:
		int c;
};

class D: public B, C
{
	private:
		int d;

	public:
		void display()
		{
			cout<<a;
		}
};

int main()
{
	D d;
	d.display();

	cout<<"A = "<<sizeof(A)<<endl<<"B= "<<sizeof(B)<<endl<<"C= "<<sizeof(C)<<endl<<"D= "<<sizeof(D)<<endl;

	return 0;
}
