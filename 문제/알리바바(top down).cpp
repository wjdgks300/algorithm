#include<bits/stdc++.h>	

using namespace std;

int maps[21][21];
int res[21][21];
int max, n;


int DFS(int x, int y){
	if(x ==0 && y ==0){
		return maps[0][0];
	}
	else if(x <= 0){
		return res[x][y] = DFS(x,y-1) + maps[x][y];
	}else if(y <=0){
		return res[x][y] = DFS(x-1, y) + maps[x][y];
	}
	else{
		return res[x][y]= min(DFS(x-1, y), DFS(x, y-1)) + maps[x][y];
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i =0; i<n;i++){
		for(int j= 0; j<n; j++){
			cin >> maps[i][j];
		}
	}	
	
	cout << DFS(n-1, n-1);
	
	
	return 0;
}