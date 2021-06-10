#include <iostream>
using namespace std;

int main ()
{
	int a,b;
	char op;
	cin>>a>>op>>b;
	if ((op=='+')||(op=='-')||(op=='*'))
	{
		switch (op)
		{
			case '+': cout<<a+b; break;
			case '-': cout<<a-b; break;
			case '*': cout<<a*b; break;
		}
	}
	else
	{
		switch (op)
		{
			case '<': 	if (a<b) 
						{
							cout<<"benar";
						} 
						else
						{
							cout<<"salah";
						}
						break;
			case '>': 	if (a>b) 
						{
							cout<<"benar";
						} 
						else
						{
							cout<<"salah";
						}
						break;
			case '=': 	if (a==b)
						{
							cout<<"benar";
						}
						else
						{
							cout<<"salah";
						}
						break;
		}
	}
	cout<<endl;
	return 0;
}
