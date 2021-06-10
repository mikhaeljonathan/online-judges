#include <stdio.h>

int main (){
	int n, k;
	scanf("%d %d", &n, &k);
	int storage[n];
	bool ever[105];
	int count = 0;
	for (int i = 0; i < 105; i++) ever[i] = false;
	for (int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		if (count == k) break;
		if (!ever[num]){
			storage[count] = i + 1;
			count++;
			ever[num] = true;
		}
	}
	if (count != k){
		puts("NO");
	} else {
		puts("YES");
		for (int i = 0; i < count; i++){
			printf("%d", storage[i]);
			if (i != count - 1) printf(" ");
		}
		puts("");
	}
	return 0;
}
