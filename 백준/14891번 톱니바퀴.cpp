#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int dir[5];
vector<string> v(5);

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	for(int i = 1; i <= 4; i++){
		cin >> v[i];
	}
	int n, a,b;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(b == -1){
			dir[a] = -1;
		}else{
			dir[a] = 1;
		} 
		
		for(int j = a-1; j >= 1; j--){
			if(v[j][2] != v[j+1][6]){
				dir[j] = -dir[j+1];
			}
		}
		
		for(int j = a+1; j <=4; j++){
			if(v[j][6] != v[j-1][2]){
				dir[j] = -dir[j-1];
			}
		}
		
		
		for(int i =1; i <=4; i++){
			if(dir[i] == -1){
				char tmp;
				tmp = v[i][0];
				v[i].erase(v[i].begin());
				v[i].insert(v[i].end(),tmp);
			}
			else if(dir[i] == 1){
				char tmp;
				tmp = v[i][7];
				v[i].erase(v[i].end() -1);
				v[i].insert(v[i].begin(),tmp);
			}
		}		
		//initial
		for(int i =1; i <=4; i++){
			//cout << dir[i];
			dir[i] = 0;
		}
		
//		cout << endl;
//		for(int k = 1; k  <=4; k++){
//			for(int i = 0; i < 8; i++){
//				//cout << v[k][i];
//			}
//			//cout << endl;
//		}
//		//cout << endl;
	}
	
	int ans = 0;
	for(int i = 1; i <= 4; i++){
		
		if(v[i][0] == '1') ans += pow(2,i-1);
		//cout << i << "" << endl;	
	}
	
	cout << ans;
	
	return 0;
}