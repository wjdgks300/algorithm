#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int maps[102][102];
	
	
	
	int n, m, r;
	cin >> n >> m >> r;
	int val[n];
	fill(maps[1], maps[n+1], 99999); // -1,0 이외의 것으로 초기화 할때는 fill을 사용해야 한다. 
	
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}
	
	
	for(int i = 0; i < r; i++){
		int x, y, l;
		cin >> x >> y >> l;
		maps[x][y] = l;
		maps[y][x] = l;
	}
	for(int i = 1; i <= n; i++){
		maps[i][i] = 0;
	}
	
	
	for(int k = 1; k <= n;k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
			}
		}
	}
	
//	for(int i = 1; i <=n; i++){
//		for(int j =1; j <=n; j++){
//			cout << maps[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	int max_val = 0;
	
	
	for(int i = 1; i <=n; i++){
		int sum = 0;
		for(int j = 1; j <=n; j++){
			if(maps[i][j] <= m){
				sum += val[j];
			}
		}
		if(max_val < sum) max_val = sum;
	}
	
	cout << max_val;
	
	return 0;
}