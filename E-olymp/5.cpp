#include <stdio.h>
#include <math.h>

int main (){
	int k;
	scanf("%d", &k);
	if (k == 1){
		printf("1\n");
		return 0;
	}
	k *= 2;
	int prime[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int primefactor[10];
	int temp = k;
	int index = 0;
	int indexfactor = 0;
	while (temp != 1){
		if (temp % prime[index] == 0){
			temp = temp / prime[index];
			primefactor[indexfactor++] = prime[index];
		} else {
			index++;
		}
	}
	long long res = 1;
	index = 0;
	for (int i = indexfactor - 1; i >= 0; i--){
		printf("%d %d %lf\n", prime[index],primefactor[i]-1, pow(prime[index], primefactor[i]-1));
		res *= pow(prime[index++], primefactor[i] - 1);
	}
	printf("%lld\n", res);
	return 0;
}
