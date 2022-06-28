#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	int maps[n];
	vector<int> dp(n,0);
	for(int i = 0; i < n;i++){
		cin >> maps[i];
	}
	dp[0] = maps[0];
	
	for(int i = 1; i < n; i++){
		if(dp[i-1] + maps[i] > maps[i]){
			dp[i] = dp[i-1] + maps[i];
		}
		else dp[i] = maps[i];
//		cout << dp[i] << " ";
	}
	
	sort(dp.rbegin(), dp.rend());
	cout << dp[0];
	
	
	return 0;
}