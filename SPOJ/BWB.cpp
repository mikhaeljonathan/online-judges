#include <iostream>
using namespace std;
long long int func(int n, int k);
long long int a=1;
long long int answer=0;

int main ()
{
	long long int t;
	cin>>t;
	while (t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<func(n,k)%1000000007<<endl;
	}
	return 0;
}

long long int func(int n, int k)
{
	if (k==1)
	{
		return 1;
	}
	if (n<=k)
	{
		long long int temp=1;
		for (int a=1; a<n; a++)
		{
			temp*=2;
		}
		return temp;
	}
	else
	{
		while (a<=k)
		{
			answer=answer+func(n-a,k);
			a++;
		}
		return answer;
	}
}
