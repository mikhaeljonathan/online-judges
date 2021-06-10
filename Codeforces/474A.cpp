#include <stdio.h>
#include <string.h>

int main (){
	char x;
	scanf("%c", &x); getchar();
	char s[105];
	gets(s);
	char key[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
	int len = strlen(s);
	int len2 = strlen(key);
	for (int i = 0 ;i < len; i++){
		
		for (int j = 0; j < len2; j++){
			if (s[i] == key[j]){
				if (x == 'L'){
					printf("%c", key[j + 1]);
				} else {
					printf("%c", key[j - 1]);
				}
			}
		}
	}
	puts("");
	return 0;
}
