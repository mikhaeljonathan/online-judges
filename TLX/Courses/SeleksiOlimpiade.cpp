#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	string nama;
	int n1, n2, n3;
} peserta;

bool compare (peserta a, peserta b){
	if (a.n3 < b.n3){
		return false;
	} else if (a.n3 == b.n3){
		if (a.n2 < b.n2){
			return false;
		} else if (a.n2 == b.n2){
			if (a.n1 < b.n1){
				return false;
			}
		}
	}
	return true;
}

int main (){
	// Input
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		peserta siswa[n];
		string cariNama;
		cin >> cariNama;
		for (int a = 0; a < n; a++){
			cin >> siswa[a].nama >> siswa[a].n1 >> siswa[a].n2 >> siswa[a].n3;
		}
		
		// Insertion sort
		for (int a = 0; a < n; a++){
			int pos = a;
			while ((pos > 0) && (compare(siswa[pos], siswa[pos-1]))){
				swap(siswa[pos],siswa[pos-1]);
				pos--;
			}
		}
		
		// Checking
		bool lulus = false;
		for (int a = 0; a < m; a++){
			if (cariNama == siswa[a].nama){
				lulus = true;
				break;
			}
		}
		
		if (lulus) {
			cout << "YA" << endl;
		} else {
			cout << "TIDAK" << endl;
		}
	}
	
	return 0;
}
