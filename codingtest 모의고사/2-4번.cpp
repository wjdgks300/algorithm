#include <bits/stdc++.h>
using namespace std;

int maps[1001][1001];
int dis[2][1001][1001];

struct loc{
	int x, y;
	loc(int a, int b){
		x = a;
		y = b;
	}
};

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
int w, h;

queue<loc> Q;

void bfs(int d){
	int cnt = 1;
	while(!Q.empty()){
		cnt++;
		loc tmp = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++){
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if(xx < 0 || xx >= h || yy < 0 || yy >=w || maps[xx][yy] == 1)continue;
			if(dis[d][xx][yy] == 0){
				dis[d][xx][yy] = dis[d][tmp.x][tmp.y] + 1;
				Q.push(loc(xx,yy));	
			}
		}
	}
	return;
}



int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> w >> h;
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> maps[i][j];		
		}
	}
	
	
	int j;
	for(int i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(maps[i][j] == 2){
				Q.push(loc(i,j));
				dis[0][i][j] = 1;
				bfs(0);
				break;
			}		
		}
		if(j< w) break;
	}
	
	for(int i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(maps[i][j] == 3){
				Q.push(loc(i,j));
				dis[1][i][j] = 1;
				bfs(1);
				break;
			}		
		}
		if(j< w) break;
	}
	
	
//	for(int i = 0; i < h; i++){
//		for(int j = 0; j < w; j++){
//			cout << dis[0][i][j] << " "; 
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for(int i = 0; i < h; i++){
//		for(int j = 0; j < w; j++){
//			cout << dis[1][i][j] << " "; 
//		}
//		cout << endl;
//	}

	int res = INT_MAX;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(maps[i][j] == 4 && dis[0][i][j] >0 && dis[1][i][j] > 0){
				res = min(res,dis[0][i][j] + dis[1][i][j]);
			}
		}
	}
	cout << res - 2;

	return 0;
}