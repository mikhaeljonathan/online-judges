#include <stdio.h>
#include <string.h>

void swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

bool test(char s[], int len){
	for (int i = 0; i < len - 1; i++)
		if (s[i + 1] - s[i] != 1) return false;
	return true;
}

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	while (n--){
		char s[105];
		gets(s);
		int len = strlen(s);
		for (int i = 0; i < len - 1; i ++)
			for (int j = 0; j < len - 1 - i; j++)
				if (s[j] > s[j + 1]) swap(s[j], s[j + 1]);
		printf("%s\n", test(s, len) ? "Yes" : "No");
	}
	return 0;
}
