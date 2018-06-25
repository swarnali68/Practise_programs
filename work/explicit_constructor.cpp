#include<iostream>
#include<string.h>

using namespace std;

class Entity
{
	char* name;
	int age;
	public:
		Entity(){}
		/*Entity(const char* n, int a)
		{
			strcpy(name,  n);
			age = a;
		}*/
		explicit Entity(const char* n)
		{
			name = new char[strlen(n) + 1];
			strcpy(name,  n);
			age = -1;
		}
		explicit Entity(int a)
		{
			name = new char[8];
			strcpy(name,  "unknown");
			age = a;
		}
		void display();
};

void Entity::display()
{
	cout<<name<<endl<<age<<endl;
}

int main()
{
	//Entity E = "swarnali", 20;
	//Entity E1 = "swarnali";
	//Entity E2 = 22;
	Entity E3;
	E3 = "swarnali";
	//E.display();
	//E1.display();
	//E2.display();
	E3.display(); 
	return 0;
}
