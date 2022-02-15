#include<bits/stdc++.h>	

using namespace std;
int dy[1001];

struct Ju{
	int w, val;	
	Ju(int a, int b){
		w = a;
		val = b;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	int n, coverage;
	cin >> n >> coverage;
	vector<Ju> arr;
	
	
	for(int i = 0;i<n;i++){
		int a, b;
		cin >>a >> b;
		arr.push_back(Ju(a,b));	
	}
	
	for(int i = 0; i<n; i++){
		int wei = arr[i].w;
		for(int j = wei; j <=coverage; j++){
			dy[j] = max(dy[j], dy[j-wei] + arr[i].val);
		}
	}
	
	cout << dy[coverage];
	
	return 0;
}