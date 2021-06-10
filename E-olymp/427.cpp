#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		long long n;
		scanf("%lld",&n);
		long long hasil=0;
		for (long long k=0; k<=n-1; k++){
			hasil = hasil+pow(k,2)*pow(2,k);
		}
		printf("%lld\n",hasil);
	}
	return 0;
}
