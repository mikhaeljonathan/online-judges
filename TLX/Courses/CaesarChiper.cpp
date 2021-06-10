#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	char s[100];
	int ascii[100];
	int k;
	cin>>s>>k;
	int temp = strlen(s)-1;
	for (int a=0;a<=temp;a++)
	{
		ascii[a] = int (s[a]);
	}
	for (int b=0;b<=temp;b++)
	{
		ascii[b] = ascii [b] + k;
		if (ascii[b]>=123)
		{
			ascii[b] = ascii[b]-26;
		}
	}
	for (int c=0;c<=temp;c++)
	{
		s[c] = (char)ascii[c];
	}
	cout<<s<<endl;
	return 0;
}
