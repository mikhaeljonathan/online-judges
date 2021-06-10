#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	int total=0;
	for (int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		total = total + b;
	}
	cout<<total<<endl;
}
