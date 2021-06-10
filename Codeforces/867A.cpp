#include <stdio.h>
#include <string.h>

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char s[n + 5];
	gets(s);
	int len = strlen(s);
	char curr = 'a';
	int StoF, FtoS;
	StoF = FtoS = 0;
	for (int i = 0; i < len; i++){
		if (curr == 'S' && s[i] == 'F') StoF++;
		if (curr == 'F' && s[i] == 'S') FtoS++;
		curr = s[i];
	}
	printf("%s\n", (StoF > FtoS) ? "YES" : "NO");
	return 0;
}
