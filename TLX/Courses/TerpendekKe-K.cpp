#include <iostream>
using namespace std;
void swap (long int *x, long int *y);

int main ()
{
	int n,k;
	cin>>n>>k;
	long int w[n];
	for (int temp=0; temp<n; temp++)
	{
		cin>>w[temp];
	}
	//selection sort
	int minindex;
	for (int temp2=0; temp2<k; temp2++)
	{
		minindex=temp2;
		for (int temp3=temp2+1; temp3<n; temp3++)
		{
			if (w[temp3]<w[minindex])
			{
				minindex = temp3;
			}
		}
		swap (w[temp2],w[minindex]);
	}
	cout<<w[k-1]<<endl;
	return 0;
}

void swap (long int *x, long int *y)
{
	long int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
