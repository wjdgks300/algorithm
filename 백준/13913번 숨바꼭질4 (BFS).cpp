#include<bits/stdc++.h>	
using namespace std;
int n, m;
int res;
int ch[100001];
int parrent[100001];

struct loc{
	int x, cnt;
	loc(int a, int b){
		x =a;
		cnt = b;
	}
};

vector<int> path;

void bfs(int a, int b){
	queue<loc> Q;
	Q.push(loc(a, 0));
	ch[a] = 1;
	
	while(!Q.empty()){
		loc cur = Q.front();
		Q.pop();
		if(cur.x == b){
			res = cur.cnt;
			int tmp = cur.x;
			for(int i = res+ 1; i > 0; i--){
				path.push_back(tmp);
				tmp = parrent[tmp];
			}
			return;
		}
		for(int i = 0; i < 3; i++){
			if(cur.x - 1 >= 0 && ch[cur.x - 1] != 1 && i == 0){
				int xx = cur.x + (-1);
				Q.push(loc(xx, cur.cnt + 1));
				ch[xx] = 1;
				parrent[xx] = cur.x;
			}
			else if(cur.x +1 <= 100000 && ch[cur.x + 1] != 1 && i == 1){
				int xx = cur.x + 1;
				Q.push(loc(xx, cur.cnt + 1));
				ch[xx] = 1;
				parrent[xx] = cur.x;
			}
			else if((cur.x * 2) <= 100000 && ch[(cur.x * 2)] != 1 && i == 2){
				int xx = cur.x * 2;
				Q.push(loc(xx, cur.cnt + 1));
				ch[xx] = 1;
				parrent[xx] = cur.x;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	bfs(n,m);
	cout << res << endl;
	
	for(int i = res; i >=0; i--){
		cout << path[i] << " ";
	}
	
	return 0;
}


