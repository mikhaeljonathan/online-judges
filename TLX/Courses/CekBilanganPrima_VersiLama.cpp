#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	int num;
	while (cin>>num)
	{
		bool prime=true;
		int count = 0;
		if (num>0)
		{
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
		}
		else
		{
			prime=false;
		}
		
		if ((prime)&&(num!=1))
		{
			cout<<"YA";
		}
		else
		{
			cout<<"TIDAK";
		}
		cout<<endl;
	}
	return 0;
}
