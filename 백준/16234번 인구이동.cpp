#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int ch[200][200] = {-1,};
int ch2[200][200];
int maps[200][200];
int n, l, r;
int res[50000000];
int sum[50000000];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
int max_d;


struct loc{
	int x, y;
	loc(int a, int b){
		x = a;
		y = b;
	}
};

queue<loc> vec;
int bfs(int counts){
	int cnt = 0;
	while(!vec.empty()){
		loc tmp = vec.front();
		int x = tmp.x;
		int y = tmp.y;
		vec.pop();
		for(int i = 0; i < 4; i++){
			int xx = dx[i] + x;
			int yy = dy[i] + y;
			if(xx < 0 || xx >=n || yy < 0 || yy >=n) continue;
			int diff = abs(maps[xx][yy] - maps[x][y]);
			if(ch[xx][yy] == -1 && diff >= l && diff <= r){
				ch[xx][yy] = counts;
				cnt++;
				sum[counts] += maps[xx][yy];
				vec.push(loc(xx,yy));
			}
		}
	}
	return cnt;
}

bool check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++){
			for(int k = 0; k < 4; k++){
				int xx = i + dx[k];
				int yy = j + dy[k];
				if(xx < 0 || xx >=n || yy < 0 || yy >=n) continue;
				int tmp = abs(maps[xx][yy] - maps[i][j]);
				if(tmp >= l && tmp <= r) return true;
			}
		}
	}
	return false;
}

void cal(int k){
	for(int i = 0; i <n; i++){
		for(int j = 0; j<n; j++){
			if(ch[i][j] == k){
				maps[i][j] = sum[k] /res[k];
			}
		}
	}
}


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> l >> r;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> maps[i][j];
		}
	}
	int k = 0;
	int result_cnt = 0;
	while(check()){
		result_cnt++;
		memset(ch, -1, sizeof(ch));
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(ch[i][j] == -1&& ch[i][j] < k){
					vec.push(loc(i,j));
					res[k]=bfs(k);
					if(res[k]> 1) cal(k);
					k++;
				}
			}
		}

		for(int i = 0; i <n; i++){
			for(int j = 0; j<n; j++){
				if(ch[i][j] == k){
					cout << maps[i][j] << endl;
				}
			}
		}
	}
	
	cout << result_cnt;
	
	return 0;
}