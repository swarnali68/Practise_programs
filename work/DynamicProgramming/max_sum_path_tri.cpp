#include<iostream>

#define N 3 

using namespace std;

int max_path_sum(int tri[N][N])
{
	int i;
	int j;

	for(i= N-2; i >=0; i--)
	{
		for(j=0; j<=i; j++)
		{
			tri[i][j] = tri[i][j] + max(tri[i+1][j], tri[i+1][j+1]);
		}	
	}
	return tri[0][0];	
}

int main()
{
	/*int tri[N][N] = {{3,0,0,0},
			 {3,7,0,0},
			 {8,5,6,0},
			 {6,1,9,3}};*/
	/*int tri[N][N] = {{2,0,0},
			 {3,9,0},
			 {1,6,7}};*/
	int tri[N][N] = {  {1, 0, 0},
                      {4, 8, 0},
                      {1, 5, 3} };
	
	cout<<max_path_sum(tri);

	return 0;
}
