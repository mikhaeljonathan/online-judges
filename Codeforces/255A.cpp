#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int count[3];
	count[0] = count[1] = count[2] = 0;
	for (int i = 0; i < n; i++)	{
		int num;
		scanf("%d", &num);
		count[i % 3] += num;
	}
	int max = count[0];
	int index = 0;
	for (int i = 1; i < 3; i++){
		if (count[i] > max){
			max = count[i];
			index = i;
		}
	}
	if (index == 0) puts("chest");
	else if (index == 1) puts("biceps");
	else puts("back");

	return 0;
}
