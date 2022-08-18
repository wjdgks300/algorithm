#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[201][201];
int res[201];
int cnt = 1;

void bfs(int a){
	queue<int> q;
	q.push(a);
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(maps[t][i] == 1 && res[i] == 0){
				q.push(i);
				res[i] = cnt;
			}
		}
	}
	
	
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> maps[i][j];
		}
	}
	
	
	for(int i = 1; i <= n; i++){
		if(res[i] == 0){
			bfs(i);	
			res[i] = cnt++;
		}	
	}
	int pre = 0;
	for(int i = 1; i <= m; i++){
		int num;
		cin >> num;
		if(i >=2){
			if(pre != res[num]){
				cout << "NO";
				exit(0);
			}
		}
		pre = res[num];
	}
	cout << "YES";
	
    return 0;
}
