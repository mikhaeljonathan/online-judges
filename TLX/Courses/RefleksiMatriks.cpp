#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

bool identik(int a[][80], int b[][80], int n){
	for (int temp=0; temp<n; temp++){
		for (int temp2=0; temp2<n; temp2++){
			if (a[temp][temp2]!=b[temp][temp2]){
				return false;
			}
		}
	}
	return true;
}

bool vertikal(int a[][80], int b[][80], int n){
	int temporary[n][80];
	for (int temp=0; temp<n; temp++){
		for (int temp2=0; temp2<n; temp2++){
			temporary[temp][temp2]=a[temp][(n-1)-temp2];
		}
	}
	if (identik(temporary,b,n)){
		return true;
	}
	return false;
}

bool horisontal(int a[][80], int b[][80], int n){
	int temporary[n][80];
	for (int temp=0; temp<n; temp++){
		for (int temp2=0; temp2<n; temp2++){
			temporary[temp][temp2]=a[(n-1)-temp][temp2];
		}
	}
	
	if (identik(temporary,b,n)){
		return true;
	}
	return false;
}

bool kananbawah(int a[][80], int b[][80], int n){
	for (int temp=0; temp<n; temp++){
		for (int temp2=0; temp2<n; temp2++){
			if (a[temp][temp2]!=b[temp2][temp]){
				return false;
			}
		}
	}
	return true;
}

bool kiribawah(int a[][80], int b[][80], int n){
	int temporary[n][80];
	for (int temp=0; temp<n; temp++){
		for (int temp2=0; temp2<n; temp2++){
			temporary[temp][temp2]=a[temp][(n-1)-temp2];
		}
	}
	
	for (int temp=0; temp<n/2; temp++){
		for (int temp2=0; temp2<n; temp2++){
			swap(temporary[temp][temp2],temporary[(n-1)-temp][temp2]);
		}
	}
	
	if (kananbawah(temporary,b,n)){
		return true;
	}
	return false;
}

int main (){
	int n;
	cin>>n>>n;
	int arr[n][80];
	for (int a=0; a<n; a++){
		for (int b=0; b<n; b++){
			cin>>arr[a][b];
		}
	}
	int n2;
	cin>>n2>>n2;
	int arr2[n2][80];
	for (int a=0; a<n2; a++){
		for (int b=0; b<n2; b++){
			cin>>arr2[a][b];
		}
	}
	
	
	if (n!=n2){
		cout<<"tidak identik";
	} else if (identik(arr,arr2,n)){
		cout<<"identik";
	} else if (vertikal(arr,arr2,n)){
		cout<<"vertikal";
	} else if (horisontal(arr,arr2,n)){
		cout<<"horisontal";
	} else if (kananbawah(arr,arr2,n)){
		cout<<"diagonal kanan bawah";
	} else if (kiribawah(arr,arr2,n)){
		cout<<"diagonal kiri bawah";
	} else {
		cout<<"tidak identik";
	}
	
	
	cout<<endl;
	return 0;
}
