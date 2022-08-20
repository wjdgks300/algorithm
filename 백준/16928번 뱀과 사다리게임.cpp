#include <bits/stdc++.h>
using namespace std;

int n, m, mins = 100;
int ch[120];
struct loc{
	int s, e;
	loc(int a, int b){
		s= a;
		e= b;
	}
};

vector<loc> v;

void bfs(int x){
	queue<loc> q;
	q.push(loc(x,0));
	while(!q.empty()){
		int cur = q.front().s;
		int cnt = q.front().e;
		q.pop();
		if(cur == 100){
			mins = min(cnt, mins);
		}
		if(cur >100 || mins < cnt) continue;
		
		
		for(int i = 1; i <=6; i++){
			bool use = false;
			for(int j = 0; j < n+m; j++){
				if(cur + i == v[j].s){
					if(ch[cur+i] == 0){
						q.push(loc(v[j].e, cnt+1));
						ch[cur+i] = 1;
						use = true;	
					}
				}
			}
			if(use == false && ch[cur+i] == 0){
				q.push(loc(cur+i, cnt+1));	
				ch[cur+i] = 1;
			}
		}
		
	}
	return;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    
    
    
    for(int i = 0; i < n; i++){
    	int s, e;
    	cin >> s >> e;
    	v.push_back(loc(s, e));
	}
	
	for(int i = 0; i < m; i++){
    	int s, e;
    	cin >> s >> e;
    	v.push_back(loc(s, e));
	}
	
	bfs(1);
	cout << mins;
	
	
    return 0;
}
