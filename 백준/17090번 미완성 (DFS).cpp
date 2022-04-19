#include<bits/stdc++.h>	
using namespace std;

int n, m;
char maps[501][501];
int ch[501][501];
int ch2[501][501];
int res;

void dfs(int y, int x, int count){
	if(y < 0 || x < 0 || y >= n || x >=m){
		res = count;
		return;	
	}
	else{
		if(ch[y][x] != 1){
			if(maps[y][x] == 'U'){
				ch[y][x] = 1;
				if(ch2[y][x] == 1){
					dfs(y-1, x, count);
				}
				else{
					ch2[y][x] = 1;
					dfs(y-1, x, count + 1);
				}	
			}
			else if(maps[y][x] == 'R'){
				ch[y][x] = 1;
				if(ch2[y][x] == 1){
					dfs(y, x+1, count);
				}
				else{
					ch2[y][x] = 1;
					dfs(y, x+1, count + 1);
				}
			}
			else if(maps[y][x] == 'D'){
				ch[y][x] = 1;
				if(ch2[y][x] == 1){
					dfs(y+ 1, x, count);
				}
				else{
					ch2[y][x] = 1;
					dfs(y + 1, x, count + 1);
				}
			}
			else if(maps[y][x] == 'L'){
				ch[y][x] = 1;
				if(ch2[y][x] == 1){
					dfs(y, x-1, count);
				}
				else{
					ch2[y][x] = 1;
					dfs(y, x -1, count + 1);
				}
			}
		}
	}
	return;
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
	
	int cnt = 0;
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			res = 0;
			if(ch2[i][j] != 1){
				dfs(i,j, 0);
				memset(ch, 0, sizeof(ch));
				if(res > 0) cnt += res;
			}
		}
	}
	
	cout << cnt;
	return 0;
}


