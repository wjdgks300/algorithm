#include<bits/stdc++.h>	

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<string> vps(n);
	
	for(int i =0; i < n; i++){
		cin >> vps[i];
	}
	
	for(int i = 0; i< vps.size(); i++){
		stack<int> s;
		int check =0;
		for(int j = 0; j < vps[i].size(); j++){
			if(vps[i][j] == '('){
				s.push(1);
			}
			else{
				if(s.empty()){
					cout << "NO" << endl;
					check =1;
					break;
				}
				s.pop();	
			}
		}
		if(s.empty() && check !=1){
			cout << "YES" << endl;
		}
		else if(check != 1){
			cout << "NO" << endl;
		}
	}
	
	return 0;
}