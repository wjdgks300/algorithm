#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int >> v;
int res= 999999999;

void dfs(int d, int white, int black, int num){
	if(d == n){
		if(num == n/2){
			if(res > abs(white - black)){
				res = abs(white - black);
			}
		}
		return;
	}
	
	dfs(d+1, white + v[d].first, black, num+1);
	dfs(d+1, white, black+v[d].second, num);
	
	return;
}


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i =0; i < n; i++){
		int fir, sec;
		cin >> fir >> sec;
		v.push_back(make_pair(fir,sec));
	}
	dfs(0,0,0,0);
	
	cout << res;
	
	
	return 0;
}