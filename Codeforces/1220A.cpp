#include <stdio.h>

bool possibleOne(int key[], char s[], int n){
	return (key['o'] > 0 && key['n'] > 0 && key['e'] > 0);
}

bool possibleZero(int key[], char s[], int n){
	return (key['z'] > 0 && key['e'] > 0 && key['r'] > 0 && key['o'] > 0);
}

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char s[n + 5];
	gets(s);
	int key[300];
	for (int i = 0; i < 300; i++) key[i] = 0;
	for (int i = 0; i < n; i++) key[s[i]]++;
	bool first = true;
	while (1){
		if (possibleOne(key, s, n)){
			if (!first) printf(" ");
			printf("1");
			key['o']--;
			key['n']--;
			key['e']--;
			first = false;
		} else if (possibleZero(key, s, n)){
			if (!first) printf(" ");
			printf("0");
			key['z']--;
			key['e']--;
			key['r']--;
			key['o']--;
			first = false;
		} else break;
	}
	return 0;
}
