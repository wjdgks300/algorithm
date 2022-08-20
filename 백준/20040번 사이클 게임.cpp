#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[500001];

int find(int a){
	if(parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

bool is_sames(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a == b) return true;
	else{
		parent[a] = b;
		return false;
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
    	parent[i] = i;
	}
	int ans = 0;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	
    	if(is_sames(a,b)){
    		cout << i+1;
    		ans = i+1;
    		break;
		}
	}

	if(ans == 0) cout << 0;
	
    return 0;
}
