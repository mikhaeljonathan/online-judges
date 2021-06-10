#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n!=-1)
	{
		int data[n];
		int sum=0;
		int move=0;
		for(int a=0;a<n;a++)
		{
			cin>>data[a];
			sum = sum + data[a];
		}
		if (sum%n==0)
		{
			int average = sum/n;
			for (int b=0;b<n;b++)
			{
				if (data[b]>average)
				{
					int remain = data[b]-average;
					move = move + remain;
				}
			}
			cout<<move<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
		cin>>n;
	}
	return 0;
}
