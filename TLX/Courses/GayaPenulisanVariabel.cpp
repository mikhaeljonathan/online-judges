#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	char s[100],ans[100];
	cin>>s;
	bool snakecase, camelcase, temp = false;
	int a=0;
	while ((!temp)&&(a<=strlen(s)-1))
	{
		if (s[a]=='_')
		{
			snakecase, temp = true;
		}
		else if ((int(s[a])<=90)&&(int(s[a])>=65))
		{
			camelcase, temp = true;
		}
		a++;
	}
	if (snakecase)
	{
		int b=0;
		bool underscores = false;
		while (s.find('_')>=0)
		{
			if (s[b]=='_')
			{
				underscores = true;
			}
			b++;
		}
		b = b-1;
		
	}
	else if (camelcase)
	{
		
	}
	else
	{
		
	}
}

