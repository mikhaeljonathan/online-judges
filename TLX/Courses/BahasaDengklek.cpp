#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	char s[100];
	int ascii[100];
	cin>>s;
	for (int a=0;a<=strlen(s)-1;a++)
	{
		if(((int)s[a]<=90)&&((int)s[a]>=65))
		{
			ascii[a] = (int)s[a]+32;
		}
		else if (((int)s[a]<=122)&&((int)s[a]>=97))
		{
			ascii[a] = (int)s[a]-32;
		}
	}
	for (int b=0;b<=strlen(s)-1;b++)
	{
		s[b] = (char)ascii[b];
	}
	cout<<s<<endl;
	return 0;
}
