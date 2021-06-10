//SPOJ CPTTRN6
#include <iostream>
using namespace std;

void hasil (int l, int c, int h, int w);
void dotlines (int c, int h, int w);
void dots (int w);
void minuslines (int c, int h, int w);
void minuses(int w);


int main ()
{
	int t;
	cin>>t;
	for (int tcase=1; tcase<=t; tcase++) //test case
	{
		int l,c,h,w;
		cin>>l>>c>>h>>w;
		hasil(l,c,h,w);
		cout<<endl; //enter for the next case
	}
	return 0;
}

void hasil (int l, int c, int h, int w)
{
	for (int lines=1; lines<=l; lines++) //main lines
	{
		dotlines(c,h,w);
		minuslines(c,h,w);
	}
	dotlines(c,h,w);	
}

void dotlines (int c, int h, int w)
{
	for (int dotlines=1; dotlines<=h; dotlines++) //height for dotlines
	{
		for (int columns=1; columns<=c; columns++) //column for dots
		{
			dots(w);
			cout<<"|";
		}
		dots(w);
		cout<<endl; //enter for the next height of dotlines
	}
}

void dots (int w)
{
	for (int dots=1; dots<=w; dots++) //total dots of "w"
	{
		cout<<".";
	}
}

void minuslines (int c, int h, int w)
{
	for (int columns=1; columns<=c; columns++) //column for minuses //there is just 1 line
	{
		minuses(w);
		cout<<"+";
	}
	minuses(w);
	cout<<endl; //enter for the next ilne
} 

void minuses (int w)
{
	for (int minuses=1; minuses<= w; minuses++) //total minuses of "w"
	{
		cout<<"-";
	}
}
