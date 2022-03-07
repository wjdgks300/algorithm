#include<bits/stdc++.h>	
using namespace std;
int n, k;
int res[101][100001];
int w[101];
int v[101];

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	//dp로 풀어야함!! DFS로 풀면 시간 초과 
	
	cin >> n >> k;
	
	
	
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
	}
	
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<= k; j++){
			if(j- w[i] >=0){
				res[i][j] = max(res[i-1][j], v[i] + res[i-1][j-w[i]]);
			}
			else res[i][j] = res[i-1][j];
		}
	}
	
	cout << res[n][k];
	return 0;
}