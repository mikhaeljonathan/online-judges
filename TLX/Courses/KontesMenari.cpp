#include <stdio.h>
#include <algorithm>
#include <string.h>

/*
Algorithm:
1. generate all array of value of each permutations
2. sort that array (std::sort c++)
3. binary search the h variable9
4. find the index of smallest number that greater than h
5. cout the value of vector size - index
*/

long long n, r, y, j, h;
long long d[105];
char t[105];

// global variable in permutation
long long permutations[10000005];
long long permutationsIndex = 0;
long long catat[20];
bool ever[20];

// counting the sum of d function
long long execute (long long catat[]){
	long long total = 0;
	bool meyakinkan = false;
	char status = 'B';
	for (long long i = 0; i < r; i++){
		long long k;
		if (status == 'P'){
			k =  d[ catat[i] ] * 2;
		} else if (status == 'L'){
			k =  d[ catat[i] ] / 2 ;
		} else if (status == 'Y'){
			meyakinkan = true;
			k = d[ catat[i] ];
		} else {
			k = d[ catat[i] ];
		}
			
		if (meyakinkan){
			k += y;
		}
		
		total += k;
		status = t[ catat[i] ];
	}
	return total;
}


// generate permutation
void generatePermutation(long long depth){
	if (depth == r) /* (r != 0) to avoid pushback in permutations vector*/{
		// add to permutations vector
		permutations[permutationsIndex++] = execute(catat);
		 
	} else {	
		for (long long i = 0; i < n; i++){
			if (!ever[i]){
				ever[i] = true;
				catat[depth] = i;
				generatePermutation(depth + 1);
				ever[i] = false;
			}
		}
	}
}

long long getceil(long long num[], long long left, long long right, long long r){
	long long ceil = -1;
	while (left <= right){
		long long mid = (left + right) / 2;
		if (num[mid] == r){
			while (num[mid] == r && mid <= right) mid++;
			return mid;
		} else if (num[mid] > r){
			right = mid - 1;
		} else{
			ceil = mid;
			left = mid + 1;
		}
	}
	return ceil + 1;
}

int main (){
	//Input
	char subsoal[1005];
	gets(subsoal);
	scanf("%lld %lld %lld %lld", &n, &r, &y, &j);
	for (long long i = 0; i < n; i++){
		scanf("%lld %c", &d[i], &t[i]);
		getchar();
	}
	
	// execute
	memset(ever, false, sizeof(ever));
	generatePermutation(0);
	std::sort(permutations, permutations + permutationsIndex);
	
	for (long long i = 0; i < j; i++){
		scanf("%lld", &h);
		
		long long res = getceil(permutations, 0, permutationsIndex - 1, h);
		
		printf("%lld\n", permutationsIndex - res);
		
	}
	return 0;
}
