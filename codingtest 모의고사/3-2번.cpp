#include <bits/stdc++.h>
using namespace std;

struct loc{
	int x;
	loc(int a){
		x =a;
	}
	bool operator <(const loc &b)const{
		return x < b.x;
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	
	vector<int> t(n+1);
	for(int i = 1; i <=n;i++){
		cin >> t[i];
	}
	
	sort(t.begin(), t.end());
	int res = 0;
	int i;
	for(i =n; i>=4; i-=2){
		res+= min(t[i]+t[1]+t[i-1]+t[1], t[2]+t[2]+t[i]+t[1]);
	}
	if(i == 3){
		res += t[1]+t[2]+t[3];
	}
	if(i==2){
		res +=t[2];
	}
	if(i==1){
		res +=t[1];
	}
	cout << res;
	return 0;
}