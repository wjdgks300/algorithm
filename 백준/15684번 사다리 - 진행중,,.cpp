#include<bits/stdc++.h>	
using namespace std;

// 왜틀렸는지 모르겠음,,,,

int ladder[32][12];
int N, M, H;

bool manipulate(){
	for(int i = 1; i<= N; i++){
		int ans = i;
		for(int j = 1; j<= H; j++){
			if(ladder[j][ans]){
				ans++;
			}
			else if(ladder[j][ans-1]){
				ans--;
			}
		}
		if(ans != i){
			return false;
		}
	}
	return true;
}


void DFS(int d, int cnt){
	if(d == cnt){
		if(manipulate()){
			cout << d;
			exit(0);
		}
		
		return;
	}else{
		for(int i= 1; i < N; i++){
			for(int j = 1; j<= H; j++){
				if(ladder[j][i-1]|| ladder[j][i] || ladder[j][i+1]) continue;
				else{
					ladder[j][i] = 1;
					DFS(d, cnt + 1);
					ladder[j][i] = 0;
					
					while(!ladder[j][i-1] && !ladder[j][i+1]) i++;
				}	
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> N >> M >> H;

	int x, y;
	for(int i =0; i< M; i++){
		cin >> y >> x;
		ladder[y][x] = 1;
	}
	for(int i =0; i < 4; i++){
		DFS(i, 0);
	}	
	cout << -1;	
	
	return 0;
}