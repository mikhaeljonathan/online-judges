#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	string x;
	getline(cin, x);
	int length=0;
	int i=0;
	while (x[i]!='\0')
	{
		length++;
		i++;
	}
	for (int a=length-1; a>=0; a--)
	{
		cout<<x[a];
	}
	cout<<endl;
	return 0;
}
