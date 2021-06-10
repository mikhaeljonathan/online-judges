#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	long long t;
	scanf("%lld",&t);
	while (t--){
		long long n;
		long long sum=1;
		scanf("%lld",&n);
		for (long long a=2; a<=(long long)sqrt(n); a++){
			if (n%a==0){
				sum+=a;
				long long temp = (long long)n/a;
				sum+=temp;
				if (a==temp)
					sum-=temp;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
