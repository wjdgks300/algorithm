#include<bits/stdc++.h>	
using namespace std;
int n, m;
int goal_y, goal_x;

char maps[11][11];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int ch[11][11][11][11];
int counts;

struct loc{
	int by, bx, rx, ry, cnt;
	loc(int a, int b, int c,int d, int e){
		ry = a;
		rx = b;
		by = c;
		bx = d;
		cnt = e;
	}
};


int bfs(int by, int bx, int ry, int rx){
	queue<loc> Q;
	Q.push(loc(ry,rx,by,bx,0));
	while(!Q.empty()){
		loc cur = Q.front();
		Q.pop();
		
		if(cur.rx == goal_x && cur.ry == goal_y){
			counts = cur.cnt;
			break;
		}
		
		for(int i =0; i <4; i++){
			int rxx = cur.rx;
			int ryy = cur.ry;
			int bxx = cur.bx;
			int byy = cur.by;
			while(maps[ryy + dy[i]][rxx + dx[i]] != '#' && maps[ryy][rxx] != 'O'){
				rxx += dx[i];
				ryy += dy[i];
				
			}
			while(maps[byy + dy[i]][bxx + dx[i]] != '#' && maps[byy][bxx] != 'O'){
				bxx += dx[i];
				byy += dy[i];
			}
			
			if(maps[byy][bxx] == 'O') continue;
			if(maps[ryy][rxx] == 'O') {
				Q.push(loc(ryy, rxx, byy, bxx, cur.cnt +1));
				break;
			}
			
			if(ryy == byy && rxx == bxx){
				if(maps[ryy][rxx] == 'O') continue;
				int k = (i + 2) % 4;
				
				if((abs(ryy - cur.ry) + abs(rxx - cur.rx)) > (abs(byy - cur.by) + abs(bxx - cur.bx))){
					ryy += dy[k];
					rxx += dx[k];
				} 
				else{
					byy += dy[k];
					bxx += dx[k];
				}
			}

			
			if(ch[ryy][rxx][byy][bxx] != 1){
				Q.push(loc(ryy, rxx, byy, bxx, cur.cnt +1));
				ch[ryy][rxx][byy][bxx] = 1;
			}
			
		}
	}
	return counts;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int r_x, r_y, b_x, b_y;
	cin >> n >> m;
	
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> maps[i][j];
			if(maps[i][j] == 'B'){
				b_y = i;
				b_x = j;
			}
			else if(maps[i][j] == 'R'){
				r_y = i;
				r_x = j;
			}
			else if(maps[i][j] == 'O'){
				goal_y = i;
				goal_x = j;
			}
		}
	}
	
	int res = bfs(b_y, b_x, r_y, r_x);
	if(res == 0){
		cout << "-1";
	}
	
	else cout << res;
	
	
	return 0;
}


