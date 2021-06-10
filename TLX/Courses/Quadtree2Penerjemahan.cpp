#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int m[128][128];
string jawaban[128*128];
int n, j, pow2;

// Membuat submatriks menjadi 1 semua yang homogen
void makeItOne(int r, int c, int k){
	for (int i = r; i < r+k; i++){
		for (int j = c; j < c+k; j++){
			m[i][j]=1;
		}
	}
}


void quadtree (int r, int c, int k, int i){
	// Base case saat index sudah di akhir string dan j tidak boleh melebihi banyaknya string
	if ((i >= jawaban[j].length()) && (j < n)) {
		makeItOne(r, c, k);
		j++;
		// Inisiasi kembali dari awal untuk j berikutnya
		i=0;
		r=0;
		c=0;
		k=pow2;
		quadtree(r, c, k, 0);
		
	} else {
		// Karena karakter pertama pasti bernilai 1
		if (i==0){
			quadtree (r, c, k, i+1);
		}
		if (jawaban[j][i]=='0'){
			quadtree (r, c, k/2, i+1);
		} else if (jawaban[j][i]=='1'){
			quadtree (r, c+(k/2), k/2, i+1);
		} else if (jawaban[j][i]=='2'){
			quadtree (r+(k/2), c, k/2, i+1);
		} else if (jawaban[j][i]=='3'){
			quadtree(r+(k/2), c+(k/2), k/2, i+1);
		}
	}
}

int main (){
	int r, c;
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>jawaban[i];
	}
	cin>>r>>c;
	
	// Cari 2^p yang >= max(r, c)
   	int maxRc = max(r, c);
    pow2 = 1;
   	while (pow2 < maxRc){
   	   pow2 *= 2;
   	}
	
	// Inisiasi
	for (int i = 0; i < pow2; i++){
		for (int j = 0; j < pow2; j++){
			m[i][j]=0;
		}
	}
	
	int j = 0;
	quadtree(0, 0, pow2, 0);
	
	// Print
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout<<m[i][j];
			if (j != c-1){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
