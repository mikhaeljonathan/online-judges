#include <stdio.h>
#include <string.h>

int abs (int x){
	if (x < 0){
		return -x;
	}
	return x;
}

int main () {
	char in[1005];
	scanf("%s", in);
	int n = 0, e = 0, s = 0, w = 0;
	for (int i = 0; i < strlen(in); i++){
		if (in[i] == 'N'){
			n++;
		} else if (in[i] == 'E'){
			e++;
		} else if (in[i] == 'S'){
			s++;
		} else {
			w++;
		}
	}
	int res = abs(n - s) + abs(e - w);
	printf("%d\n", res);
	return 0;
}
