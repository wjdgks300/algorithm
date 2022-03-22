#include<bits/stdc++.h>	
using namespace std;

int maps[6][6];
int cnt;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int ch[1000000];

void dfs(int x, int y, int d, int cur){
	if(d == 5){
		if(ch[cur] !=1){
			ch[cur] = 1;
			cnt++;
		}
		return;
	}
	else{
		for(int i =0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx < 0 || xx >= 5 || yy < 0 || yy >=5) continue;
			dfs(xx,yy, d+1, cur* 10 + maps[xx][yy]);
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	for(int i =0 ; i< 5; i++){
		for(int j= 0; j < 5; j++){
			cin >> maps[i][j];
		}
	}
	
	for(int i =0; i < 5; i++){
		for(int j = 0; j< 5; j++){
			dfs(i,j,0, maps[i][j]);
		}
	}
	cout << cnt << endl;
	
	
	return 0;
}


