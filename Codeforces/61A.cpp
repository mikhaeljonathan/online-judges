#include <stdio.h>
#include <string.h>

int main () {
	char a[105], b[105];
	scanf("%s %s", a, b);
	for (int i = 0; i < strlen(a); i++){
		bool boola = (a[i] == '1') ? true : false;
		bool boolb = (b[i] == '1') ? true : false;
		if (boola ^ boolb){
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
	return 0;
}
