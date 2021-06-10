#include <iostream>
using namespace std;
long int reverse(long int x);

int main ()
{
	long int a,b;
	cin>>a>>b;
	cout<<reverse(reverse(a)+reverse(b))<<endl;
	
}

long int reverse (long int x)
{
	long int temp=x;
	int ret = 0;
	while (temp>0)
	{
		ret = (ret*10) + (temp%10);
		temp = temp/10;
	}
	return ret;
}
