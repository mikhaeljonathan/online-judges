#include <stdio.h>

typedef struct{
	int index;
	int total;
}Student;

void swap(Student &a, Student &b){
	Student temp = a;
	a = b;
	b = temp;
}

int main (){
	int n;
	scanf("%d", &n);
	Student students[n];
	for (int i = 0; i < n; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		students[i].index = i + 1;
		students[i].total = a + b + c + d;
	} 
	
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (students[j].total < students[j + 1].total) swap(students[j], students[j + 1]);
	int i = 0;
	
	for (; i < n; i++) if (students[i].index == 1) break;
	
	printf("%d\n", i + 1);
	return 0;
}
