#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	// <map>
	string a = "It is time to Study Go Go";
	//map<char, int> ch;
	//unordered_map<char, int> ch;
//	for(auto x : a){
//		if(x != ' ') ch[x]++;
//	}
//	for(auto it=ch.begin(); it !=ch.end(); it++){
//		cout << it->first << " " << it->second<<endl;
//	}
	
	map<string, int> ch;
	string tmp;
	for(auto x : a){
		if(x==' '){
			ch[tmp]++;
			tmp.clear();
		}
		else tmp+=x;
	}
	ch[tmp]++;

	for(auto x : ch) cout << x.first << " " << x.second << endl;
	
	
	return 0;
}