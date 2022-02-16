#include<bits/stdc++.h>	

using namespace std;
vector<vector<int>> dy(100,vector<int>(100,0));


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	vector<int> dy2(m+1);
	int score, time;
//	for(int i =1; i<=n; i++){
//		cin >> score >> time;
//		dy[i].assign(dy[i-1].begin(), dy[i-1].end());
//		for(int j = time; j <=m; j++){
//			dy[i][j] = max(dy[i][j], dy[i-1][j -time] + score);
//		}	
//	}
	
	for(int i =1; i <= n; i++){
		cin >> score >> time;
		for(int j= m; j >=time; j--){
			dy2[j] = max(dy2[j], dy2[j-time] + score);
		}
	}
	cout << dy2[m];
	return 0;
}