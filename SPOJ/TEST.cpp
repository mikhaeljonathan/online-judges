#include <iostream>
using namespace std;

int main() 
{
	int x;
	bool trig=true;
	while (trig)
	{
		cin>>x;
		if (x==42)
		{
			trig=false;
		}
		else
		{
			cout<<x<<endl;
		}
	}
	return 0;
}
