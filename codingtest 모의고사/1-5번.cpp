#include <bits/stdc++.h>
using namespace std;
int n, m, r;
struct loc{
	int st, et, get;
	loc(int a, int b, int c){
		st = a;
		et = b;
		get = c;
	}
	bool operator <(const loc& b)const{
		return st < b.st;
	}
};
vector<loc> v;
	
int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m >> r;
	int dy[m], answer =INT_MIN;
	
	for(int i = 0 ; i < m; i++){
		int s,e,g;
		cin >> s >> e >> g;
		v.push_back(loc(s,e,g));
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < m; i++){
		dy[i] = v[i].get;
	}
	
	for(int i = 1; i< m; i++){
		for(int j = i-1; j >=0; j--){
			if(v[j].et+r <= v[i].st){
				dy[i] = max(dy[j] + v[i].get, dy[i]);
			}
		}
		answer = max(answer, dy[i]);
	}
	
	//cout << dy[m-1];
	
	cout << answer;

	return 0;
}