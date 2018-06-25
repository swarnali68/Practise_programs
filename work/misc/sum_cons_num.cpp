#include <iostream>

using namespace std;

long countConsecutive(long num)
{
	long i;
	long count;
	long sum;
	long j;
	for(i=1; i<(num/2)+1; i++)
	{
		sum=0;
		j = i;
		while(sum < num)
		{
			cout<<j<<" + ";
			sum = sum + j;
			j++;
		}
		cout<<" = "<<sum<<endl;
		if(sum == num)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	long num;
	cout<<"Enter the number: ";
	cin>>num;

	cout<<countConsecutive(num);

	return 0;
}
