#include <stdio.h>
#include <string.h>

int main(){
	char in[25];
	scanf("%s", in);
	int len = strlen(in);
	int nlucky = 0;
	for (int i = 0; i < len; i++){
		if (in[i] == '4' || in[i] == '7'){
			nlucky++;
		}
	}
	printf("%s\n", (nlucky == 4 || nlucky == 7) ? "YES" : "NO");
	return 0;
}
