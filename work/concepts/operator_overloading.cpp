#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*class isOdd
{
	public:
		isOdd()
		{
			cout<<"Inside Constructor"<<endl;
		}
		int operator()()
		{
			cout<<"Inside Operator"<<endl;
			return 2; 
		}
};
int main()
{
	//isOdd obj;
	//obj();
	isOdd();
}*/

struct Accumulator
{
    int counter = 0;
    int operator()(int i) { return counter += i; }
};
int main()
{
/*Accumulator acc;
cout << acc(10) << endl; //prints "10"
cout << acc(20) << endl;*/
vector<int> col{1,3,5,7,8,9};
size_t c;
//c = count_if(col.begin(), col.end(), Accumulator());
//cout<<c<<endl;
c = Accumulator();
cout<<c<<endl;
}
