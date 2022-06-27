#include <bits/stdc++.h>
using namespace std;

int dp[100001][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int n;	
	cin >> n;	
	//xx 
	dp[1][0] = 1;
	//ox
	dp[1][1] = 1;
	//xo
	dp[1][2] = 1;
	
	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i-1][0]+ dp[i-1][1] + dp[i-1][2];
		dp[i][1] = dp[i-1][0] + dp[i-1][2];
		dp[i][2] = dp[i-1][0] + dp[i-1][1];
		
		dp[i][0] %= 9901;
		dp[i][1] %= 9901;
		dp[i][2] %= 9901;
	}
	int res = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
	cout << res;
	
	return 0;
}