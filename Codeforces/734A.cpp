#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n); getchar();
	char s[n + 5];
	scanf("%s", s);
	int anton, danik;
	anton = danik = 0;
	int index = 0;
	while (s[index] != '\0'){
		if (s[index] == 'A') anton++;
		else danik++;
		index++;
	}
	if (anton > danik) puts("Anton");
	else if (anton < danik) puts("Danik");
	else puts("Friendship");
	return 0;
}
