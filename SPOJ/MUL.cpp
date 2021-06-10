#include <cstdio>
using namespace std;

int main ()
{
	long long t;
	scanf("%lld",&t);
	while (t--){
		double a,b;
		scanf("%lf %lf",&a,&b);
		long long ans = (long long)a*(long long)b;
		printf("%lld\n",ans);
	}
	return 0;
}
