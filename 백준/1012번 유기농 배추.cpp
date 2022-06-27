#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int maps[51][51];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int y, int x){
	queue<pair<int, int> > q;
	q.push(make_pair(y,x));
	while(!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx < 0 || xx >=m || yy < 0 || yy >=n || maps[yy][xx] !=1)continue;
			q.push(make_pair(yy,xx));
			maps[yy][xx] = 0;
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m >> k;
		for(int j = 0; j <k; j++){
			int x, y;
			cin >> y >> x;
			maps[y][x] = 1;
		}
		int cnt = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j <n; j++){
				if(maps[j][i] == 1){
					bfs(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(maps,0,sizeof(maps));
	}
	
	return 0;
}