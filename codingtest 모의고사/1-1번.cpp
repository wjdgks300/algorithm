#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<string> v;
	int min = INT_MAX;
	for(int i =0;i < n; i++){
		string tmp;
		cin >> tmp;
		if(tmp.size() < min) min = tmp.size(); 
		v.push_back(tmp);
	}
	
	
	// my sol 
//	int res =min;
//	for(int i = 0; i< min; i++){
//		char tmp = v[0][i];
//		for(int j = 0; j < n;j++){
//			if(tmp != v[j][i]){
//				res = i;
//				for(int i = 0; i < res; i++){
//					cout << v[0][i];
//				}
//				return 0;
//			}
//		}		
//	}
//	
//	for(int i = 0; i < res; i++){
//		cout << v[0][i];
//	}
	
	//sol 1 
//	string res = "";
//	for(int i = 0; i < min; i++){
//		string tmp = "";
//		for(auto &s : v) tmp+= s[i];
//		int m = count(tmp.begin(), tmp.end(), tmp[0]);
//		if(m == n) res += tmp[0];
//		else break;
//	}
//	cout << res;
	
	
	//sol 2 use 'set'
//	string res = "";
//	for(int i = 0; i < min; i++){
//		set<char> tmp;
//		for(auto &s : v) tmp.insert(s[i]);
//		if(tmp.size() == 1) res += v[0][i];
//		else break;
//	}
//	cout << res;
	
	
	//sol3 
	
	
	string res = v[0];
	//cout << res;
	for(int i = 1; i < v.size(); i++){
		while(v[i].find(res) != 0){
			res = res.substr(0,res.size()-1);
		}
	}
	cout << res;
	return 0;
}