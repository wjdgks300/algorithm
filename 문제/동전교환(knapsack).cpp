#include<bits/stdc++.h>	

using namespace std;
vector<int> dy(100, 500);


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n, m;
	cin >> n;
	vector<int> arr;
	for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cin >> m;
	dy[0] = 0;
	for(int i = 0; i<n; i++){
		int v = arr[i];
		for(int j = v; j <=m; j++){
			dy[j] = min(dy[j], dy[j-v] + 1);			
		}
	}
	
	cout << dy[m];
	
	return 0;
}