#include <iostream>
using namespace std;

int main ()
{
	int n,m,p;
	cin>>n>>m>>p;
	int a[n][m];
	int b[m][p];
	int c[n][p];
	for (int aa=0;aa<=n-1;aa++)
	{
		for (int b=0;b<=m-1;b++)
		{
			cin>>a[aa][b];
		}
	}
	for (int c=0;c<=m-1;c++)
	{
		for (int d=0;d<=p-1;d++)
		{
			cin>>b[c][d];
		}
	}
	for (int d=0;d<=n-1;d++)
	{
		for (int e=0;e<=p-1;e++)
		{
			c[d][e]=0;
			for (int f=0;f<=m-1;f++)
			{
				c[d][e] = c[d][e] + (a[d][f]*b[f][e]);
			}
		}
	}
	for (int g=0;g<=n-1;g++)
	{
		for (int h=0;h<=p-1;h++)
		{
			cout<<c[g][h];
			if (h!=p-1)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
