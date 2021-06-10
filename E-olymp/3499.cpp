#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD=8388608LL;

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

int main ()
{
	int t;
	scanf("%d",&t);
	while (t--){
		LL n;
		scanf("%lld",&n);
		LL ans1=modex(2LL,n-1LL,MOD);
		LL ans2=((n%MOD)*((n-1LL)%MOD))%MOD+2LL;
		LL ans3=((ans1*ans2)%MOD-1LL)%MOD;
		if(ans3<0)ans3+=MOD;
		printf("%lld\n",ans3);
	}	
	return 0;
}
