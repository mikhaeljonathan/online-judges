#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	//the terms (Un) using the formula: n/2(n+1)
	bool ans=false;
	int n=1;
	long long terms;
	while(!ans){
		terms = n*(n+1)/2;
		int factors=2;
		for (int divisor=2; divisor<=sqrt(terms); divisor++)
		{
			if (terms%divisor==0){
				factors+=2;
				if (terms/divisor==divisor)factors--;
			}
		}
		if (factors>500){
			ans=true;
		}
		n++;
	}
	printf("%lld",terms);
	return 0;
}
