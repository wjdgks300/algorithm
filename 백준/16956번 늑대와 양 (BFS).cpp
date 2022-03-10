#include<bits/stdc++.h>	
using namespace std;

int R, C;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0,0, 1, -1};
char maps[501][501];


struct loc{
	int x, y;
	loc(int a, int b){
		x = a;
		y = b;
	}
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> R >> C;
	queue<loc> Q;
	
	for(int i = 0 ; i < R; i++){
		for(int j= 0; j < C;j++){
			cin >> maps[i][j];
			if(maps[i][j] == 'W') {
				Q.push(loc(i,j));
			} 
			//cout << maps[i][j];
		}
		//cout << endl;
	}
	
	
	
	while(!Q.empty()){
		loc tmp = Q.front();
		Q.pop();
		for(int i = 0; i<4; i++){
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			
			if(xx < 0 || xx > R || yy < 0 || yy > C) continue;
			if(maps[xx][yy] == '.') maps[xx][yy] = 'D';
			else if(maps[xx][yy] == 'S') {
				cout << '0';
				return 0;
			}  
		}
	}
	
	
	
	
	cout << '1' <<endl;
	for(int i = 0 ; i < R; i++){
		for(int j= 0; j < C;j++){
			cout << maps[i][j];
		}
		cout << endl;
	}
}