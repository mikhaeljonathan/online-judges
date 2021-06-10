#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main () {
	char s[105];
	gets(s);
	char num[105];
	int index = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i+=2, index++) num[index] = s[i];
	
	for (int j = 0; j < index - 1; j++)
		for (int k = 0; k < index - j - 1; k++)
			if (num[k] > num[k + 1]) swap(&num[k], &num[k + 1]);
			
	for (int i = 0; i < index; i++){
		printf("%c", num[i]);
		if (i != index - 1) printf("+");
	}
	puts("");
	return 0;
}
