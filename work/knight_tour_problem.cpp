#include<iostream>
#include<unistd.h>
#include<iomanip>

using namespace std;

#define N 8

bool issafe(int x, int y, int sol[][N])
{
	//return (x<N && y<N && sol[x][y]==-1);
	return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == -1);
}

int solvekutil(int x, int y, int imove, int xmove[], int ymove[], int sol[][N])
{
	int k;
	int newx;
	int newy;

	if(imove == N*N)
		return 1;
	
	for(k=0; k<N; k++)
	{
		newx = x + xmove[k];
		newy = y + ymove[k];

		if(issafe(newx, newy, sol))
		{
			sol[newx][newy] = imove;
			if(solvekutil(newx, newy, imove+1, xmove, ymove, sol)==1)
				return 1;
			else
			{
				/*cout<<newx<<endl<<newy<<endl<<"imove = "<<imove<<endl;
				cout<<"Inside backtracking"<<endl;
				sleep(10);*/
				sol[newx][newy] = -1;
			}
		}
	}
	return 0;	
}

void printsolution(int sol[][N])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			//cout<<setw(2)<<sol[i][j]<<"\t";
			cout<<sol[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	int sol[N][N];
	int i;
	int j;
	int ret;

	for(i=0; i < N; i++)
	{
		for(j=0; j<N; j++)
		{
			sol[i][j] = -1;
		}
	}
	sol[0][0]=0;
	ret = solvekutil(0,0, 1, xMove,yMove, sol);
	if(ret)
	{
		printsolution(sol);
	}
	else
	{
		cout<<"Solution does not exist"<<endl;
	}

	return 0;
}
