#include<bits/stdc++.h>	

using namespace std;

int l, c;
vector<char> locks;
vector<char> res;

bool check(){
	int counts = 0;
	for(int i =0; i< l; i++){
		if(res[i] == 'a' || res[i]== 'e' || res[i]=='i' || res[i]=='o' || res[i]== 'u')
			counts++;
	}
	if(counts >= 1 && l - counts >=2) return true;
	return false;
}


void DFS(int a){
	if(res.size() == l){
		if(check()){
			for(int i =0; i <l; i++){
				cout << res[i];
			}
			cout << endl;
		}
	}else{
		for(int i = a; i< c; i++){
			res.push_back(locks[i]);
			DFS(i+1);
			res.pop_back();
		}
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> l >> c;
	char input;
	for(int i =0; i <c; i++){
		cin >> input;
		locks.push_back(input);
	}

	sort(locks.begin(), locks.end());
	
	DFS(0);
	
	
	return 0;
}