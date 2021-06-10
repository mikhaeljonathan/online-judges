#include <iostream>
using namespace std;

int main ()
{
	long int n[101];
	int i=0;
	while (cin>>n[i])
	{
		i++;
	}
	for (int a=i-1;a>=0;a--)
	{
		cout<<n[a]<<endl;
	}
}
