#include <cstdio>
#include <algorithm>
using namespace std;

int main () {
	int n;
	scanf("%d",&n);
	int data[n];
	for (int a=0; a<n; a++){
		scanf("%d",&data[a]);
	}
	int memo[n];
	for (int b=0; b<n; b++){
	memo[b]=1;
	}
	int index=0;
	while (index<n){
		for (int c=0; c<index; c++){
			if (data[c]<data[index]){
				memo[index]=max(memo[c]+1,memo[index]);
			}
		}
		index++;
	}
	int max=memo[0];
	for (int d=1; d<n; d++){
		if (memo[d]>max){
			max=memo[d];
		}
	}
	printf("%d\n",max);
	return 0;
}
