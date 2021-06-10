#include <iostream>
using namespace std;

int main ()
{
	string s;
	cin>>s;
	int digit=0;
	while(s[digit]!='\0')
		digit++;
	int a=0;
	int b=digit-1;
	int pair=0;
	while(a<=b)
	{
		if (s[a]==s[b])
		{
			pair++;
		}
		a++;
		b--;
	}
	cout<<pair<<endl;
}
