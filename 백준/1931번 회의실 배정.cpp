#include <bits/stdc++.h>
using namespace std;


int n;

struct loc{
	int s, e;
	loc(int a, int b){
		s = a;
		e = b;
	}
	bool operator <(const loc &b){
		if(e == b.e) return s < b.s;
		return e < b.e;
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	cin >> n;
	vector<loc> v;
	for(int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		v.push_back(loc(s,e));
	}
	sort(v.begin(), v.end());
	
	int pre = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(pre <= v[i].s){
			pre = v[i].e;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}