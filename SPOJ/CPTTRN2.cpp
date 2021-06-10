#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i;
	cin>>i;
	for (int j=1;j<=i;j++)
	{
		int x,y;
		cin>>x>>y;
		for (int a=1;a<=x;a++)
		{
			for (int b=1;b<=y;b++)
			{
				if (1<a && a<x && 1<b && b<y)
				{
					cout<<".";
				}
				else
				{
					cout<<"*";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
