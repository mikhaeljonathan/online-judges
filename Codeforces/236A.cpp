#include <stdio.h>
#include <string.h>

int main (){
	bool key[300] = {0};
	char x[105];
	gets(x);
	int counter = 0;
	for (int i = 0; i < strlen(x); i++){
		if (!key[x[i]]){
			counter++;
			key[x[i]] = true;
		}
	}
	if (counter % 2 == 0){
		puts("CHAT WITH HER!");
	} else {
		puts("IGNORE HIM!");
	}
	return 0;
}
