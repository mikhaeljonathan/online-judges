#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	for (int a=1;a<=n;a++)
	{
		if (a%10==0)
		{
			continue;
		}
		else if (a==42)
		{
			cout<<"ERROR"<<endl;
			break;
		}
		else
		{
			cout<<a<<endl;
		}
	}
}
