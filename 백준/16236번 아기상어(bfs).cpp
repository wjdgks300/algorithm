#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;
int maps[21][21];
int ch[21][21];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
int res;

struct loc{
	int x,y,d;
	loc(int a, int b,int c){
		x = a;
		y = b;
		d = c;
	}
	bool operator <(const loc &b)const{
		if(d == b.d){
			if(x == b.x){
				return y > b.y;
			}else
				return x > b.x;
		}
		else
			return d > b.d;
	}
};


struct shark_baby{
	int x, y, size, exp;
	void level_up(){
		size += 1;
		exp = 0;
	}
};

priority_queue<loc> Q;
shark_baby shark;


void bfs(){
	
	while(!Q.empty()){
		loc cur = Q.top();
		Q.pop();
		
		int x = cur.x;
		int y = cur.y;
		int dis = cur.d;
		
		if(maps[x][y] !=0 && maps[x][y] < shark.size){
			shark.x = x;
			shark.y = y;
			shark.exp += 1;
			if(shark.exp == shark.size) shark.level_up();
			maps[x][y]=0;
			for(int i =0; i < n; i++){
				for(int j =0;j < n; j++){
					ch[i][j] = 0;
				}
			}
			while(!Q.empty()) Q.pop();
			res = cur.d;
		}
 		
		
		for(int i =0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= n || xx <0 || yy >=n || yy < 0 || maps[xx][yy] > shark.size || ch[xx][yy] > 0) continue;
			Q.push(loc(xx,yy, dis+1));
			ch[xx][yy]=1;
		} 
	}
	return;	
}



int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> maps[i][j];
			if(maps[i][j] == 9) {
				Q.push(loc(i,j,0));
				shark.size = 2;
				maps[i][j] = 0;
			}
		}
	}
	
	bfs();
	cout << res;
	
	
	return 0;
}