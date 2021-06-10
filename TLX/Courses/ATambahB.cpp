#include <iostream>
using namespace std;

int main ()
{
	int x,y;
	cin>>x>>y;
	if (((x >= 1 && x <= 100) && (y >= 1 && y <= 100)))
	{
		cout<<x+y<<endl;
	}	
	return 0;
}
