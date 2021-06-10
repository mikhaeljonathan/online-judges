#include<iostream>
using namespace std;

int main ()
{
	int n[25000];
	int i=0;
	while (cin>>n[i])
	{
		i++;
	}
	for (int a=i-1; a>=0; a--)
	{
		cout<<n[a]<<endl;
	}
	return 0;
}
