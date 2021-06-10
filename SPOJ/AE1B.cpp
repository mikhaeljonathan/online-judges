#include<iostream>
#include<algorithm>
using namespace std;

int main (){
	int n,k,s;
	cin>>n>>k>>s;
	int	boxes[n];
	for (int a=0; a<n; a++){
		cin>>boxes[a];
	}
	sort(boxes,boxes+n);
	int capacity=0;
	int index=n-1;
	int counter=0;
	while(capacity<k*s){
		capacity+=boxes[index];
		index--;
		counter++;
	}
	cout<<counter<<endl;
	return 0;
}
