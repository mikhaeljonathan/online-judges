#include <stdio.h>
#include <string.h>

struct TEAM{
	int no;
	int ever[10];
	int problemSolved;
	int penalty[10];
	int totalPenalty;
}teams[105];

int compare(TEAM a, TEAM b){
	if (a.problemSolved != b.problemSolved) return (b.problemSolved < a.problemSolved);
	else return (a.totalPenalty <= b.totalPenalty);
}

void merge(TEAM teams[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	TEAM temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight) {
		if (compare(teams[aIndex], teams[bIndex])) temp[tIndex++] = teams[aIndex++];
		else temp[tIndex++] = teams[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = teams[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = teams[bIndex++];
	
	for (int i = 0; i < size; i++) teams[aLeft + i] = temp[i];
}

void mergeSort(TEAM teams[],int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(teams, left, mid);
		mergeSort(teams, mid + 1, right);
		merge(teams, left, mid, mid + 1, right);
	}
}

int main (){
	int t;
	scanf("%d", &t); getchar();
	if (t != 0) getchar();
	while (t--){
		//initialization
		for (int i = 1; i <= 100; i++) {
			teams[i].problemSolved = teams[i].totalPenalty = teams[i].no = 0;
			for (int j = 1; j <= 9; j++) teams[i].ever[j] = teams[i].penalty[j] = 0;
		}
		
		//execute
		int no, prob, time; char idctr;
		char s[30];
		
		while (gets(s)){
			if (!strcmp(s, "")) break;
			sscanf(s, "%d %d %d %c", &no, &prob, &time, &idctr);
			teams[no].no = no;
			if (idctr == 'C'){
				if (!teams[no].ever[prob]){
					teams[no].penalty[prob] += time;
					teams[no].totalPenalty += teams[no].penalty[prob];
					teams[no].problemSolved++;
					teams[no].ever[prob] = 1;
				}
			} else if (idctr == 'I'){
				teams[no].penalty[prob] += 20;
			}
		}
		mergeSort(teams, 1, 100);
		for (int i = 1; i <= 100; i++)
			if (teams[i].no != 0) 
				printf("%d %d %d\n", teams[i].no, teams[i].problemSolved, teams[i].totalPenalty);
				
		if (t != 0) puts("");
	}
	return 0;
}
