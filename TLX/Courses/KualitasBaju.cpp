#include <iostream>
#include <iomanip>
using namespace std;
void swap (int *x,int *y);

int main ()
{
	//read
	long int n;
	cin>>n;
	int qual[n];
	for (long int temp=0; temp<n; temp++)
	{
		cin>>qual[temp];
	}
	//sequence (counting sort)
	long int ftable[100000];
	for (long int temp3=0; temp3<100000; temp3++)
	{
		ftable[temp3] =0;
	}
	for (long int temp2=0; temp2<n; temp2++)
	{
		ftable[qual[temp2]] = ftable[qual[temp2]] + 1;
	}
	long int index=0;
	for (long int temp4=0; temp4<100000; temp4++)
	{
		for (long int temp5=1; temp5<=ftable[temp4]; temp5++)
		{
			qual[index]=temp4;
			index = index+1;
		}
	}
	//median
	cout<<setprecision(1)<<fixed;
	float median;
	if (n%2==1)
	{
		median=qual[n/2];
	}
	else
	{
		median = (qual[n/2-1] + qual[n/2]) / 2.0;
	}
	cout<<median<<endl;
	return 0;
}

void swap (int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
