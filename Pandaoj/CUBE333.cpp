#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int tc=1; tc<=t; tc++){
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long n=1,res=0,counter=0;
		while (res<=b){
			res=pow(n,3);
			if (res>=a)
				counter++;
			n++;
		}
		printf("Case #%d: %lld\n",tc,counter-1);
	}
	return 0;
}
