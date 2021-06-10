#include <iostream>
using namespace std;
void f(int n, int depth);
int num[1000000];
bool ever[1000000];

int main ()
{
	int n;
	cin>>n;
	f(n,0);
	return 0;
}

void f(int n, int depth)
{
	if (depth>=n)
	{
		bool zigzag=false;
		int counter=0;
		for (int a=1; a<n-1; a++)
		{
			if (((num[a]<num[a-1])&&(num[a]<num[a+1]))||((num[a]>num[a-1])&&(num[a]>num[a+1])))
			{
				counter++;
			}
		}
		if ((counter==n-2)||(n==2)||(n==1))
		{
			for (int i=0; i<n; i++)
			{
			cout<<num[i];
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
				f(n,depth+1);
				ever[i] = false;
			}
		}
	}
}
