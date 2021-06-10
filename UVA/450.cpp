#include <stdio.h>
#include <string.h>

typedef struct{
	char title[105];
	char firstName[105];
	char lastName[105];
	char homeAddress[105];
	char department[105];
	char homePhone[105];
	char workPhone[105];
	char campusBox[105];
}MEMBER;

MEMBER members[100005];

void merge(MEMBER members[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	MEMBER temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (strcmp(members[aIndex].lastName, members[bIndex].lastName) < 0) temp[tIndex++] = members[aIndex++];
		else temp[tIndex++] = members[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = members[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = members[bIndex++];
	
	for (int i = 0; i < size; i++) members[aLeft + i] = temp[i];
}

void mergeSort(MEMBER members[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(members, left, mid);
		mergeSort(members, mid + 1, right);
		merge(members, left, mid, mid + 1, right);
	}
}

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	int index = 0;
	while (n--){
		char department[105];
		gets(department);
		char s[1005];
		while (gets(s)){
			if (!strcmp(s, "")) break;
			sscanf(s, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", members[index].title, members[index].firstName, members[index].lastName, members[index].homeAddress, members[index].homePhone, members[index].workPhone, members[index].campusBox);
			strcpy(members[index].department, department);
			index++;
		}
	}
	
	mergeSort(members, 0, index - 1);
	
	
	for (int i = 0; i < index; i++){
		puts("----------------------------------------");
		printf("%s %s %s\n", members[i].title, members[i].firstName, members[i].lastName);
		printf("%s\n", members[i].homeAddress);
		printf("Department: %s\n", members[i].department);
		printf("Home Phone: %s\n", members[i].homePhone);
		printf("Work Phone: %s\n", members[i].workPhone);
		printf("Campus Box: %s\n", members[i].campusBox);
	}
	
	return 0;
}
