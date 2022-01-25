#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Map{
	int v, dis;
	Map(int a, int b){
		v = a;
		dis = b;
	}
	bool operator <(const Map &b)const{
		return dis > b.dis;
	}
};



int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	priority_queue<Map> Q;
	vector<pair<int, int> > map[30];
	vector<int> dist(n+1, 2147000000);
	for(int i = 0; i <m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b,c));
	}
	Q.push(Map(1,0));
	dist[1] = 0;
	
	while(!Q.empty()){
		int now = Q.top().v;
		int cost = Q.top().dis;
		Q.pop();
		if(cost > dist[now]) continue;
		for(int i =0; i < map[now].size(); i++){
			int next = map[now][i].first;
			int nextdis = cost + map[now][i].second;
			if(dist[next] > nextdis){
				dist[next] = nextdis;
				Q.push(Map(next, nextdis));
			}
		}
	}
	for(int i = 2; i<=n; i++){
		if(dist[i]!= 2147000000) cout<< i << " : " <<dist[i] << endl;
		else cout << i << " : impossible" <<endl;
	}
	
	return 0;
}