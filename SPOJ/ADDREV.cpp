#include <iostream>
using namespace std;
int reverse (int x);

int main ()
{
	int n;
	cin>>n;
	for (int tcase=1; tcase<=n; tcase++)
	{
		int j,k;
		cin>>j>>k;
		cout<<reverse(reverse(j)+reverse(k))<<endl;
	}
	return 0;
}

int reverse(int x)
{
	int temp = x;
	int ret = 0;
	while (temp>0)
	{
		ret = (ret*10) + (temp%10);
		temp = temp/10;
	}
	return ret;
}
