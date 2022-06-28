#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int maps[600][600];
int dp[600][600];
int n, m;

int dynamic(int x, int y){
	if(x == n-1 && y == m-1) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx < 0 || xx >=n || yy <0 || yy >=m || maps[xx][yy] >= maps[x][y]) continue;
		dp[x][y] = dp[x][y] + dynamic(xx,yy);		
	}
	return dp[x][y];
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> maps[i][j];
			dp[i][j] = -1;
			//여기서 핵심 dp를 0이 아닌 -1로 초기화 해서 갈 수 있는 경로가 없을 경우 
			//0으로 바꾸는 거임 -> 이거 안하면 시간 초과 나온다.
		}
	}
	int x = 0;
	int y = 0;
	cout << dynamic(0,0) << endl;
//	for(int i = 0; i <n; i++){
//		for(int j = 0; j < m; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	//cout << dp[n-1][m-1];
	
	return 0;
}