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
		bool prime = false;
		int count = 0;
		cin>>num;
		for (long int divider=2; divider<=sqrt(num); divider++)
		{
			if (num%divider==0)
			{
				count = count+1;
			}
		}
		if (count<=1)
		{
			prime = true;
		}
		if (prime)
		{
			cout<<"YA"<<endl;
		}
		else
		{
			cout<<"BUKAN"<<endl;
		}
	}
}
