//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a[1000001];
int dp[1000001];

struct loc{
	int prev_idx, val;
	loc(int a,int b){
		prev_idx = a;
		val = b;
	}
	bool operator<(const loc &b)const{
		return val < b.val;
	}
};

loc T[1000001];
int T_length;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
    
	
    for(int i = 1; i <=n ;i++){
    	loc *idx = lower_bound(T, T + T_length, a[i]);
    	
	}
    
    
	return 0;	
}
