#include <iostream>
using namespace std;
void go(long int n);

int main ()
{
	long int n;
	while (cin>>n)
	{
		go(n);
	}
	return 0;
}

void go (long int n)
{
	int digit=0;
	while (n>=1)
	{
		n/=10;
		digit++;
	}
	switch(digit)
	{
		case 1:	cout<<"satuan";
				break;
		case 2:	cout<<"puluhan";
				break;
		case 3:	cout<<"ratusan";
				break;
		case 4: cout<<"ribuan";
				break;
		case 5: cout<<"puluhribuan";
				break;
	}
	cout<<endl;
}
