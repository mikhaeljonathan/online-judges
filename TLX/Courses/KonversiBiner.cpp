#include <iostream>
using namespace std;
void binaryof(long long int n);

int main ()
{
	long long int n;
	cin>>n;
	binaryof(n);
	cout<<endl;
	return 0;
}

void binaryof (long long int n)
{
	if (n==0)
	{
		cout<<"0";
	}
	else if (n==1)
	{
		cout<<"1";
	}
	else
	{
		binaryof(n/2);
		if (n%2==0)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
}
