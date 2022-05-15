#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<string> v;
	int min = 100;
	for(int i =0;i < n; i++){
		string tmp;
		cin >> tmp;
		if(tmp.size() < min) min = tmp.size(); 
		v.push_back(tmp);
	}
	
	int res =min;
	for(int i = 0; i< min; i++){
		char tmp = v[0][i];
		for(int j = 0; j < n;j++){
			if(tmp != v[j][i]){
				res = i;
				for(int i = 0; i < res; i++){
					cout << v[0][i];
				}
				return 0;
			}
		}		
	}
	
	for(int i = 0; i < res; i++){
		cout << v[0][i];
	}
		
	return 0;
}