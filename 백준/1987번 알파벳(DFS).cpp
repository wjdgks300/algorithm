#include<bits/stdc++.h>	

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maxs;
int R, C;
vector<int> trace(26);
vector<string> maps(21);

void DFS(int x, int y, int sum){
	if(maxs < sum){
		maxs = sum;	
	} 
	for(int i =0; i < 4; i++){
		int check = 0;
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx < 0 || xx >= R || yy < 0 || yy >= C) continue;
		else{
			if(trace[maps[xx][yy] -'A'] == 1) continue;
			else{
				trace[maps[xx][yy] - 'A'] = 1;
				DFS(xx, yy, sum +1);
				trace[maps[xx][yy] - 'A'] = 0;
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	

	cin >> R >> C;
	
	for(int i =0; i <R; i++){
		cin >> maps[i];
	}
	
//	for(int i = 0; i <R; i++){
//		for(int j= 0; j<C; j++){
//			cout << maps[i][j];
//		}
//		cout << endl;
//	}
	
	trace[maps[0][0] - 'A'] = 1;
	DFS(0,0,1);
	cout << maxs << endl;
	
	return 0;
}