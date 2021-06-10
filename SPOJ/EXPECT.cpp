#include <iostream>
using namespace std;

int main ()
{
	long long int num;
	bool fourtytwo = false;
	while (!fourtytwo)
	{
		cin>>num;
		cout<<num<<endl;
		if (num==42)
		{
			fourtytwo = true;
		}
	}
	return 0;
}
