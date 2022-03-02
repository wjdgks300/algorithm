#include<bits/stdc++.h>	
using namespace std;

int n;
int maps[22][22];
int ch[22];

int mins = 99999999;

void DFS(int num, int idx){
	if(num -1 == n /2){
		int sum1 = 0, sum2 = 0;
		vector<int> start;
		vector<int> link;
		for(int i = 1; i <= n; i++){
			if(ch[i] == 1)
				start.push_back(i);
			else
				link.push_back(i);
		}
		
		for(int i =0; i < start.size(); i++){
			for(int j = 0;j < start.size(); j++){
				sum1 += maps[start[i]][start[j]];
				sum2 += maps[link[i]][link[j]];
			}
		}
		
		if(abs(sum1 - sum2) < mins) mins = abs(sum1- sum2); 
		return;
	}else{
		for(int i = idx; i <= n; i++){
			if(ch[i] != 1){
				ch[i] = 1;
				DFS(num+1, i);
				ch[i] = 0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i =1; i<= n; i++){
		for(int j = 1; j<= n; j++){
			cin >> maps[i][j];
		}
	}
	
	DFS(1,1);
	
	cout << mins;
	
	return 0;
}