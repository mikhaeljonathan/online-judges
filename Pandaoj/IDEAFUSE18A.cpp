#include <stdio.h>

int main () {
	int t;
	scanf("%d", &t);
	for ( int i = 1; i <= t; i++ ){
		int n;
		scanf( "%d", &n );
		bool exceed = false;
		bool biutiful = false;
		int num = 1;
		int total = 0;
		while (!exceed){
			if (total > n){
				exceed = true;
			}
			if (total == n){
				biutiful = true;
			}
			total += num;
			num++;
		}
		
		printf("Case #%d: ", i );
		if (biutiful){
			printf("YES\n");
		} else {
			printf( "NO\n" );
		}
	}
	return 0;
}
