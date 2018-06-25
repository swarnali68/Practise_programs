#include<iostream>

using namespace std;

typedef char CHARPTR[10];

int main()
{
        CHARPTR ab;
        cout<< sizeof(ab)<<endl;
	cout<<sizeof(CHARPTR)<<endl;
	cout<<sizeof(char)<<endl;
	return 0;
}
