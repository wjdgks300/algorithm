#include<bits/stdc++.h>	
using namespace std;

int N, M, cnt = 1;
char maps[11][11];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool ch[11][11][11][11];


struct loc{
	int rx,ry,bx,by, dd;
	loc(int a, int b, int c, int d, int e){
		ry = a;
		rx = b;
		by = c;
		bx = d;
		dd = e;
	}
};
queue<loc> Q;

void bfs(){
	
	while(!Q.empty()){
		loc tmp = Q.front();
		Q.pop();
		if(tmp.dd >= 10){
			break;	
		} 
		 
		if(maps[tmp.ry][tmp.rx] == 'O') return; //return result
		for(int i = 0; i< 4; i++){
			int r_y = tmp.ry;
			int r_x = tmp.rx;
			int b_y = tmp.by;
			int b_x = tmp.bx;
			int d = tmp.dd;
			while(maps[r_y + dy[i]][r_x + dx[i]] != '#' && maps[r_y][r_x] != 'O'){
				r_y +=dy[i];
				r_x +=dx[i];
			}
			
			while(maps[b_y + dy[i]][b_x + dx[i]] != '#' && maps[b_y][b_x] != 'O'){
				b_y +=dy[i];
				b_x +=dx[i];
			}
			if(maps[b_y][b_x] == 'O') continue;
			if(maps[r_y][r_x] == 'O') {
				cout << "1" << endl;
				return;
			}
			if(b_y == r_y && b_x == r_x){
				if(maps[r_y][r_x] == 'O') continue;
				if((abs(r_y - tmp.ry)+abs(r_x - tmp.rx)) < (abs(b_y - tmp.by)+abs(b_x - tmp.bx))){
					b_y = b_y - dy[i];
					b_x = b_x - dx[i];
				}
				else{
					r_y = r_y - dy[i];
					r_x = r_x - dx[i];
				}
			}
			if(ch[r_y][r_x][b_y][b_x])continue;
			Q.push(loc(r_y,r_x,b_y, b_x, d+1));
			
			ch[r_y][r_x][b_y][b_x] = true;
			//cout << r_y << " " << r_x << endl;
		}
	}
	cout << "0" << endl;
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> N >> M;
	int rx,ry,bx,by;
	
	for(int i = 0; i< N; i++){
		for(int j= 0; j < M; j++){
			cin >> maps[i][j];
			if(maps[i][j] == 'R'){
				ry = i;
				rx = j;
			}
			else if(maps[i][j] == 'B'){
				by = i;
				bx = j;
			}
		}
	}
	
	//cout << red_start[0].y << " " << red_start[0].x;
	ch[ry][rx][by][bx] = true;
	Q.push(loc(ry, rx, by, bx,0));
	bfs();
	
	
	return 0;
}


