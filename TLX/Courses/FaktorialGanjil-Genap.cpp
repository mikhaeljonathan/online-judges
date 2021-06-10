#include <iostream>
using namespace std;
long int f(int n);

int main ()
{
	int n;
	cin>>n;
	long int result = f(n);
	cout<<result<<endl;
	return 0;
}

long int f(int n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		if (n%2==0)
		{
			return n/2*f(n-1);
		}
		else
		{
			return n*f(n-1);
		}
	}
}
