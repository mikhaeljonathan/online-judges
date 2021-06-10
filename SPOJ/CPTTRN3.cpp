#include <iostream>
using namespace std;
void boom(int kolom, int baris);

int main()
{
	int t;
	cin>>t;
	for (int tcase=1;tcase<=t;tcase++)
	{
		int baris,kolom;
		cin>>baris>>kolom;
		boom(kolom,baris);
		cout<<endl;
	}
}

void boom(int kolom, int baris)
{
	int kolom2 = kolom*3+1;
	for (int a=1;a<=baris;a++)
	{
		for (int b=1;b<=kolom2;b++)
		{
			cout<<"*";
		}
		cout<<endl;
		for (int c=1;c<=2;c++)
		{
			for (int d=1;d<=kolom;d++)
			{
				cout<<"*..";
			}
			cout<<"*"<<endl;
		}
	}
	for (int e=1;e<=kolom2;e++)
	{
		cout<<"*";
	}
	cout<<endl;
}
