#include <bits/stdc++.h>
using namespace std;
int n,m;
int maps[102][102];
int res[102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
    	int s, e, p;	
    	cin >> s>>e >>p;
    	if(maps[s][e] == 0){
    		maps[s][e] = p;	
		}
    	else {
    		maps[s][e] = min(maps[s][e], p);
		}
    	
	}
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(maps[i][j] == 0) maps[i][j] = 9999999;
		}
	}
	
	
	// floyd
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
	    	for(int j = 1; j <= n; j++){
	    		if(i == j || i == k || j == k) continue;
	    		maps[i][j] = min(maps[i][j] , maps[i][k] + maps[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(maps[i][j] == 9999999) cout << 0 << " ";
    		else cout << maps[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	
    return 0;
}
