#include <iostream>
using namespace std;
void draw(int x);

int main ()
{
	int n;
	cin>>n;
	draw(n);
	return 0;
}

void draw(int x)
{
	if (x==1)
	{
		cout<<"*"<<endl;
	}
	else
	{
		draw(x-1);
		for (int i=1;i<=x;i++)
		{
			cout<<"*";
		}
		cout<<endl;
		draw(x-1);
	}
}
