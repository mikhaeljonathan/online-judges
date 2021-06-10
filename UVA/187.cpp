#include <stdio.h>
#include <string.h>
#define SIZE 1005

struct acc{
	char name[50];
}accounts[SIZE];

void init(){
	for (int i = 0; i < SIZE; i++){
		strcpy(accounts[i].name, "");
	}
}

int main (){
	init();
	
	char s[50];
	while (scanf("%[^\n]", s)){
		getchar();
		if (s[0] == '0' && s[1] == '0' && s[2] == '0') break;
		int x;
		sscanf(s, "%d", &x);
		strcpy(accounts[x].name, s + 3);
	}
	
	char sequence[20];
	int accsequence[100000];
	int amountsequence[100000];
	
	int beforetransaction = -1;
	int idx = 0;
	int amount = 0;
	
	while (scanf("%[^\n]", sequence)){
		getchar();
		
		//copy number transaction
		char temp[1000];
		for (int i = 0; i < 3; i++) temp[i] = sequence[i];
		temp[3] = '\0';
		int notransaction;
		sscanf(temp, "%d", &notransaction);
		
//		check whether it's same transaction or not
		if (notransaction != beforetransaction){
			if (amount != 0){
				printf("*** Transaction %.3d is out of balance ***\n", beforetransaction);
				double temp;
				for (int i = 0; i < idx; i++){
					temp = amountsequence[i] / 100.0;
					printf("%.3d %-30s %10.2lf\n", accsequence[i], accounts[accsequence[i]].name, temp);
				}
				amount *= -1;
				temp = amount / 100.0;
				printf("999 %-30s %10.2lf\n\n", "Out of Balance", temp);
			}
			idx = 0;
			amount = 0;
		}
		
		//copy account number
		for (int i = 3; i < 6; i++) temp[i - 3] = sequence[i];
		temp[3] = '\0';
		sscanf(temp, "%d", &accsequence[idx]);
		
		//copy amount sequence
		strcpy(temp, sequence + 7);
		sscanf(temp, "%d", &amountsequence[idx]);
		
		amount += amountsequence[idx];
		beforetransaction = notransaction;
		idx++;
		
		if (sequence[0] == '0' && sequence[1] == '0' && sequence[2] == '0') break;
	}
	
	return 0;
}
