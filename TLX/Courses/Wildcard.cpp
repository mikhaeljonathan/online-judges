#include <iostream>
using namespace std;

int main (){
	// Input
	string word;
	cin >> word;
	int n;
	cin >> n;
	string cases[n];
	for (int a = 0; a < n; a++){
		cin >> cases[a];
	}
	
	// Execute
	for (int b = 0; b < n; b ++){
		
		// Inisiasi
		int counter=0;
		
		// Dari kiri
		int c = 0;
		while (word[c] != '*'){
			if (word[c] == cases[b][c]){
				counter++;
			}
			c++;
		}
		int howManyLettersFromLeft = counter - 1;
		
		// Dari kanan
		int d = word.length() - 1;
		int e = cases[b].length() - 1;
		while (word[d] != '*'){
			if (e == howManyLettersFromLeft){
				break;
			}
			if (word[d] == cases[b][e]){
				counter++;
			}
			d--;
			e--;
		}
		
		// Check the answer
		if (counter == word.length() - 1){
			cout << cases[b] << endl;
		}
	}
	
	return 0;
}
