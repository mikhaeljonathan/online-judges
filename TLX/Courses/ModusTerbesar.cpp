#include <iostream>
using namespace std;

int main ()
{
	long int n;
	cin>>n;
	int num[n];
	for (int a=0;a<n;a++)
	{
		cin>>num[a];
	}
	int max = num[0];
	for (int b=0;b<n;b++)
	{
		if (num[b]>max)
		{
			max = num[b];
		}
	}
	long int frek[max+1];
    for (int c=0;c<=max;c++)
    {
    	frek[c] = 0;
	}
	
	for (int d=0;d<=n-1;d++)
	{
		frek[num[d]] = frek[num[d]] + 1;
	}
	
	for (int e=1;e<=max;e++)
	{
		for (int f=e+1;f<=max;f++)
		{
			if ((frek[e]==frek[f])&&(e>f))
			{
				frek[f]=0;
			}
			else if ((frek[e]==frek[f])&&(f>e))
			{
				frek[e]=0;
			}
		}
	}
	
	long int frekmax = 0;
	int modus;
	for (int g=1;g<=max;g++)
	{
		if (frek[g]>frekmax)
		{
			frekmax = frek[g];
			modus = g;
		}
		
	}
	cout<<modus<<endl;
}
