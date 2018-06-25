#include<iostream>

using namespace std;

int main()
{
	int i=5;
	int j=10;

	do
	{
		cout<<i;

		if(i == j)
		{
			i = 100;
			continue;
		}
		i++;
	}while(i<=j);

	return 0;
}
