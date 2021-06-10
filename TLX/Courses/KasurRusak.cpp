#include <iostream>
#include <string>
using namespace std;
string f(string test, int left, int right);
int length(string x);

int main ()
{
	string test;
	cin>>test;
	int left=0;
	int right=length(test)-1;
	if (length(f(test,left,right))<2)
	{
		cout<<"YA";
	}
	else
	{
		cout<<"BUKAN";
	}
	cout<<endl;
}

string f(string test, int left, int right)
{
	if (length(test)<2)
	{
		return test;
	}
	else
	{
		if (test[left]!=test[right])
		{
			return test;
		}
		else
		{
			test.erase(left,1);
			test.erase(right-1,1);
			return f(test, left, right-2);
		}
	}
}		

int length(string x)
{
	int count=0;
	int index=0;
	while (x[index]!='\0')
	{
		count++;
		index++;
	}
	return count;
}
