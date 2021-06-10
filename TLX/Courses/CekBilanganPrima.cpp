#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	for (int a=1; a<=n; a++)
	{
		long int num;
		bool prime=true;
		int count = 0;
		cin>>num;
		if ((num%2==0)&&(num!=2))
		{
			prime=false;
		}
		else
		{
			for (int a=3; a<=sqrt(num); a++)
			{
				if (num%a==0)
				{
					prime=false;
					break;
				}
			}
		}
		if ((prime)&&(num!=1))
		{
			cout<<"YA";
		}
		else
		{
			cout<<"BUKAN";
		}
		cout<<endl;
	}
}
