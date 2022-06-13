#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int> v;
	for(int i =0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	int res[n] = {0,};
	res[0] =1;
	int maxs= 0;
	for(int i = 1; i< n; i++){
		for(int j = 0; j < i; j++){
			if(v[j] < v[i]){
				res[i] = max(res[i] ,res[j]+1);
			}
		}
		if(res[i] == 0) res[i] = 1;
		maxs = max(maxs, res[i]);
	}
	if(maxs == 0) maxs = 1;
//	for(auto a :res) cout << a << " ";
	cout << maxs;
	
	return 0;
}