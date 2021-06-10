#include <iostream>
using namespace std;

int main ()
{
	int n,k;
    cin>>n>>k;
	for (int a=1;a<=n;a++)
	{
		if ((a%k==0)&&(a!=n))
		{			
			cout<<"* ";
		}
		else if ((a%k==0)&&(a==n))
		{
			cout<<"*"<<endl;
		}	
		else if (a==n)
		{
			cout<<a<<endl;
		}
		else
		{
			cout<<a<<" ";
		}
	}
	return 0;
}
