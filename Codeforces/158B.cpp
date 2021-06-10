#include <stdio.h>
#include <algorithm>

int main (){
	int n;
	scanf("%d", &n);
	int num[n];
	num[0] = 10;
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
	std::sort(num, num + n);
	int res = 0;
	int capacity = 0;
	for (int i = n; i >= 0; i--){
		if (capacity + num[i] > 4){
			res++;
			capacity = num[i];
		} 
		else capacity += num[i];
	}
	printf("%d\n", res);
	return 0;
}
