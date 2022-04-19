#include<bits/stdc++.h>	
using namespace std;

int n, m;
char maps[501][501];
int ch[501][501];

int dfs(int y, int x){
	if(y < 0 || x < 0 || y >= n || x >= m) return 1;
	
	int& ret = ch[y][x];
	
	if(ret != -1){
		return ret;
	}
	ret = 0;
	
	if(maps[y][x] == 'D'){
		return ret = dfs(y+1, x);
	}
	else if(maps[y][x] == 'R'){
		return ret = dfs(y, x+1);
	}
	else if(maps[y][x] == 'L'){
		return ret = dfs(y, x-1);
	}
	else if(maps[y][x] == 'U'){
		return ret = dfs(y-1, x);
	}
	
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> maps[i][j];
		}
	}

	memset(ch, -1, sizeof(ch));
	
	int cnt = 0;
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			cnt += dfs(i,j);
		}
	}
	
	cout << cnt;
	return 0;
}


