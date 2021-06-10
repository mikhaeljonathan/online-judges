#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int x;
	cin>>x;
	if (0<=x<=50)
	{
		cout<<"W";
		for (int i=1;i<=x;i++)
		{
			cout<<"o";
		}
		cout<<"w";
	}
	return 0;
}
