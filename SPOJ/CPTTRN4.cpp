#include <iostream>
using namespace std;
void fullbaris(int c2);
void hasil(int l, int c, int h, int w);

int main()
{
	int t;
	cin>>t;
	for(int tcase=1;tcase<=t;tcase++)
	{
		int l,c,h,w;
		cin>>l>>c>>h>>w;
		hasil(l,c,h,w);
		cout<<endl;
	}
	return 0;
}

void hasil(int l, int c, int h, int w)
{
	int c2=(w+1)*c+1;
	for (int temp=1;temp<=l;temp++)
	{
		fullbaris(c2);
		for (int temp2=1;temp2<=h;temp2++)
		{
			for (int temp3=1;temp3<=c;temp3++)
			{
				cout<<"*";
				for (int temp4=1;temp4<=w;temp4++)
				{
					cout<<".";
				}
			}
			cout<<"*"<<endl;
		}
	}
	fullbaris(c2);
}

void fullbaris(int c2)
{
	for (int temp=1;temp<=c2;temp++)
	{
		cout<<"*";
	}
	cout<<endl;
}
