#include <cstdio>
using namespace std;

//FORMULA: ((9+n)(8+n)...(1+m)-9!) / (9(8+n)(7+n)...(1+n))
int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		long long n;
		scanf("%lld",&n);
		double ans1=1.0;
		for (double a=1.0; a<=9.0; a+=1.0){
			ans1*=((double)n+a);
		}
		double ans2 = ans1/(9.0+(double)n);
		double res = (ans1-362880.0)/(9.0*ans2);
		printf("%.6lf\n",res);
	}	
	return 0;
}
