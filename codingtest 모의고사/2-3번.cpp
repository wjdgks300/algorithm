#include <bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	long long n,k;

	cin >> n;
	vector<long long> T(n+1);
	for(int i = 1; i <=n; i++) cin >> T[i];
	cin >> k;
	vector<long long> st(T);
	sort(st.begin(), st.end());
	long long rest = n;
	for(int i = 1; i <=n; i++){
		if(k < (rest * (st[i] - st[i-1]))){
			int index = k % rest;
			int cnt = 0;
			for(int j = 1; j <=n; j++){
				if(T[j] >= st[i]){
					if(cnt == index){
						cout << j;
						return 0;
					}
					cnt++;
				}
			} 
		}else{
			k -= (rest * (st[i] - st[i-1]));
			rest--;
		}
	}
	cout << "-1";
	return 0;
}