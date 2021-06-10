#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	long double num[n];
	double total=0.00;
	for (int a=0; a<n; a++)
	{
		cin>>num[a];
		total+=num[a];
	}
	double min=num[0];
	double max=num[0];
	for (int a=1; a<n; a++)
	{
		if (num[a]<min)
		{
			min=num[a];
		}
		if (num[a]>max)
		{
			max=num[a];
		}
	}
	double temp=n*1.0;
	double average=total/temp;
	cout<<setprecision(2)<<fixed;
	cout<<min<<" "<<max<<" "<<average<<endl;
	return 0;
}
