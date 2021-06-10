#include <iostream>
using namespace std;
void swap (int x, int y);

int main ()
{
	int n;
	cin>>n;
	long int a[n],b[n];
	for (int temp=0;temp<=n-1;temp++)
	{
		cin>>a[temp];
	}
	for (int temp2=0;temp2<=n-1;temp2++)
	{
		cin>>b[temp2];
	}
	
	int q;
	cin>>q;
	for (int c=1;c<=q;c++)
	{
		char o,p;
		int x,y;
		cin>>o>>x>>p>>y;
		if ((o=='A')&&(p=='B'))
		{
			swap(a[x-1], b[y-1]);
		}
		else if ((o=='B')&&(p=='A'))
		{
			swap(b[x-1], a[y-1]);
		}
		else if ((o=='A')&&(p=='A'))
		{
			swap(a[x-1], a[y-1]);
		}
		else if ((o=='B')&&(o=='B'))
		{
			swap(b[x-1], b[y-1]);
		}
	}
	
	for (int d=0;d<=n-1;d++)
	{
		cout<<a[d];
		if (d!=n-1)
		{
			cout<<" ";
		}
	}
	cout<<endl;
	for (int e=0;e<=n-1;e++)
	{
		cout<<b[e];
		if (e!=n-1)
		{
			cout<<" ";
		}
	}
	cout<<endl;
	return 0;
}

void swap (int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

