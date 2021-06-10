#include <stdio.h>
#include <string.h>

bool checkPalindrome(char s[]){
	
	int left = 0;
	int right = strlen(s) - 1;
	while (left <= right){
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
	
}

int main (){
	
	char words[10005];
	scanf("%[^\n]", words);
	char *pch = strtok(words, " ");
	bool first = true;
	while (pch != NULL){
		if (checkPalindrome(pch)) {
			if (!first) printf(" ");
			printf("%s", pch);
			first = false;
		}
		pch = strtok(NULL, " ");
	}
	printf("\n");
	return 0;
}
