//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 1234567890
using namespace std;
int N;
int W[16][16];
int cost[16][(1 << 16)];
int allvisit;
int dfs(int start, int visits){
	if(visits == allvisit){
		if(W[start][0] == 0) return INF;
		else return W[start][0];
	}
	if(cost[start][visits] != -1) return cost[start][visits];
	cost[start][visits] = INF;
	
	for(int i =0; i < N; i++){
        if(W[start][i] == 0) continue;
		if((visits & (1 << i)) == (1 << i))continue;
		cost[start][visits] = min(cost[start][visits] , W[start][i] + dfs(i, visits | 1 << i));
	}
	return cost[start][visits];
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < N; j++){
    		cin >> W[i][j];
		}
	}
	
	memset(cost, -1, sizeof(cost));
	allvisit = (1 << N) -1;
    cout << dfs(0,1);
    
    
    
	return 0;	
}
