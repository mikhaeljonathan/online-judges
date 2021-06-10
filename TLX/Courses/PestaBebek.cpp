#include <iostream>
using namespace std;
void swap(string *x, string *y);

int main ()
{
	int n;
	cin>>n;
	string name[n];
	for (int temp=0; temp<n; temp++)
	{
		cin>>name[temp];
		int pos = temp;
		while ((pos>0)&&(name[pos]<name[pos-1]))
		{
			swap(name[pos],name[pos-1]);
			pos--;
		}
		cout<<pos+1<<endl;
	}
	return 0;
}

void swap(string *x, string *y)
{
	string temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
