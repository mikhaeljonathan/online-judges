#include <iostream>
using namespace std;
int func(int a, int b, int x);

int main ()
{
	int a,b,k,x;
	cin>>a>>b>>k>>x;
	int result = func(a,b,x);
	for (int temp=2;temp<=k;temp++)
	{
		result = func(a,b,result);
	}
	cout<<result<<endl;
}

int func(int a, int b, int x)
{
	int result = a*x+b;
	if (result<0)
	{
		result = -result;
	}
	return result;
}

