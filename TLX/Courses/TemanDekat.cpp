#include <iostream>
using namespace std;
void read(int n,int x[],int y[]);
int func(int x[], int y[], int d, int a, int b);
int absx(int x[], int a, int b);
int absy(int y[], int a, int b);

int main ()
{
	int n,d;
	cin>>n>>d;
	int x[n],y[n];
	int min,max;
	
	read(n,x,y);
	min = func(x,y,d,1,2);	
	max = func(x,y,d,1,2);
	for (int a=1;a<=n-1;a++)
	{
		for (int b=a+1;b<=n;b++)
		{
			if (func(x,y,d,a,b)<=min)
			{
				min = func (x,y,d,a,b);
			}
			if (func(x,y,d,a,b)>=max)
			{
				max = func (x,y,d,a,b);
			}
		}
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}

void read(int n, int x[], int y[])
{
	for (int a=0; a<=n-1; a++)
	{
		cin>>x[a]>>y[a];
	}
}

int func(int x[], int y[], int d, int a, int b)
{
	int resultx = 1;
	int resulty = 1;
	for (int temp=1;temp<=d;temp++)
	{
		resultx = resultx * absx(x,a,b);
		resulty = resulty * absy(y,a,b);
	}
	int result = resultx + resulty;
	return result;
}

int absx(int x[], int a, int b)
{
	int result = x[a-1]-x[b-1];
	if (result<0)
	{
		result = -result;
	}
	return result;
}

int absy(int y[], int a, int b)
{
	int result = y[a-1]-y[b-1];
	if (result<0)
	{
		result = -result;
	}
	return result;
}
