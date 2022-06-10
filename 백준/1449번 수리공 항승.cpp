#include <bits/stdc++.h>
using namespace std;



int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int n, l;
	cin >> n >> l;
	vector<int> v;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	int cur = 0, cnt = 0;
	int tmp = cur;
	for(int i = 0; i < n; i++){
		if(v[tmp]-0.5 + l < v[i]){
			cnt++;
			tmp = cur++;
		}
		else cur++;
	}
	cnt++;
	cout << cnt;
	
	return 0;
}