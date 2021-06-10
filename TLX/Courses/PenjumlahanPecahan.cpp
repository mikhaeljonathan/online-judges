#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b){
	if (b==0){
		return a;
	} else {
		return gcd(b,a%b);
	}
}

int main (){
	long long int a,b,c,d;
	cin>>a>>b>>c>>d;
	long long int numerator=a*d+b*c;
	long long int denominator=b*d;
	long long int e=numerator/gcd(numerator,denominator);
	long long int f=denominator/gcd(numerator,denominator);
	cout<<e<<" "<<f<<endl;
	return 0;
}
