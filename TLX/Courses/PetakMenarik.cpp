#include <iostream>
using namespace std;

int main ()
{
	int n,m,k;
	cin>>n>>m>>k;
	int num[n+2][m+2];
	
	for (int a=0;a<=n+1;a++)
	{
		for (int b=0;b<=m+1;b++)
		{
			if ((a==0)||(a==n+1)||(b==0)||(b==m+1))
			{
				num[a][b] = 1;
			}
		}
	}
	
	for (int c=1;c<=n;c++)
	{
		for (int d=1;d<=m;d++)
		{
			cin>>num[c][d];
		}
	}
	
	int ans[n][m];
	for (int e=0;e<=n-1;e++)
	{
		for (int f=0;f<=m-1;f++)
		{
			ans[e][f] = num[e][f+1] * num[e+1][f+2] * num[e+2][f+1] * num[e+1][f];
		}
	}
	
	bool found = false;
	int g=0;
	int h=0;
	while ((!found)&&(h<=m-1))
	{
		while ((!found)&&(g<=n-1))
		{
			if (ans[g][h]==k)
			{
				found=true;
			}
			g++;
		}
		h++;
		if(!found)
		{
			g=0;
		}
	}

	if (found)
	{
		cout<<g<<" "<<h<<endl;
	}
	else
	{
		cout<<"0 0"<<endl;
	}
	return 0;
}
