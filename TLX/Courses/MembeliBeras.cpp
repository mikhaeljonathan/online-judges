#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	//input
	int n;
	long int x;
	cin>>n>>x;
	int w[n], c[n];
	for (int temp=0; temp<n; temp++)
	{
		cin>>w[temp];
	}
	for (int temp2=0; temp2<n; temp2++)
	{
		cin>>c[temp2];
	}
	
	//count the price per kg
	double wf[n];
	for (int temp3=0; temp3<n; temp3++)
	{
		wf[temp3] = w[temp3]*1.0; //times 1.0 to make a double value
	}
	
	double price[n];
	for (int temp4=0; temp4<n; temp4++)
	{
		price[temp4] = c[temp4]/wf[temp4];
	}
	
	//take it
	long int weight=0;
	double money=0.00000;
	while (weight<x)
	{
		//identify the index of the max value of price
		int index=0; 
		double max=price[index];
		for (int temp5=1; temp5<n; temp5++)
		{
			if ((max<price[temp5])&&(w[temp5]!=0))
			{
				max=price[temp5];
				index=temp5;
			}
		}
		
		w[index]--; //the weight of the max value reduced by 1 because we take it
		weight++; //and move the weight to variable "weight"
		money+=price[index]; //the total money
		if (w[index]==0) //if the weight of max value is 0, change the price to 0 to prevent the first element that considered as max value (at line 39 and 40)
		{
			price[index]=0.00000;
		}
	}
	cout<<setprecision(5)<<fixed;
	cout<<money<<endl;
	return 0;
}
