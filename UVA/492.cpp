#include <stdio.h>
#include <string.h>

int main (){
	char x[1000005];
	scanf("%[^\n]", x);
	bool newWord = true;
	bool consonant = true;
	char temp;
	int size = strlen(x);
	for (int i = 0; i < size; i++){

		if (newWord && (x[i] != 'A' && x[i] != 'E' && x[i] != 'I' && x[i] != 'O' && x[i] != 'U' && x[i] != 'a' && x[i] != 'e' && x[i] != 'i' && x[i] != 'o' && x[i] != 'u')){
			consonant = true;
			temp = x[i];
			newWord = false;
			continue;
		} else if (newWord){
			consonant = false;
			newWord = false;
		}
		
		if (!newWord){
			if ((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z')){
				printf("%c", x[i]);
				if (i == size - 1){
					if (consonant){
						printf("%c", temp);
					}
					printf("ay");
				}
			} else {
				newWord = true;
				if (consonant){
					printf("%c", temp);
				}
				printf("ay");
				printf("%c", x[i]);
			}
		}
	}
	return 0;
}
