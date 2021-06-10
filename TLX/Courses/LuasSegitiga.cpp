#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x; int y;
	cin>>x>>y;
	double broad;
	broad=x*y/2.0;
	cout<<setprecision(2)<<fixed;
	cout<<broad<<endl;
	return 0;
}
