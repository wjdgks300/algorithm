#include<bits/stdc++.h>	
using namespace std;

int n, m, r, c, d;
int maps[50][50];
int ch[50][50];

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int maxs = -1;
struct loc{
	int x, y, direct, counts;
	loc(int a, int b, int c, int d){
		y = a;
		x = b;
		direct = c;
		counts = d;
	}
};

void bfs(){
	queue<loc> Q;
	Q.push(loc(r,c,d,1));
	int cnt;
	while(!Q.empty()){
		loc tmp = Q.front();
		int y = tmp.y;
		int x = tmp.x;
		int direct = tmp.direct;
		cnt = tmp.counts;
		Q.pop();
		if(ch[y][x] == 0 && maps[y][x] == 0){
			ch[y][x] = 1;
			//cout << y << " " << x << endl;
		}
		//direct에 따라서 바뀌어야함 다시 짜야한다. 
		for(int i = 0; i< 4;i++){
			int yy = y + dy[direct];
			int xx = x + dx[direct];
			int dd = (direct + 3) % 4;
			if(xx < 0 && xx >=m && yy >=n && yy <0) continue;
			if(maps[yy][xx] ==0 && ch[yy][xx] != 1){
				Q.push(loc(yy,xx,dd,cnt+1));
				break;
			}
			else{
				direct = dd;
				if(i == 3){
					i = -1;
					y = y + dy[(direct+3) % 4];
					x = x + dx[(direct+3) % 4];
					if(maps[y][x] == 1)break;
				}
			}
		}
	}
	cout << cnt;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	cin >> r >> c >> d;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <m; j++){
			cin >> maps[i][j];
 		}
	}
	
	bfs();
	
	return 0;
}


