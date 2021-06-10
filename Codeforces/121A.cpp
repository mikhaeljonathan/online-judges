#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Generate(int size, vector <long long int> &v , string s = "" ){
    if (size == 0){
        long long int intStr = strtoll(s.c_str(), NULL, 10);
        v.push_back(intStr);

        return;
    }
    Generate(size - 1,v, s + "4");
    Generate(size - 1,v, s + "7");
}

long long int Sum(long long int l, long long int r, vector <long long int> vec){
    long long int sum=0;
    int index=0;
    sort(vec.begin(), vec.end());
    for(long long int i=0; i < vec.size(); i++){
        if(vec[i]>=l && vec[i]<=r) {
            sum+=(vec[i]-l+1)*vec[i];
            l=vec[i]+1;
        }
        else if(vec[i]>=l && vec[i]>r) {
            sum+=(r-l+1)*vec[i];
            break;
        }
    }
    return sum;
}

int main (){
	long long int l, r;
		cin >> l >> r;
    	vector <long long int> vec;
        for (int i = 1; i <= 10; i++){
            Generate(i,vec,"");
        }
        
        cout << Sum(l, r, vec) << endl;
	return 0;
}
