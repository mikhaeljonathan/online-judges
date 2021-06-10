#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	char s[n + 3], t[n + 3];
	scanf("%s", s);
	scanf("%s", t);
	int frequency[26];
	for (int i = 0; i < 26; i++) frequency[i] = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		int temp = ++frequency[(int)(s[i] - 'a')];
		if (temp > res) res = temp;
		if (s[i] == t[i]) continue;
		temp = ++frequency[(int)(t[i] - 'a')];
		if (temp > res) res = temp;
	}
	printf("%d\n", res);
	return 0;
}
