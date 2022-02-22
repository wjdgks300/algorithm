#include<bits/stdc++.h>	

using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<vector<int>> map(n+1, vector<int>(n+1, 9999));
	vector<int> res(n+1);
	int a, b;
	
	while(1){
		cin>> a >> b;
		if(a==-1 && b ==-1) break;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for(int i = 1; i <=n;i++) map[i][i] = 0;
	
	
	for(int k = 1; k <=n; k++){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j <=n; j++){
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	
	int count = 0, mins= 9999;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j <=n; j++){
			res[i] = max(res[i], map[i][j]);
		}
		mins = min(mins, res[i]);
	}

	
	for(int i = 1; i <=n; i++){
		if(mins == res[i]) count++;
	}
	
	cout << mins << " " << count << endl;
	for(int i = 1; i <= n; i++){
		if(mins == res[i]) cout << i << " ";
	}
	
	
	
	return 0;
}