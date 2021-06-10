#include <iostream>
using namespace std;

int main ()
{
	int tcase;
	cin>>tcase;
	for (int t=1;t<=tcase;t++)
	{
		int n,x,y;
		cin>>n>>x>>y;
		for (int num=1;num<n;num++)
		{
			if ((num%x==0) && (num%y!=0))
			{
				cout<<num<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
