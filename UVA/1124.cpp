#include <stdio.h>

int main (){
	char in[100];
	while (scanf("%[^\n]", in) != EOF){
		getchar();
		printf("%s\n", in);
	}
	return 0;
}
