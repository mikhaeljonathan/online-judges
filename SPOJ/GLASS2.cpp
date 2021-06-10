#include <iostream>
#include <math.h>
using namespace std;
long int sum (int x);

int main ()
{
	int n;
	cin>>n;
	cout<<sum(n);
	return 0;
}

long int sum(int x)
{
	if (x==1)
	{
		return 1;
	}
	else
	{
		return pow(x,2)+sum(x-1);
	}
}
