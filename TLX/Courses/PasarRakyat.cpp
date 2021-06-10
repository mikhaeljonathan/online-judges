#include <iostream>
using namespace std;

long long int gcd(long long int a,long long int b){
	if (b==0){
		return a;
	} else {
		return gcd(b,a%b);
	}
}

long long int lcm(long long int a, long long int b){
	return (a*b)/gcd(a,b);
}

int main (){
	long long int n;
	cin>>n;
	long long int lcmvar=1;
	while(n--){
		long long int d;
		cin>>d;
		lcmvar = lcm(d,lcmvar);
	}
	cout<<lcmvar<<endl;
}
