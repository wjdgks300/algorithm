#include <bits/stdc++.h>
using namespace std;

struct loc{
	int cur, pay;
	loc(int a,int b){
		cur = a;
		pay = b;
	}
	bool operator <(const loc &b)const{
		if(pay == b.pay) return cur < b.cur;
		else return pay < b.pay;
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> v[1001];
	int n, m, pay;
	cin >> n >> m;
	int maps[1002];
	fill_n(maps, 1002, 100000);

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b >> pay;
		v[a].push_back(make_pair(b,pay));
	}
	int start, end;
	cin >> start >> end;
	
	priority_queue<loc> q;
	q.push(loc(start, 0));
	int res = 100000;
	while(!q.empty()){
		loc tmp = q.top();
		int cur = tmp.cur;
		int pay = tmp.pay;
		q.pop();
		if(maps[cur] < pay) continue;
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i].first;
			int next_cost = maps[cur] + v[cur][i].second;
			if(next_cost < maps[next]){
				maps[next] = next_cost;
				q.push(loc(next, next_cost));
			}
		}
	}
	
	cout << maps[end];
	return 0;
}