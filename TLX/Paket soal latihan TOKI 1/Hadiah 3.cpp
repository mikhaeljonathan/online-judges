#include <stdio.h>

int pow(int a, int b){
	if (b == 0) return 1;
	return a * pow(a, b - 1);
}

int main (){
	int n;
	scanf("%d", &n);
	int container[105];
	int idx = 0;
	while (n > 0){
		
		int temp = n;
		int res = 0;
		while (temp % 3 == 0){
			temp /= 3;
			res++;
		}
		
		res = pow(3, res);
		container[idx++] = res;
		n -= res;
		
	}
	printf("%d\n", idx);
	for (int i = 0; i < idx; i++){
		if (i != 0) printf(" ");
		printf("%d", container[i]);
	}
	printf("\n");
	return 0;
}
