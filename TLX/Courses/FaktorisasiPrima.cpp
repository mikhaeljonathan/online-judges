#include <iostream>
#include <math.h>
using namespace std;
long int theNextPrime(long long int x);

int main ()
{
	long long int n;
	cin>>n;
		int j=1;
		long long int divider=2;
		while(n>1)
		{
			if (n%divider==0)
			{
				if (j>1)
				{
					cout<<" x ";
				}
				int i=0;
				while (n%divider==0)
				{
					i=i+1;
					n = n/divider;
					if (i==1)
					{
					cout<<divider;
					}
					else if (i==2)
					{
						cout<<"^";
					}
				}
				if (i>1)
				{
					cout<<i;
				}
				j=j+1;
			}
			divider = theNextPrime(divider);
		}
	cout<<endl;
	return 0;
}

long int theNextPrime(long long int x)
{
	int i = 0;
	bool prime = false;
	while (!(prime))
	{
		x=x+1;
		if ((x%2==0)&&(x!=2))
		{
			continue;
		}
		for (long int a=3; a<=sqrt(x); a++)
		{
			if (x%a==0)
			{
				continue;
			}
		}
		prime=true;
	}
	return x;
}
