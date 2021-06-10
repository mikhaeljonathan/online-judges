#include<iostream>
#include<cmath>
using namespace std;

int main (){
	int n;
	cin>>n;
	int counter=0;
	for (int a=1; a<=n;a++){
		for (int b=1; b<=sqrt(a);b++){
			if (a%b==0){
				counter++;
			}
		}
	}
	cout<<counter<<endl;
	return 0;
}
