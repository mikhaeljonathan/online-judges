#include <stdio.h>
#include <string.h>

int main (){
	char in[105];
	scanf("%s", in);
	int len = strlen(in);
	int counter = 0;
	for (int i = 0; i < len; i++){
		if (in[i] == 'H' || in[i] == 'Q' || in[i] == '9') {
			counter++;
		}
	}
	printf("%s\n", (counter > 0) ? "YES" : "NO"); 
	return 0;
}
