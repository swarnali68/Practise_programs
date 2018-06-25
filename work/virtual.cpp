#include<iostream>

using namespace std;

class Base
{
	int b;

	public:
		static virtual void fun()
		{
			this->b = 20;
			cout<<"hello";
		}
};

class Derived: public Base
{
	int a;
	private:

		void fun()
		{
			this->a = 10;
			cout<<"Derived";
		}
		/*void show()
		{
			cout<<"Derived Show";
		}*/
};

int main()
{
	Base* bptr = new Derived;
	bptr->fun();
	//bptr->show();
	/*Derived *d = new Derived();
	d->fun();*/
	return 0;
}
