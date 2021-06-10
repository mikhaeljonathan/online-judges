#include <stdio.h>

int main () {
	int c;
	scanf("%d", &c);
	while (c--){
		int n;
		scanf("%d", &n);
		int grade[n];
		long long total = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &grade[i]);
			total += grade[i];
		}
		
		double avg = (double)total / (double)n;
		
		double pass = 0;
		for (int i = 0; i < n; i++){
			if (grade[i] > avg){
				pass++;
			}
		}
		
		double res = (double)pass / (double)n * 100.0;
		
		printf("%.3lf%%\n", res);
	}
	return 0;
}
