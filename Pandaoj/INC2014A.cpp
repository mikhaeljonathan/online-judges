#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int tc=1; tc<=t; tc++){
		int n;
		scanf("%d",&n);
		long long sum=0;
		for (int a=0; a<n; a++){
			long long cap;
			scanf("%lld",&cap);
			sum+=cap;
		}
		int k=4;
		while (sum>pow(2,k)*1000)
			k++;
		long int res=pow(2,k);
		printf("Case #%d: %ldGB\n",tc,res);
	}
	return 0;
}
