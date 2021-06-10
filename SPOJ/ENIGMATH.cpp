#include <cstdio>
using namespace std;

long long int gcd (long long int a,long long int b){
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		long long int a,b;
		scanf("%lld %lld",&a,&b);
		long long int temp=gcd(a,b);
		long long int x=b/temp;
		long long int y=a/temp;
		printf("%lld %lld\n",x,y);
	}
	return 0;
}
