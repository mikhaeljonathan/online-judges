#include <iostream>
#include <utility>
#define forr(a,n) for (long long int a = 0; a < n; a++)
using namespace std;

void merge (pair <long long int, long long int> times[], long long int aleft, long long int aright, long long int bleft, long long int bright){
	long long int size = bright - aleft + 1;
	pair <long long int, long long int> temp[size];
	long long int tindex = 0;
	long long int aindex = aleft;
	long long int bindex = bleft;
	
	while (aindex <= aright && bindex <= bright){
		if (times[aindex].second <= times[bindex].second){
			temp[tindex] = times[aindex];
			aindex++;
		} else {
			temp[tindex] = times[bindex];
			bindex++;
		}
		tindex++;
	}
	
	while (aindex <= aright){
		temp[tindex] = times[aindex];
		aindex++;
		tindex++;
	}
	
	while (bindex <= bright){
		temp[tindex] = times[bindex];
		bindex++;
		tindex++;
	}
	
	for (long long int i = 0; i < size; i++){
		times[aleft + i] = temp[i];
	}
}

void mergesort (pair <long long int, long long int> times[], long long int left, long long int right){
	if (left == right){
		return;
	} else {
		long long int mid = (left + right) / 2;
		mergesort (times, left, mid);
		mergesort (times, mid + 1, right);
		merge (times, left, mid, mid + 1, right);
	}
}

int main (){
	// Input
	long long int n;
	cin >> n;
	pair <long long int, long long int> times [n];
	forr (a, n){
		cin >> times[a].first >> times[a].second;
		times[a].second += times[a].first;
	}
	
	// Merge sort according to d
	long long int temp = sizeof(times)/sizeof(times[0]) - 1;
	mergesort(times, 0, temp);
	
	// execute
	long long int selectedCount = 0;
	long long int startTime = 0;
	forr (a, n){
		if (times[a].first >= startTime){
			selectedCount++;
			startTime = times[a].second;
		}
	}
	
	// Output
	cout << selectedCount << endl;
	return 0;
}
