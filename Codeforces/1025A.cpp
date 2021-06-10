#include <stdio.h>

bool test(char s[], int n){
	if (n == 1) return true;
	
	int ever[300];
	for (int i = 0; i < 300; i++) ever[i] = 0;
	for (int i = 0; i < n; i++){
		if (!ever[s[i]]) ever[s[i]] = 1;
		else return true;
	}
	return false;
}

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char s[n + 5];
	gets(s);
	printf("%s\n", test(s, n) ? "Yes" : "No");
	return 0;
}
