#include <iostream>
using namespace std;
long int f(int n);

int main ()
{
	int n;
	cin>>n;
	if ((n>=0)&&(n<=10))
	{
		cout<<f(n);
	}
	else
	{
		cout<<"ditolak";
	}
	cout<<endl;
	return 0;
}

long int f (int n)
{
	if (n==0)
	{
		return 1;
	}
	else
	{
		return n*f(n-1);
	}
}
