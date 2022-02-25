#include<bits/stdc++.h>	

using namespace std;

int maps[25][25];
int ch[25][25];
int n, cnt;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> res;

void DFS(int x,int y){
	ch[x][y] = 1;
	for(int i =0; i<4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx < 0 || xx >=n || yy < 0 || yy >=n) continue;
		if(maps[xx][yy] == 1 && ch[xx][yy] == 0){
			cnt++;
			DFS(xx,yy);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	string line;
	for(int i =0; i < n; i++){
		cin >> line;
		for(int j =0; j< n; j++){
			maps[i][j] = line[j] - '0';
 		}
	}
	
//	for(int i =0; i < n; i++){
//		for(int j = 0; j <n; j++){
//			cout << maps[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for(int i =0; i <n; i++){
		for(int j = 0; j <n; j++){
			if(maps[i][j] == 1 && ch[i][j] == 0){
				cnt = 1;
				DFS(i,j);
				res.push_back(cnt);
			}
		}
	}
	
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(int i =0 ; i< res.size(); i++){
		cout << res[i] << endl;
	}
	return 0;
}