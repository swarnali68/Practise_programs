#include<iostream>
#include<cstring>
#include<vector>
#include<limits.h>

using namespace std;

int find_lcs(char *x, char *y, int m, int n, vector<char> &v)
{
	int i = 0;
	int j = 0;

	int L[m+1][n+1];
	int max_no = INT_MIN;

	for(i = 0; i <= m; i++)
	{
		for(j = 0; j <= n; j++)
		{
			if((i == 0) || (j == 0))
			{
				L[i][j] = 0;
			}
			else if(x[i-1] == y[j-1])
			{
				L[i][j] = L[i-1][j-1] + 1;

				if(L[i][j] > max_no)
				{
					v.push_back(x[i-1]);	
					max_no = L[i][j];
				}
			}
			else
			{
				L[i][j] = max(L[i][j-1], L[i-1][j]);
			}
		}
	}

	return (L[m][n]);
}

int main()
{
	char x[] = "AGGTAB";
	char y[] = "GXTXAYB";

	int lcs = 0;
	vector<char> v;
	int i;
	
	int m = strlen(x);
	int n = strlen(y);

	lcs = find_lcs(x,y, m, n, v);

	cout<<"Longest common Sunsequence: "<<lcs<<endl;

	for(i=0; i < v.size(); i++)
	{
		cout<<v[i];
	}

	cout<<endl;
	return 0; 
}
