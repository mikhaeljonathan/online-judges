#include <iostream>
using namespace std;

int main()
{
	long int n;
	cin>>n;
	long int num=1;
	bool found = false;
	while (num<=n)
	{
		num = num*2;
		if (num==n)
		{
			found=true;
		}
	}
	if ((found) or (n==1))
	{
		cout<<"ya"<<endl;
	}
	else
	{
		cout<<"bukan"<<endl;
	}
}
