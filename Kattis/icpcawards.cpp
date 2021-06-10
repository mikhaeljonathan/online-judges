#include <stdio.h>
#include <string.h>

int main () {
	int n;
	scanf("%d", &n);
	char universities[n][25];
	char teams[n][25];
	for (int i = 0; i < n; i++){
		getchar();
		scanf("%s", universities[i]);
		scanf("%s", teams[i]);
	}
	char champions[n][25];
	int indexChampions = 0;
	int champs = 0;
	int indexTeams = 0;
	while (champs < 12){
		bool exist = false;
		for (int i = 0; i < indexChampions; i++){
//			printf("%d %s %s\n", i, universities[indexTeams], champions[i]);
			if (strcmp(universities[indexTeams], champions[i]) == 0){
				exist = true;
				break;
			}
		}
		
		if (!exist){
			strcpy(champions[indexChampions], universities[indexTeams]);
//			printf("%s\n", champions[indexChampions]);
			printf("%s %s\n", universities[indexTeams], teams[indexTeams]);
			champs++;
			indexChampions++;
		}
		
		indexTeams++;
	}
	return 0;
}
