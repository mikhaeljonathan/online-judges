#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int tcase=1;tcase<=t;tcase++)
	{
		long long int k;
		cin>>k;
		long long int result = 192+((k-1)*250);
		cout<<result<<endl;
	}
	return 0;
}
