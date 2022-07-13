#include <bits/stdc++.h>
using namespace std;
int n, m;

struct loc{
	long long A, B, C;
} E[6001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
     
	long long visited[6001];  
	for(int i = 1; i <= n;i++){
		visited[i] = INT_MAX;
	}
    for(int i = 1; i <= m; i++){
    	long long a, b, c;
    	cin >> a >> b >> c;
    	E[i].A = a;
    	E[i].B = b;
    	E[i].C = c;
    	//if(a == 1) visited[b] = c;
	}
	
	
	visited[1] = 0;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			if(visited[E[j].A] < INT_MAX && visited[E[j].A] + E[j].C < visited[E[j].B]){
				visited[E[j].B] = visited[E[j].A] + E[j].C;
			}
		}
	}
	bool change = false;
	for(int i = 1; i <= m; i++){
		if(visited[E[i].A] < INT_MAX && visited[E[i].A] + E[i].C < visited[E[i].B]){
			change = true;
		}
	}
	
	if(change) cout << -1;
	else{
		for(int i = 2; i <=n;i++){
			if(visited[i] != INT_MAX) cout << visited[i] <<"\n";
			else cout << -1<< "\n";
		}
	}
	
	
	
	return 0;	
}
