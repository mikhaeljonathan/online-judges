#include <iostream>
using namespace std;
void doit(int n, int k, int depth);
int num[1000];
bool ever[1000];

int main ()
{
	int n,k;
	cin>>n>>k;
	doit(n,k,0);
	return 0;
}

void doit(int n, int k, int depth)
{
	if (depth==k)
	{
		bool ascending=true;
		int a=0;
		while ((ascending)&&(a<k-1))
		{
			if (num[a]>num[a+1])
			{
				ascending=false;
			}
			a++;
		}
		
		if (ascending)
		{
			for(int i=0; i<depth; i++)
			{
				cout<<num[i];
				if (i!=depth-1)
				{
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
	else
	{
		for (int i=0; i<n; i++)
		{
			if (!ever[i])
			{
				ever[i] = true;
 				num[depth] = i+1;
				doit(n,k,depth+1);
				ever[i] = false;
			}	
		}
	}
}
