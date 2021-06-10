#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	long long t;
	scanf("%lld",&t);
	while (t--){
		double m,n;
		scanf("%lf %lf",&m,&n);
		double resdouble;
		long long resint;
		if ((m-floor(m)==0.0)&&(n-floor(n)==0.0)){
			resint = (int)m+(int)n;
			printf("%lld",resint);
		}else{
			resdouble = m+n;
			printf("%lf",resdouble);
		}
		printf("\n");
	}
	return 0;
}
