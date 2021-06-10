#include <stdio.h>

int min(int a, int b){
	return (a < b) ? a : b;
}

int main (){
	int n;
	scanf("%d", &n);
	int lengthmax = 0;
	int num1 = 0;
	int num2 = 0;
	int temp = -1;
	while (n--){
		int num;
		scanf("%d", &num);
		if (temp != num){
			if (num == 1) num1 = 0;
			else num2 = 0;
		}
		
		int length;
		if (num == 1){
			num1++;
			length = min(num1, num2);
		} else {
			num2++;
			length = min(num2, num1);
		}
		if (length > lengthmax) lengthmax = length;
		
		temp = num;
	}
	printf("%d\n", lengthmax * 2);
	return 0;
}
