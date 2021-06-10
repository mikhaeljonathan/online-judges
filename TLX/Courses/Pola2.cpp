#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	for (int a=1;a<=n;a++)
	{
		for (int b=1;b<=n-a;b++)
		{
			cout<<" ";
		}
		for (int c=1;c<=a;c++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}
