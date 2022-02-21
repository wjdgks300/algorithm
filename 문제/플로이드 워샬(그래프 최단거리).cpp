#include<bits/stdc++.h>	

using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n+1, vector<int>(n+1,9999));
	int x, y, v;
	for(int i = 1; i <=n;i++) map[i][i] = 0;
	for(int i = 1; i<=m; i++){
		cin >> x >> y >> v;
		map[x][y] = v;
	}
	
	int sum = 0;
	for(int k = 1; k <=n; k++){
		for(int i = 1; i<= n;i++){
			for(int j =1; j<= n;j++){
				if(map[i][j] > map[i][k] + map[k][j]){
					map[i][j] = map[i][k] + map[k][j];
				}
				//map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			} 
		}	
	}
	
	for(int i = 1; i<= n;i++){
		for(int j =1; j<= n;j++){
			if(map[i][j] == 9999){
				cout << "M ";
			}
			else cout << map[i][j] << " ";
		} 
		cout <<endl;
	}
	
	
	
	
	return 0;
}