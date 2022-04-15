#include <stdio.h>
#include <string.h>

int main (){
	char in[105];
	scanf("%s", in);
	int up, low;
	up = low = 0;
	int len = strlen(in);
	for (int i = 0; i < len; i++){
		if (in[i] < 91) {
			up++;
		} else {
			low++;
		}
	}

	for (int i = 0; i < len; i++) {
		if (up <= low && in[i] < 91) {
			in[i]+=32;
		}
		if (up > low && in[i] > 91) {
			in[i]-=32;
		}
	}		
	
	printf("%s\n", in);
	return 0;
}
