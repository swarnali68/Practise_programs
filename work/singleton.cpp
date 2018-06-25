#include<iostream>

using namespace std;

class Singleton
{
	private:
		bool static instanceFlag;
		static Singleton* single;
		Singleton();

	public:
		static Singleton* getInstance();
		void display();
		void deleteInstance();
		~Singleton();
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;

Singleton::Singleton()
{
}

Singleton* Singleton:: getInstance()
{
	if (!instanceFlag)
	{
		single = new Singleton;
		instanceFlag = true;
		return single;
	}
	else
	{
		return single;
	}
}

Singleton::~Singleton()
{
	single = NULL;
	instanceFlag = false;
}
void Singleton::deleteInstance()
{
	delete single;
}
void Singleton::display()
{
	cout<<"In display"<<endl;
}

int main()
{
	Singleton *s1;
	Singleton *s2;
	s1 = Singleton::getInstance();
	s2 = Singleton::getInstance();
	s1->display();
	s2->display();
	//Singleton::deleteInstance();
	return 0;
}
