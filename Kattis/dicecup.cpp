#include <stdio.h>
#include <string.h>

int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	int freq[100];
	memset(freq, 0, sizeof(freq));
	for (int temp = 1; temp <= a; temp++){
		for (int temp2 = 1; temp2 <= b; temp2++){
			int temp3 = temp + temp2;
			freq[temp3]++;
		}
	}
	int max = freq[0];
	for (int temp = 1; temp < 100; temp++){
		if (freq[temp] > max){
			max = freq[temp];
		}
	}
	
	for (int temp = 1; temp < 100; temp++){
		if (freq[temp] == max){
			printf("%d\n", temp);
		}
	}
	return 0;
}
