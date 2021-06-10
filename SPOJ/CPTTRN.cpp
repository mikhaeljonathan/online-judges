#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i;
	cin>>i;
	if (i<100)
	{
		for (int a=1;a<=i;a++)
		{
			int x,y;
			cin>>x>>y;
			for (int b=1;b<=x;b++)
			{
				if (b%2==1)
				{
					for (int c=1;c<=y;c++)
					{
						if (c%2==1)
						{
							cout<<"*";
						}
						else
						{
							cout<<".";
						}	
					}
				}
				if (b%2==0)
				{
					for (int d=1;d<=y;d++)
				    {
				   		if (d%2==1)
				   		{
				   			cout<<".";
				   		}
				   		else
				   		{
				   			cout<<"*";
				   		}
				   }
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}
