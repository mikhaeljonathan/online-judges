#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	long int m;
	long int max=-100001;;
	long int min=100001;
	for (int a=1; a<=n; a++)
	{
		cin>>m;
		if (m<min)
		{
			min=m;
		}
		if (m>max)
		{
			max=m;
		}
	}
	cout<<max<<" "<<min<<endl;
	return 0;
}
