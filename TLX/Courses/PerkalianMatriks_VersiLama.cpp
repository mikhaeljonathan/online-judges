#include <iostream>
using namespace std;

int main ()
{
	int a,b;
	cin>>a>>b;
	int num[a][b];
	for (int temp=0; temp<a; temp++)
	{
		for (int temp2=0; temp2<b; temp2++)
		{
			cin>>num[temp][temp2];
		}
	}

	int c,d;
	cin>>c>>d;
	int num2[c][d];
	for (int temp=0; temp<c; temp++)
	{
		for (int temp2=0; temp2<d; temp2++)
		{
			cin>>num2[temp][temp2];
		}
	}
	
	int result[a][d];
	for (int temp=0; temp<a; temp++)
	{
		for (int temp2=0; temp2<d; temp2++)
		{
			result[temp][temp2]=0;
			for (int temp3=0; temp3<b; temp3++)
			{
				result[temp][temp2] = result[temp][temp2] + (num[temp][temp3]*num2[temp3][temp2]);
			}
		}
	}
	
	for (int temp=0; temp<a; temp++)
	{
		for (int temp2=0; temp2<d; temp2++)
		{
			cout<<result[temp][temp2];
			if (temp2!=d-1)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
