#include<bits/stdc++.h>	

using namespace std;

int maps[21][21];
int res[21][21];
int max, n;


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i =0; i<n;i++){
		for(int j= 0; j<n; j++){
			cin >> maps[i][j];
		}
	}	
	
	res[0][0] = maps[0][0];
	
	for(int i = 1; i <n; i++){
		res[i][0] = res[i-1][0] + maps[i][0];
		res[0][i] = res[0][i-1] + maps[0][i];
	}
	
	for(int i=1; i <n;i++){
		for(int j = 1; j<n;j++){
			res[i][j] = min(res[i-1][j], res[i][j-1]) + maps[i][j];
		}
	}
	
	cout << res[n-1][n-1];
	return 0;
}