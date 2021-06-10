#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main ()
{
	string s;
	char t[100];
	cin>>s>>t;
	int length = strlen(t);
	int posisi = s.find(t);
	while(posisi>=0)
	{
		s.erase(posisi,length);
		posisi=s.find(t);
	}
	cout<<s<<endl;
}
