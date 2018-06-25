#include<iostream>

#define R 3
#define C 3

using namespace std;

int min(int x,int y,int z)
{
	if((x<y) && (x<z))
		return x;
	else if((y<x) && (y<z))
		return y;
	else
		return z;
}

int min_cost_path(int a[R][C],int m, int n)
{
	int tc[m][n];
	int i;
	int j;

	tc[0][0] = a[0][0];

	for(i=1; i<=m; i++)
	{
		tc[i][0] = tc[i-1][0] + a[i][0];	
	}

	for(j=1; j <=n; j++)
	{
		tc[0][j]= tc[0][j-1] + a[0][j];
	}

	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			tc[i][j] = a[i][j] + min(tc[i][j-1], tc[i-1][j-1],tc[i-1][j]);
		}
	}

	return tc[m][n];
	
	return 1;
}

int main()
{
	int m,n;
	int a[R][C]={1,3,4,
		     5,6,2,
		     8,10,9};
	cout<<"Enter the corodinates:";
	cin>>m>>n;

	cout<<min_cost_path(a,m,n)<<endl;

	return 0;
}
