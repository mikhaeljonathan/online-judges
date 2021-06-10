#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int a=1; a<=t; a++){
		int n;
		scanf("%d",&n);
		int sum=0;
		for (int b=0; b<n; b++){
			int num;
			scanf("%d",&num);
			if (num<60)
				sum++;
		}
		printf("Case #%d: %d\n",a,sum);
	}
	return 0;
}
