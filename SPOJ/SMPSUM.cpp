#include <iostream>
using namespace std;

int square(int x);

int main() {
	// your code goes here
	int x,y;
	cin>>x>>y;
	int sum=0;
	if (1<=x<=y<=100)
	{
		for (int i=x;i<=y;i++)
		{
			int a;
			a = square(i);
			sum = sum + a;
		}
		cout<<sum;
	}
	return 0;
}

int square(int x)
{
	return x*x;
}
