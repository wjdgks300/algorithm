#include<bits/stdc++.h>	
using namespace std;

int n, m, res;
int maps[9][9];
int ch[9][9];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//int count(){
//	int cnt = 0;
//	for(int i =0; i <n; i++){
//		for(int j = 0; j< m; j++){
//			if(maps[i][j] == 0) cnt++;
//		}
//	}
//	return cnt;
//}

struct loc{
	int x,y;
	loc(int a, int b){
		y = a;
		x = b;
	}
};


void virus(){
	queue<loc> Q;
	
	int aftervirus[n][m];
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j< m; j++){
			aftervirus[i][j] = maps[i][j];
			if(aftervirus[i][j] == 2) Q.push(loc(i,j));
		}
	}
	
	while(!Q.empty()){
		loc tmp = Q.front();
		int x = tmp.x;
		int y = tmp.y;
		Q.pop();
		for(int i =0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(yy < 0 || yy >=n || xx < 0|| xx >= m) continue;
			if(aftervirus[yy][xx] == 0){
				aftervirus[yy][xx] = 2;
				Q.push(loc(yy,xx));
			}
		}
	}
	
	int cnt = 0;
	for(int i =0; i <n; i++){
		for(int j = 0; j< m; j++){
			if(aftervirus[i][j] == 0) cnt++;
		}
	}
	if(res < cnt) res = cnt;
	
}



void dfs(int d, int y, int x){
	if(d== 3){
		virus();
		return;	
	}
	else{
		for(int i =y ; i< n; i++){
			for(int j = x; j < m; j++){
				if(maps[i][j] == 0){
					maps[i][j] = 1;
					dfs(d+1, y, x);
					maps[i][j] = 0;
				}
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 0; i <n;i++){
		for(int j= 0; j <m; j++){
			cin >> maps[i][j];
		}
	}
	
	for(int i = 0; i< n; i++){
		for(int j =0; j< m; j++){
			dfs(0,i,j);
		}
	}
	
	cout << res;
	
	return 0;
}


