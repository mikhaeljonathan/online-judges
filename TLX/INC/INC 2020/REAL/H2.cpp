#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;

int item[100100];
vector<int> buyer;

priority_queue<int> pq;

int main(){
	int N, M;
	scanf("%d",&N); //item
	for(int i=0;i<N;i++){
		scanf("%d",&item[i]);
	}
	scanf("%d",&M); //buyer
	for(int i=0;i<M;i++){
		int num;
		scanf("%d",&num);
		buyer.push_back(num);
		pq.push(num);
	}
	
	int itemNow=0, res = 0;
	for(int i=0;i<N;i++){
		itemNow = item[i];
		
		int flag = 0;
		for(int j = 0; j < buyer.size(); j++){
			if(buyer[j] >= itemNow){
				itemNow = buyer[j] + 1;
				buyer.erase(buyer.begin() + j);
				if(flag == 0){
					res++;
					flag = 1;
				}
				j--;
			}
			if(buyer[j] == pq.top()){
				pq.pop();
				break;
			}
		}
	}
	
	printf("%d\n",res);
	
	return 0;
}
