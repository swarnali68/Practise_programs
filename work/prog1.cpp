#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char* fun()
{
	char p[10] = {'\0'};
	strcpy(p, "abcdef");
	cout<<"In fun"<<*((int *)p)<<endl;
	return (char*) p;
}

int main()
{
        //void* ptr = fun();
	//cout<< (void*) (fun()) <<endl;
	//cout<< ptr <<endl;
	//printf("%s",fun());
	return 0;
}
