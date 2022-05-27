#include <bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	string s, t;
	cin >> s >> t;
	unordered_map<char, int> th;
	unordered_map<char, int> sh;
	
	for(int i = 0; i < t.size(); i++){
		th[t[i]]++;
	}
	for(int i = 0; i < t.size()-1; i++){
		sh[s[i]]++;
	}
	int lt = 0, rt = t.size()-1;
	int count = 0;
	for(int i = rt; i < s.size();i++){
		sh[s[i]]++;
		if(th == sh){
			count++;
		}
		sh[s[lt]]--;
		if(sh[s[lt]] == 0){
			sh.erase(s[lt]);
		}
		lt++;
	}
	
	cout << count;
	
	
	return 0;
}