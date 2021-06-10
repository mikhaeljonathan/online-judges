#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare (char a[], char b[]){
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (tolower(a[i]) < tolower(b[i])) return -1;
		else if(tolower(a[i]) > tolower(b[i])) return 1;
	}
	return 0;
}

int main (){
	char a[105];
	char b[105];
	gets(a);
	gets(b);
	int ans = compare(a, b);
	printf("%d\n", ans);
	return 0;
}
