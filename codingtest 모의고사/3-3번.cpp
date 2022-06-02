#include <bits/stdc++.h>
using namespace std;
struct loc{
	char t;
	int str;
	int num;
	loc(int a, int b, int c){
		t =a;
		str = b;
		num = c;
	}
	bool operator <(const loc& b){
		return str < b.str;
	}
};

int res[200000];
int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<loc> v;
	vector<int> res(n); 
	
	for(int i = 0; i < n; i++){
		char team;
		int str;
		cin >> team >> str;
		v.push_back(loc(team, str, i));
	}
	
	sort(v.begin(), v.end());
	unordered_map<char,int> t;
	int sum = 0;
	
	int j = 0;
	for(int i = 1; i <n; i++){
		for( ; j < n; j++){
			if(v[i].str > v[j].str){
				sum += v[j].str;
				t[v[j].t] += v[j].str;
			}
			else break;
		}
		res[v[i].num] = sum -t[v[i].t];
	}
	
	for(int i = 0; i < n; i++){
		cout << res[i] << endl;	
	}
	
	return 0;
}