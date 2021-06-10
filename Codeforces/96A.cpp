#include <stdio.h>
#include <string.h>

int dangerous(char string[]){
	int zero = 0;
	int one = 0;
	int len = strlen(string);
	for (int i = 0; i < len; i++){
		if (string[i] == '0'){
			zero++;
			if (zero >= 7) return 1;
			one = 0;
		} else {
			one++;
			if (one >= 7) return 1;
			zero = 0;
		}
	}
	return 0;
}

int main (){
	char string[105];
	gets(string);
	printf("%s\n", dangerous(string) ? "YES" : "NO");
	return 0;
}
