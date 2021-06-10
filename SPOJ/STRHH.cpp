#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	int i;
	cin>>i;
	if (1<=i<=100)
	{
		for (int j=1;j<=i;j++)
		{
			char x[1000000];
			cin>>x;
			int leng;
			leng = strlen(x);
			if (leng%2==0)
			{
				int leng2;
				leng2 = leng/2;
				for (int k=0;k<=leng2-1;k=k+2)
				{
					cout<<x[k];
				}
				cout<<endl;
	     	}
		}
	}

}
