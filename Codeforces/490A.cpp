#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int count[5];
	int index1[n], index2[n], index3[n];
	int i1, i2, i3;
	i1 = i2 = i3 = 0;
	for (int i = 0; i < 5; i++) count[i] = 0;
	for (int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		count[t]++;
		if (t == 1) {
			index1[i1] = i;
			i1++;
		} else if (t == 2){
			index2[i2] = i;
			i2++;
		} else {
			index3[i3] = i;
			i3++;
		}
	}
	
	int res = (count[1] > count[2]) ? count[2] : count[1];
	res = (res > count[3]) ? count[3] : res;
	
	printf("%d\n", res);
	i1 = i2 = i3 = 0;
	for (int i = 0; i < res; i++, i1++, i2++, i3++){
		printf("%d %d %d\n", index1[i1] + 1, index2[i2] + 1, index3[i3] + 1);
	}
	
	return 0;
}
