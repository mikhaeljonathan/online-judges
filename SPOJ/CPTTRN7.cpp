#include <iostream>
using namespace std;

void hasil (int r, int c, int s);
void upper (int c, int s);
void lower (int c, int s);
void slash (int temp, int s);
void backslash (int temp, int s);

int main ()
{
	int t;
	cin>>t;
	for (int tcase=0; tcase<t; tcase++)
	{
		int r,c,s;
		cin>>r>>c>>s;
		hasil(r,c,s);
		cout<<endl;
	}
	return 0;
}

void hasil (int r, int c, int s)
{
	for (int rows=0; rows<r; rows++) //the number of rows
	{
		upper(c,s); //the upper of diamonds
		lower (c,s); //the lower of diamonds
	}
}

void upper (int c, int s)
{
	for (int temp=0; temp<s; temp++) // number of rows of upper
	{
		for (int subcolumn=0; subcolumn<c*2; subcolumn++) //column that timed by two to have a square shape
		{
			if (subcolumn%2==1)
			{
				backslash(temp,s);
			}
			else
			{
				slash(temp,s);
			}
		}
		cout<<endl;
	}
}

void lower (int c, int s)
{
	for (int temp=0; temp<s; temp++) //number of rows of lower
	{
		for (int subcolumn=0; subcolumn<c*2; subcolumn++) //column that timed by two to have a square shape
		{
			if (subcolumn%2==1)
			{
				slash(temp,s);
			}
			else
			{
				backslash(temp,s);
			}
		}
		cout<<endl;
	}
}

void backslash (int temp, int s)
{
	for (int backslash=0; backslash<s; backslash++)
	{
		if (temp==backslash)
		{
			cout<<"\\";
		}
		else
		{
			cout<<".";
		}
	}
}

void slash (int temp, int s)
{
	for (int slash=0; slash<s; slash++)
	{
		if (temp+slash==s-1)
		{
			cout<<"/";
		}
		else
		{
			cout<<".";
		}
	}
	
}
