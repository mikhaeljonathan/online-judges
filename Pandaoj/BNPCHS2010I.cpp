#include <cstdio>
using namespace std;
int counter=0;
int fib[10005];
bool first=false;

long fibo(int a, int b){
	if (a==b){
		counter++;
		if (!first){
			fib[b]=fibo(a-1,b)+fibo(a-2,b);
			first=true;
		}
		else
			return fib[b];
	}
	if (a<=1)
		return a;
	return fibo(a-1,b)+fibo(a-2,b);
}

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		counter=0;
		int n,m;
		scanf("%d %d",&n,&m);
		long res = fibo(n,m);
		printf("%d\n",counter);
	}	
	return 0;
}
