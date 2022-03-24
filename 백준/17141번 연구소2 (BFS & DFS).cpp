#include<bits/stdc++.h>	
using namespace std;

int n, m, res;
int maps[51][51];
int ch[51][51];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int mins = 9999;

struct loc{
	int x,y;
	loc(int a, int b){
		y = a;
		x = b;
	}
};

vector<loc> virus_vec;
vector<loc> select_virus;

void virus(){
	queue<loc> Q;
	int res = 0;
	int tmps[n][n];
	memset(tmps,0,sizeof(tmps));
	for(int i = 0; i < select_virus.size(); i++){
		Q.push(loc(select_virus[i].y, select_virus[i].x));
		tmps[select_virus[i].y][select_virus[i].x] = 1;
	}
	
	
	while(!Q.empty()){
		loc tmp = Q.front();
		int x = tmp.x;
		int y = tmp.y;
		Q.pop();
		for(int i =0; i < 4; i++){
			int yy = y + dy[i];
			int xx = x + dx[i];
			if(yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
			if(maps[yy][xx] != 1 && tmps[yy][xx] == 0){
				tmps[yy][xx] = tmps[y][x] + 1;
				res = tmps[yy][xx];
				Q.push(loc(yy,xx));
			}
		}
	}
	
	bool checks = true;
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n;j++){
			if(tmps[i][j] == 0){
				if(maps[i][j] != 1){
					checks = false;
				}
				
			}
		}
	}
	if(mins > res && checks == true) mins = res;
}



void dfs(int d, int y, int x){
	if(d== m){
		virus();
		return;	
	}
	else{
		for(int i =y; i< n; i++){
			for(int j = x; j < n; j++){
				if(maps[i][j] == 2 && ch[i][j] != 1){
					ch[i][j] = 1;
					select_virus.push_back(loc(i,j));
					dfs(d+1, i, j);
					select_virus.pop_back();
					ch[i][j] = 0;
				}
				
			}
			x=0;
		}
	
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 0; i <n;i++){
		for(int j= 0; j <n; j++){
			cin >> maps[i][j];
			if(maps[i][j] == 1){
				ch[i][j] = -1;
			}
			else if(maps[i][j] == 2){
				virus_vec.push_back(loc(i,j));
			}
		}
	}
	
	dfs(0,0,0);
	
	if(mins != 9999){
		if(mins != 0)
			cout << mins -1;
		else
			cout << 0;
	}
	else{
		cout << -1;
	}
	
	return 0;
}


