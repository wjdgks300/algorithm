#include <bits/stdc++.h>
using namespace std;

int n;
void change(string &s, int idx){
	for(int i = idx -1; i <= idx+1; i++){
		if(i < 0 || i >= s.size()) continue;
		if(s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
}

int sol(int i, string s, string t){
	int cnt = 0;
	if(i == 0){
		change(s, 0);
		cnt++;
	}
	for(int i = 1; i< n; i++){
		if(s[i-1] != t[i-1]){
			change(s, i);
			cnt++;
		}
	}
	if(s != t){
		cnt = INT_MAX;
	}
	return cnt;
}


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	string s, t;
	cin >> s >> t;
	int res = INT_MAX;
	
	for(int i = 0; i < 2; i++){
		res = min(res, sol(i, s, t));
	}
	if(res == INT_MAX){
		cout << -1;
	}
	else cout << res;
}