#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const LL MOD=1000000007LL;

LL gcd (LL a, LL b){
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

LL modex (LL b, LL e, LL m){
	LL r=1;
	while(e>0){
		if((e&1)==1){
			r=(r*b)%m;
		}
		e>>=1;
		b=(b*b)%m;
	}
	return (LL)r;
}

int main (){
	LL n;
	scanf("%lld",&n);
	LL res=0;
	for (LL a=1; a<=modex(2,n,MOD); a=(a+1)%MOD)
		res = res+(LL)(modex(a,MOD-2,MOD)*gcd(a,modex(2,n,MOD)))%MOD;
	printf("%lld",res);
	return 0;
}
