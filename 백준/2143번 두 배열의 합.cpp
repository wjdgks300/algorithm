#include <bits/stdc++.h>
using namespace std;
int a[1001];
int b[1001];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	int n, m;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	
	vector<long long> v;
	vector<long long> v2;
	
	for(int i = 0; i <n; i++){
		long long sum = a[i];
		v.push_back(sum);
		for(int j = i +1; j <n;j++){
			sum += a[j];
			v.push_back(sum);
		} 
	}
	
	for(int i = 0; i <m; i++){
		long long sum = b[i];
		v2.push_back(sum);
		for(int j = i +1; j <m;j++){
			sum += b[j];
			v2.push_back(sum);
		} 
	}
	
	sort(v2.begin(), v2.end());
	
	// upper bound, lower bound 사용법 
//	vector<int> arr = { 1,3,5,5,7,8,8,10,10,11,13 };
//	cout << "5 이상 11 이하의 갯수 : " << upper_bound(arr.begin(), arr.end(), 11) - lower_bound(arr.begin(), arr.end(), 5);
	
	long long res = 0;
	for(int i = 0; i < v.size(); i++){
		int find = t - v[i];
		res += upper_bound(v2.begin(), v2.end(), find) - lower_bound(v2.begin(), v2.end(), find);
	}
	
	cout << res;
	
	return 0;
}