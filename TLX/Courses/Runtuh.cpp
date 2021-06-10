#include <iostream>
using namespace std;

int main (){
	int r,c;
	cin>>r>>c;
	string table[r];
	for (int a=0; a<r; a++)
		cin>>table[a];
	bool thereAreFullRow;
	do {
		thereAreFullRow=false;
		int index=-1;
		for (int b=0; b<r; b++){
			int counter=0;
			for (int d=0; d<c; d++)
				if (table[b][d]=='1')
					counter++;
			if (counter==c){
				for (int e=0; e<c; e++)
					table[b][e]='0';
				index=b;
			}
		}
		
		
		bool executed=false;
		if (index!=-1){
			executed=true;
			for (int i=index-1; i>=0; i--){
				for (int j=0; j<c; j++){
					if (table[i][j]=='1'){
						int a=i+1;
						while ((table[a][j]=='0')&&(a<r)){
							a++;
						}
						a--;
						table[a][j]='1';
						table[i][j]='0';
					}
				}
			}
		}
		
		
		int f=0;
		while ((!thereAreFullRow)&&(f<r)&&(executed)){
			int counter=0;
			for (int g=0; g<c; g++)
				if (table[f][g]=='1')
					counter++;
			if (counter==c)
				thereAreFullRow=true;
			f++;
		}
		
	} while (thereAreFullRow);

	for (int b=0; b<r; b++)
		cout<<table[b]<<endl;
	return 0;
}
