#include<bits/stdc++.h>	

using namespace std;

int cnt = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int maps[102][102];
int ch[102][102];
int n, m;
vector<int> res;

struct loc{
	int x,y;
	loc(int a, int b){
		x =a;
		y =b;
	}
};

queue<loc> Q;

void DFS(int x, int y){
	ch[x][y] = 1;
	for(int i = 0; i <4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx < 1 || xx > m || yy < 1 || yy > n) continue;
		if(maps[xx][yy] == 0 && ch[xx][yy] == 0){
			cnt++;
			DFS(xx, yy);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int l;
	cin >> m >> n >> l;
	
	//m = 5 . n = 7 
	for(int i = 0; i <=n+1; i++){
		maps[0][i] = 1;
		maps[m+1][i] = 1;
	} 
	for(int j = 0; j <= m+1; j++){
		maps[j][n+1] = 1;
		maps[j][0] = 1;
	}
	
	int x1, y1, x2, y2;
	for(int i =0; i< l; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i =x1; i <x2; i++){
			for(int j = y1; j < y2; j++){
				maps[m-j][n-i] = 1;
			}
		}
	}
	
//	for(int i = 0; i <=m+1; i++){
//		for(int j = 0; j <=n+1; j++){
//			cout << maps[i][j] << " ";
//		}	
//		cout << endl;
//	}
	
	for(int i =1; i<= m; i++){
		for(int j = 1; j<=n; j++){
			if(maps[i][j] == 0 && ch[i][j] == 0) {
				cnt = 1;
				DFS(i,j);
				res.push_back(cnt);
			}
		}
	}
	
	
	
	
	cout << res.size() << endl;
	sort(res.begin(), res.end());
	for(int i =0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	
	return 0;
}