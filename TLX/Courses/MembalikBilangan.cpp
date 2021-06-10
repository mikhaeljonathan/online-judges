#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	long long int num[n];
	for (int a=0; a<n; a++)
	{
		cin>>num[a];
	}
	for (int a=0; a<n; a++)
	{
		long long int ret=0;
		while (num[a]>0)
		{
			ret = (ret*10) + (num[a]%10);
			num[a]/=10;
		}
		cout<<ret<<endl;
	}
	return 0;
}
