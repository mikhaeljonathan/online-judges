#include <iostream>
using namespace std;
int f(int x){
	if (x == 1)
		return 1;
	else
		return x+f(x-1);
}
int main (){
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		int t = f(x);
		int a[t];
		for (int j=0; j<t; j++)
			cin>>a[j];
	}
	return 0;
}
