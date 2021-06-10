#include <iostream>
#include <math.h>
using namespace std;
bool prime(long long int x);

int main ()
{
	int t;
	cin>>t;
	for (int tcase=1;tcase<=t;tcase++)
	{
		long long int m,n;
		cin>>m>>n;
		for (long long int num=m;num<=n;num++)
		{
			if (num==1)
			{
				continue;
			}
			if (prime(num))
			{
				cout<<num<<endl;
			}
		}
		cout<<endl;
	}
}

bool prime (long long int x)
{
	if ((x!=2)&&(x%2==0))
	{
		return false;
	}
	for (long long int a=3; a<=sqrt(x); a++)
	{
		if (x%a==0)
		{
			return false;
		}
	}
	return true;
}
