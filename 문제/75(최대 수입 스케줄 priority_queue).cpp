#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Cal{
	int pay, day;
	Cal(int a, int b){
		pay = a;
		day = b;
	}
	bool operator < (const Cal &other)const{
		return day > other.day;
	}
};

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, a, b;
	scanf("%d", &n);
	vector<Cal> T;
	priority_queue<int> pQ;
	
	for(int i =0; i<n; i++){
		scanf("%d %d", &a, &b);
		T.push_back(Cal(a,b));
	}
	sort(T.begin(), T.end());	
	
	
	int sum =0, cnt = T.front().day;
	int j = 0;
	for(int i = cnt; i>=1; i--){
		for(;j<n;j++){
			if(T[j].day<i) break;
			pQ.push(T[j].pay);
		}
		if(!pQ.empty()){
			sum += pQ.top();
			pQ.pop();
		}
	}
	printf("%d", sum);
	
 	return 0;
}