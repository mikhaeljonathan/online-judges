//https://nus.kattis.com/problems/nus.basicprogramming1
#include <stdio.h>

void swap(long long &a, long long &b){
	long long temp = a;
	a = b;
	b = temp;
}

int main (){
	long long n, t;
	scanf("%lld %lld", &n, &t);
	long long a[n];
	for (long long i = 0; i < n; i++) scanf("%lld", &a[i]);
	if (t == 1){
		printf("7\n");
	} else if (t == 2){
		if (a[0] > a[1]) printf("Bigger\n");
		else if (a[0] == a[1]) printf("Equal\n");
		else printf("Smaller\n");
	} else if (t == 3){
		for (long long i = 0; i < 2; i++)
			for (long long j = 0; j < 2 - i; j++)
				if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		printf("%lld\n", a[1]);
	} else if (t == 4){
		long long total = 0;
		for (long long i = 0; i < n; i++) total += a[i];
		printf("%lld\n", total);
	} else if (t == 5){
		long long total = 0;
		for (long long i = 0; i < n; i++) if (a[i] % 2 == 0) total += a[i];
		printf("%lld\n", total);
	} else if (t == 6){
		for (long long i = 0; i < n; i++) a[i] %= 26;
		for (long long i = 0; i < n; i++) printf("%c", 'a' + a[i]);
		puts("");
	} else if (t == 7){
		bool ever[n];
		for (long long i = 0; i < n; i++) ever[i] = false;
		long long i = 0;
		ever[i] = true;
		while (1){
			i = a[i];
			if (i < 0 || i > n - 1){
				printf("Out\n");
				break;
			} else if (i == n - 1){
				printf("Done\n");
				break;
			}
			if (!ever[i]) ever[i] = true;
			else {
				printf("Cyclic\n");
				break;
			}
		}
	}
	
	return 0;
}
