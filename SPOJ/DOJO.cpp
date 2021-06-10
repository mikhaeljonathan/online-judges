#include <iostream>
#include <string.h>
using namespace std;
int tointeger(char x[]);

int main ()
{
	int t;
	cin>>t;
	for (int tcase=1; tcase<=t; tcase++)
	{
		int i,n;
		char j[1000000];
		char m[1000000];
		cin>>n>>m>>i>>j;
		int temp = n%10;
		int temp2 = tointeger(m);
		if ((temp%2==1)&&(temp2%2==1))
		{
			int temp3 = i%10;
			int temp4 = tointeger(j);
			if ((temp3+temp4)%2==0)
			{
				cout<<"Possible.";
			}
			else
			{
				cout<<"Impossible.";
			}
		}
		else
		{
			cout<<"Impossible.";
		}
		cout<<endl;
	}
	return 0;
}

int tointeger(char x[])
{
	int temp = strlen(x);
	return (int)x[temp-1]-48;
}
