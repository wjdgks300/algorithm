#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int cal(int k){
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(k > v[i]){
			sum += v[i];
		}
		else{
			sum += k;
		}
	}
	return sum;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin >> n;
		
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);	
	}
	sort(v.rbegin(), v.rend());
	int rt = v[0];
	int lt = 0, mid = 0, res= 0;
	cin >> m;
	
	while(lt <=rt){
		mid = (lt+rt)/2;
		if(cal(mid) <= m){
			res = mid;
			lt = mid +1;
		}else{
			rt = mid -1;
		}
	}
	
	cout << res;
	return 0;
}