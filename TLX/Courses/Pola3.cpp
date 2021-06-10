#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	int num=0;
	for (int a=0;a<n;a++)
	{
		for (int b=0;b<=a;b++)
		{
			cout<<num;
			num++;
			if (num==10)
			{
				num=0;
			}
		}
		cout<<endl;
	}
}
