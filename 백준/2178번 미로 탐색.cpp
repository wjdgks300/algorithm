#include <bits/stdc++.h>
using namespace std;
int N, M;
int maps[101][101];
int ch[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
struct loc{
	int x, y, cnt;
	loc(int a, int b, int c){
		x =a;
		y = b;
		cnt = c;
	}
	
};


int bfs(){
	queue<loc> q;
	q.push(loc(0,0,1));
	ch[0][0] = 1;
	while(!q.empty()){
		loc tmp = q.front();
		q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int cnt = tmp.cnt;
		for(int i = 0; i < 4; i++){
			if(x + dx[i] >= N || x + dx[i] < 0 || y + dy[i] >= M || y +dy[i] < 0) continue;
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(ch[xx][yy] == 1 || maps[xx][yy] == 0) continue;
			if(xx == N-1 && yy == M-1) return cnt+1;
			q.push(loc(xx,yy, cnt+1));
			//cout << xx << yy << endl;
			ch[xx][yy] = 1;
		}
	}
	return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    
    
    string st;
    
    for(int i = 0; i < N; i++){
    	cin >> st;
    	for(int j = 0; j < M; j++){
    		maps[i][j] = st[j] - '0';
		}
	}
    
    int res = bfs();
    
    
    cout << res;
	return 0;	
}
