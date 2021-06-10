#include <iostream>
using namespace std;
long long int factorial(int n);

int main()
{
	int t;
	cin>>t;
	for (int tcase=1; tcase<=t; tcase++)
	{
		int n;
		cin>>n;
		cout<<factorial(n)<<endl;
	}
	return 0;
}

long long int factorial(int n)
{
	if (n==0)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}
