#include<bits/stdc++.h>	
using namespace std;

int r, c, K, length, width, maxs = 3;
vector<vector<int> > num(101,vector<int> (101,0));

struct loc{
	int var;
	int cnt;
	loc(int a, int b){
		var = a;
		cnt = b;
	}
	bool operator < (const loc &b)const{
		if(var != 0)return cnt < b.cnt;
	}
};

bool cal(int counts){
	if(length >= width){
		for(int k = 1; k <= width; k++){
			vector<int> vec = num[k];
			sort(vec.begin(), vec.end());
			vector<loc> tmp;
			for(int i = 1; i<vec.size(); i++){
				if(tmp.empty() && vec[i] != 0){
					tmp.push_back(loc(vec[i], 0));
				}if(vec[i] != 0 && tmp.back().var == vec[i]){
					loc tmps = tmp.back();
					tmps.cnt++;
					tmp.pop_back();
					tmp.push_back(tmps);
				}else if(vec[i] != 0){
					tmp.push_back(loc(vec[i],1));
				}
			}
			sort(tmp.begin(), tmp.end());
		 	int count = 1;
		 	for(int i =0; i < tmp.size(); i++){
		 		//cout << tmp[i].var << " " << tmp[i].cnt << endl;
		 		num[k][count++] = tmp[i].var;
		 		num[k][count++] = tmp[i].cnt;
		 		if(maxs < count) maxs = count;
			 }
			 for(int i = count; i <= maxs; i++){
			 	num[k][i] = 0;
			 }	
		}
		width = maxs -1;
		for(int i =1;i <=length; i++){
			for(int j = 1; j<=width; j++){
				cout <<num[i][j] << " ";
			}
			cout << endl;
		}			
		
	}else{
		for(int k = 1; k <= width; k++){
			vector<int> vec;
			vec.push_back(0);
			for(int i = 1; i <= length; i++){
				vec.push_back(num[i][k]);
			}
			sort(vec.begin(), vec.end());
			vector<loc> tmp;
			for(int i = 1; i<vec.size(); i++){
				if(tmp.empty() && vec[i] != 0){
					tmp.push_back(loc(vec[i], 0));
				}if(vec[i] != 0 && tmp.back().var == vec[i]){
					loc tmps = tmp.back();
					tmps.cnt++;
					tmp.pop_back();
					tmp.push_back(tmps);
				}else if(vec[i] != 0){
					tmp.push_back(loc(vec[i],1));
				}
			}
			sort(tmp.begin(), tmp.end());
		 	int count = 1;
		 	for(int i =0; i < tmp.size(); i++){
		 		//cout << tmp[i].var << " " << tmp[i].cnt << endl;
		 		num[count++][k] = tmp[i].var;
		 		num[count++][k] = tmp[i].cnt;
		 		if(maxs < count) maxs = count;
			 }
			 for(int i = count; i <= maxs; i++){
			 	num[i][k] = 0;
			 }	
		}
		length = maxs-1;
		
		for(int i =1;i <=length; i++){
			for(int j = 1; j<=width; j++){
				cout <<num[i][j] << " ";
			}
			cout << endl;
		}				
	}
	for(int i =1;i <=length; i++){
		for(int j = 1; j<=width; j++){
			if(num[r][c] == K) return true;
		}
	}
	
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> r >> c >> K;
	
	
	for(int i = 1; i <=3; i++){
		for(int j = 1; j <=3; j++){
			cin >> num[i][j];
		}
	}
	length = 3;
	width = 3;
	bool res = false;
	if(num[r][c] == K) {
		cout << 0;
		return 0;	
	}
	
	for(int i = 1; i<=100; i++){
		if(cal(i) == true){
			res = true;
			cout << i;
			return 0;	
		} 
	}
	
	cout << -1;
	
	
	
	return 0;
}


