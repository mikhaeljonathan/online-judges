#include <iostream>
using namespace std;

int main ()
{
	int n,m;
	cin>>n>>m;
	int num[n][m];
	for (int a=0;a<=n-1;a++)
	{
		for (int b=0; b<=m-1;b++)
		{
			cin>>num[a][b];
		}
	}
	for (int c=0;c<=m-1;c++)
	{
		for (int d=n-1;d>=0;d--)
		{
			cout<<num[d][c];
			if (d!=0)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
