#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	int x;
	cin>>x;
	int i = 0;
	bool ok = false;
	while (!(ok))
	{
		x=x+1;
		for (int divider=2; divider<=sqrt(x); divider++)
		{
			if (x%divider==0)
			{
				i=i+1;
			}
		}
		if ((i<1)&&(x!=1))
		{
			ok = true;
		}
	}
	cout<<x;
}
