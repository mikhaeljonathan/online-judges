#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int a,d;
	cin>>a>>d;
	while ((a!=0)&&(d!=0))
	{
		long int b[a];
		long int c[d];
		for (int temp=0; temp<a; temp++)
		{
			cin>>b[temp];
		}
			for (int temp2=0; temp2<d; temp2++)
		{
			cin>>c[temp2];
		}
		sort(c,c+d);
		
		long int min = c[1];
		bool offside = false;
		int e=0;
		while ((!offside)&&(e!=a))
		{
			if (b[e]<min)
			{
				offside = true;
			}
			e++;
		}
		
		if (offside)
		{
			cout<<"Y";
		}
		else
		{
			cout<<"N";
		}
		cout<<endl;
		cin>>a>>d;
	}
	
	return 0;
}
