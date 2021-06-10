#include <iostream>
using namespace std;
void swap (string *x, string *y);
int length(string x);

int main ()
{
	int n;
	cin>>n;
	string name[n];
	for (int temp=0; temp<n; temp++)
	{
		cin>>name[temp];
	}
	//insertion sort
	for (int temp2=0; temp2<n; temp2++)
	{
		int pos = temp2;
		while ((pos>0)&&(length(name[pos])<=length(name[pos-1])))
		{
			if (length(name[pos])==length(name[pos-1]))
			{
				if (name[pos]<name[pos-1])
				{
					swap(name[pos], name[pos-1]);
				}
			}
			else
			{
				swap(name[pos], name[pos-1]);
			}
			pos--;
		}
	}
	for (int temp3=0; temp3<n; temp3++)
	{
		cout<<name[temp3]<<endl;
	}
	return 0;
}

void swap (string *x, string *y)
{
	string temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int length (string x)
{
	int i=0;
	while (x[i]!='\0')
	{
		i++;
	}
	return i;
}
