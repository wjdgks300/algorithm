#include <bits/stdc++.h>
using namespace std;
int maps[51][51];
int n, m;
int ch[51][51];
int dp[51][51];
int dx[4] = {-1,1, 0,0};
int dy[4] = {0,0,1,-1};
int maxs = 1;
int dfs(int x, int y, int v, int d){
	if(ch[x][y] == 1){
			cout << -1 << endl;
			exit(0);
	}
	if(res != 0) return res;
	int& res = dp[x][y];
	res = 1;
	ch[x][y] = 1;
	for(int i = 0; i <4; i++){
		int xx = x + dx[i] * v;
		int yy = y + dy[i] * v;
		if(xx < 0 || xx >=n || yy < 0 || yy >= m || maps[xx][yy] == 0) continue;
		res = max(res, dfs(xx,yy, maps[xx][yy], d+1) +1);
	}
	ch[x][y] = 0;
	return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    
    
    cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s; 
		cin >> s;
		for(int j = 0; j < m;j++){
			if(s[j] != 'H'){
				maps[i][j] = s[j] - '0';	
			}
			else{
				maps[i][j] = 0;
			}
			
		}
	}
    
    maxs = dfs(0,0, maps[0][0], 1);
    cout << maxs;
    
    return 0;
}
