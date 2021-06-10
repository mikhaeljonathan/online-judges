#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	long a=0;
	while(t--){
		int n;
		scanf("%d",&n);
		if (n>0)
			a+=n;
	}
	printf("%ld\n",a);
	return 0;
}
