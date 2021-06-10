#include <stdio.h>
#include <string.h>

typedef struct{
	char names[20];
	int points;
	int gameplayed;
	int scoredgoals;
	int sufferedgoals;
	int goaldifference;
	double earnedpoints;
}Team;

void swap(Team &a, Team &b){
	Team temp = a;
	a = b;
	b = temp;
}

int min (int a, int b){
	return (a < b) ? a : b;
}

int myOwnStrcmpi(char a[], char b[]){
	
	for (int i = 0; i < min(strlen(a), strlen(b)); i++){
		if (a[i] != b[i]){
			char tempa = a[i];
			char tempb = b[i];
			if (a[i] >= 'a' && a[i] <= 'z') tempa -= 'a' - 'A';
			if (b[i] >= 'a' && b[i] <= 'z') tempb -= 'a' - 'A';
			if (tempa < tempb) return -1;
			if (tempa > tempb) return 1;
		}
	}
	
	if (strlen(a) < strlen(b)) return -1;
	if (strlen(a) > strlen(b)) return 1;
	return 0;
}

int compare(Team a, Team b){
	if (a.points != b.points) return (a.points < b.points);
	else {
		if (a.goaldifference != b.goaldifference) return (a.goaldifference < b.goaldifference);
		else {
			if (a.scoredgoals != b.scoredgoals) return (a.scoredgoals < b.scoredgoals);
			else {
				if (myOwnStrcmpi(a.names, b.names) > 0) return 1;
				else return 0;
			}
		}
	}
}

int same(Team a, Team b){
	return (a.points == b.points && a.goaldifference == b.goaldifference && a.scoredgoals == b.scoredgoals);
}

int main (){
	int t, g;
	scanf("%d %d", &t, &g);
	
	while (t != 0 || g != 0){
		
		//initialization
		Team teams[t + 1];
		for (int i = 0; i <= t; i++){
			teams[i].points = teams[i].gameplayed = teams[i].scoredgoals = teams[i].sufferedgoals = teams[i].goaldifference = 0;
			teams[i].earnedpoints = 0.0;
		}
		
		//scan team names
		for (int i = 0; i < t; i++) {
			getchar();
			scanf("%[^\n]", teams[i].names);
		}
		
		//scan battle log
		for (int i = 0; i < g; i++){
			getchar();
			char temp1[20];
			char temp2[20];
			int score1;
			int score2;
			scanf("%s %d - %d %s", temp1, &score1, &score2, temp2);
			int left = t;
			int right = t;
			
			//searching
			for (int i = 0; i < t; i++){
				if (!strcmp(temp1, teams[i].names)) {
					left = i;
					break;
				}
			}
			for (int i = 0; i < t; i++){
				if (!strcmp(temp2, teams[i].names)) {
					right = i;
					break;
				}
			}
			
			//points
			if (score1 != score2){
				if (score1 > score2) teams[left].points += 3;
				else teams[right].points += 3;
			} else {
				teams[left].points++;
				teams[right].points++;
			}
			
			//game played
			teams[left].gameplayed++;
			teams[right].gameplayed++;
			
			//scored goals
			teams[left].scoredgoals += score1;
			teams[right].scoredgoals += score2;
			
			//suffered goals
			teams[left].sufferedgoals += score2;
			teams[right].sufferedgoals += score1;
			
		}
		
		//goal difference and earned points
		for (int i = 0; i < t; i++){
			teams[i].goaldifference = teams[i].scoredgoals - teams[i].sufferedgoals;
			
			if (teams[i].gameplayed == 0) teams[i].earnedpoints = -1.0;
			else teams[i].earnedpoints = (double) teams[i].points / ((double) teams[i].gameplayed * 3.0) * 100.0;
		}
		
//		puts("sebelum sort");
//		for (int i = 0; i < t; i++){
//			printf("%2d. %15s%4d%4d%4d%4d%4d", i + 1, teams[i].names, teams[i].points, teams[i].gameplayed, teams[i].scoredgoals, teams[i].sufferedgoals, teams[i].goaldifference);
//			if (teams[i].earnedpoints == -1.0)	printf("    N/A\n");
//			else printf(" %6.2lf\n", teams[i].earnedpoints);
//		}
		
		//bubble sort
		for (int i = 0; i < t - 1; i++)
			for (int j = 0; j < t - 1 - i; j++)
				if (compare(teams[j], teams[j + 1])) swap(teams[j], teams[j + 1]);
		
		Team temp;
		temp.points = temp.goaldifference = temp.scoredgoals = -1;
		for (int i = 0; i < t; i++){
			if (same(temp, teams[i])) printf("%19s%4d%4d%4d%4d%4d", teams[i].names, teams[i].points, teams[i].gameplayed, teams[i].scoredgoals, teams[i].sufferedgoals, teams[i].goaldifference);
			else printf("%2d. %15s%4d%4d%4d%4d%4d", i + 1, teams[i].names, teams[i].points, teams[i].gameplayed, teams[i].scoredgoals, teams[i].sufferedgoals, teams[i].goaldifference);
			if (teams[i].earnedpoints == -1.0)	printf("    N/A\n");
			else printf(" %6.2lf\n", teams[i].earnedpoints);
			temp = teams[i];
		}
		
		scanf("%d %d", &t, &g);
		
		if (t != 0 || g != 0) puts("");
	}
	
	return 0;
}
