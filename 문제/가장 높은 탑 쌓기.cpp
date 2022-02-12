#include<bits/stdc++.h>	

using namespace std;


struct Loc{
	int x;
	int h;
	int w;
	Loc(int a, int b, int c){
		x = a;
		h = b;
		w = c;
	}
	bool operator <(const Loc &bb)const{
		return x > bb.x;			// 앞에 자료가 크면 내림차순 암기해두자 
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, res = 0;
	cin >> n;
		
	vector<Loc> arr;
	vector<int> dy(n+1);
	
	for(int i = 1; i<=n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(Loc(a,b,c));
	}
	
	sort(arr.begin(), arr.end());
	
	//for(auto pos : arr) cout << pos.x << pos.h << pos.w << endl;
	
	dy[0] = arr[0].h;
	res = dy[0];
	for(int i = 1; i < n; i++){
		int max_h = 0;
		for(int j = i-1; j >=0; j--){
			if(arr[j].w > arr[i].w && dy[j] > max_h){
				max_h = dy[j];
			}
		}
		dy[i] = max_h + arr[i].h;
		res = max(res, dy[i]);
	}
	
	cout << res;
	
	
	return 0;
}