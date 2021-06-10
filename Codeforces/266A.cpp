#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	int res = 0;
	char temp = 'A';
	while (n--){
		char string;
		scanf("%c", &string);
		if (string == temp) res++;
		temp = string;
	}
	printf("%d\n", res);
	return 0;
}
