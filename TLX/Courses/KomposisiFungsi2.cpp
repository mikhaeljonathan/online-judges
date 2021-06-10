#include <iostream>
using namespace std;
int f(int a, int b, int k, int x);
int abso(int x);

int main ()
{
	int a,b,k,x;
	cin>>a>>b>>k>>x;
	int result = f(a,b,k,x);
	cout<<result<<endl;
	return 0;
}

int f(int a, int b, int k, int x)
{
	if (k==1)
	{
		int result = a*x+b;
		return abso(result);
	}
	else
	{
		int result = a*f(a,b,k-1,x)+b;
		return abso(result);
	}
}

int abso(int x)
{
	if (x<0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}
