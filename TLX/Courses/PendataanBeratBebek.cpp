#include <iostream>
using namespace std;

int main ()
{
	long int n;
	cin>>n;
	long long int data[n];
	for (int temp=0; temp<n; temp++)
	{
		cin>>data[temp];
	}
	long int q;
	cin>>q;
	long long int x,y;
	for (int temp2=0; temp2<q; temp2++)
	{
		cin>>x>>y;
		int counter=0;
		long int left=0;
		long int right=n;
		long int middle;
		bool found=false;
		while((!found)&&(left<=right))
		{
			middle = (left+right)/2;
			if ((data[middle]>x)&&(data[middle]<=y)) //in range
			{
				found=true;
				counter = counter+1;
			}
			else if ((data[middle]>x)&&(data[middle]>y)) //too high
			{
				right = middle-1;
			}
			else if ((data[middle]<=x)&&(data[middle]<=y)) //too low
			{
				left = middle+1;
			}
		}
		if(!found)
		{
			cout<<"0"<<endl;
		}
		else
		{
			long int middlelow = middle-1;
			long int middlehigh = middle+1;
			bool inrangelow = true;
			bool inrangehigh = true;
			while (inrangelow)
			{
				if ((data[middlelow]>x)&&(data[middlelow]<=y))
				{
					counter = counter+1;
				}
				else
				{
					inrangelow=false;
				}
				middlelow--;
			}
			while (inrangehigh)
			{
				if ((data[middlehigh]>x)&&(data[middlehigh]<=y))
				{
					counter = counter+1;
				}
				else
				{
					inrangehigh=false;
				}
				middlehigh++;
			}
			cout<<counter<<endl;
		}
	}
	return 0;
}
