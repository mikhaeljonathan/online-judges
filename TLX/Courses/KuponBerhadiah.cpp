#include <iostream>
using namespace std;
long int absolute (long int x);

int main ()
{
	int n;
	long int x;
	cin>>n>>x;
	long int num[n];
	for (int temp=0;temp<=n-1;temp++)
	{
		cin>>num[temp];
	}
	long int range[n];
	for (int temp3=0;temp3<=n-1;temp3++)
	{
		range[temp3] = absolute(num[temp3]-x);
	}
	for (int temp4=0;temp4<=n-2;temp4++)
	{
		if (range[temp4]==range[temp4+1])
		{
			if (num[temp4]<num[temp4+1])
			{
				range[temp4+1] = 999999;
			}
			else
			{
				range[temp4]=999999;
			}
		}
	}
	long int min = range[0];
	int i=0;
	for (int temp2=1;temp2<=n-1;temp2++)
	{
		if (range[temp2]<min)
		{
			min = range[temp2];
			i=temp2;
		}
	}
	cout<<num[i]<<endl;
	return 0;
}

long int absolute (long int x)
{
	if (x<0)
	{
		x = -x;
	}
	return x;
}
