#include<iostream>

using namespace std;

class Final;

class MakeFinal
{
	private:
		MakeFinal()
		{
			cout<<"Base"<<endl;
		}
	friend class Final;
};

class Final: virtual MakeFinal
{
	public:
		Final()
		{
			cout<<"Derived"<<endl;
		}
};

/*class Derived2: public Derived
{
	public:
		Derived2()
		{
			cout<<"Derived2"<<endl;
		}
};*/
int main()
{
	Final f;
	return 0;
}
