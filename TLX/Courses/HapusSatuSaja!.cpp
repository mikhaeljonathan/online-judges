#include <iostream>
using namespace std;

int main ()
{
	string a;
	cin>>a;
	string b;
	cin>>b;
	int mistakes=0;
	if (a.length()<=b.length()){
		
	} else {
		int aindex=0, bindex=0;
		while (aindex<a.length()){
			if (a[aindex]!=b[bindex]){
				mistakes++;
				aindex++;
			} else {
				aindex++;
				bindex++;
			}
		}
	}
	if (mistakes==1){
		cout<<"Tentu saja bisa!"<<endl;
	} else {
		cout<<"Wah, tidak bisa :("<<endl;
	}
	
	
	return 0;
}
