#include<iostream>

using namespace std;

int main()
{
	const int age = 25;

	const int *a;

	a = new int();

	//*a = 20;

	a = &age;

	//*a = 900;

	cout<<*a<<endl<<age<<endl;
}
