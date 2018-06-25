#include<iostream>

using namespace std;

void print(void*, int);

int main()
{
	int i;
	int no = 2;
	print(&no,2);
}

void print(void *n, int size)
{
	if(size> 0 )
	{
	 	char* c = (char *)n;

		print(c++, --size);
                cout<<(char)*c;
	}
	return;
}
