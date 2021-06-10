#include <stdio.h>
#include <string.h>

int homogenous(char s[], int len){
	char temp = s[0];
	for (int i = 0; i < len; i++){
		if (s[i] != temp) return false;
		temp = s[i];
	}
	return true;
}

int main (){
	int t;
	scanf("%d", &t);
	getchar();
	while (t--){
		char s[1005];
		gets(s);
		int len = strlen(s);
		if (homogenous(s, len)) printf("-1\n");
		else {
			int key[300];
			for (char i = 'a'; i <= 'z'; i++) key[i] = 0; //initializatio 
			for (int i = 0; i < len; i++) key[s[i]]++;
			for (char i = 'a'; i <= 'z'; i++) for (int j = 1; j <= key[i]; j++) printf("%c", i);
			puts("");
		}
	}
	return 0;
}
