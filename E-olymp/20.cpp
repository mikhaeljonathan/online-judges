#include <cstdio>
using namespace std;

int main () {
	long long n;
	scanf("%lld",&n);
	long long c=0;
	while (n>0){
		long long ns=n,sum=0;
		while (ns>0) {
			sum = sum+(ns%10);
			ns/=10;
		}
		n-=sum;
		c++;
	}
	printf("%lld\n",c);
	return 0;
}
