#include <stdio.h>

int count(int a){
	if (a == 1) return 1;
	else {
		if (a % 2) return 1 + count(3 * a + 1);
		else return 1 + count(a / 2);
	}
}

int min (int a, int b){
	return (a < b) ? a : b;
}

int max (int a, int b){
	return (a > b) ? a : b;
}

int main (){
	int i, j;
	while (scanf("%d %d", &i, &j) != EOF){
		int res = 0;
		int minimum = min(i, j);
		int maximum = max(i, j);
		for (int a = minimum; a <= maximum; a++){
			int temp = count(a);
			if (temp > res) res = temp;
		}
		printf("%d %d %d\n", i, j, res);
	}
	
	return 0;
}
