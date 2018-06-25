#include<iostream>
#include<cstring>

using namespace std;

class Entity
{
	int age;
	string name;

	public:

		explicit Entity(const string n): name(n),age(-1){}
		
		explicit Entity(int a): age(a),name("unknown"){}

};
int main()
{
	//Entity E1 = string("swarnali");
	//Entity E2(22);
	Entity E3 ( "swarnali");
	return 0;
}
