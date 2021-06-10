#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int a=1; a<=t; a++){
		int n;
		scanf("%d",&n);
		long long counter=0;
		int temp,temp2;
		for (int b=1; b<n-1; b++){
			for (int c=1; c<n-1; c++){
				if (b+c>n-1)
					continue;
				temp = max(max(b,c),max(c,n-b-c));
				temp2 = min(min(b,c),min(c,n-b-c));
				if (temp<temp2+(n-temp-temp2))
					counter++;
			}
		}
		printf("Case #%d: %lld\n",a,counter);
	}
	return 0;
}
