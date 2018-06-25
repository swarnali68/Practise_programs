#include<iostream>

using namespace std;

void copy_func(void *b, void* a, size_t n)
{
	int i;
	char* src = (char *)a;
	char* dest = (char*)b;

	for(i=0; i<n; i++)
	{
		*dest = *src;
		src++;
		dest++;		
	}
}

int main()
{
	int a =4;
	int b;

	copy_func(&b, &a, 4);

	cout<<b<<endl;
}
