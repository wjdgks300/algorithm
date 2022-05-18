#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int >> v;
int res= INT_MAX;
int can[2][21], ch[21];

	//my sol 
//void dfs(int d, int white, int black, int num){
//	if(d == n){
//		if(num == n/2){
//			if(res > abs(white - black)){
//				res = abs(white - black);
//			}
//		}
//		return;
//	}
//	
//	dfs(d+1, white + v[d].first, black, num+1);
//	dfs(d+1, white, black+v[d].second, num);
//	
//	return;
//}


void dfs(int L, int s){
	if(L == n/2){
		vector<int> A, B;
		for(int i = 0; i <n; i++){
			if(ch[i] == 1) A.push_back(i);
			else B.push_back(i);
		}
		int sumA = 0, sumB = 0;
		for(int i = 0; i < A.size(); i++){
			sumA+= can[0][A[i]];
			sumB+= can[0][B[i]];
		}
		res = min(res, abs(sumA - sumB));
	}
	else{
		for(int i = s; i < n; i++){
			ch[i] = 1;
			dfs(L+1, i+1);
			ch[i] = 0;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	// my sol
//	for(int i =0; i < n; i++){
//		int fir, sec;
//		cin >> fir >> sec;
//		v.push_back(make_pair(fir,sec));
//	}
//	dfs(0,0,0,0);
//	
//	cout << res;
	
	for(int i = 0; i < n; i++){
		cin >> can[0][i] >> can[1][i];
	}
	dfs(0,0);
	cout << res;
	
	return 0;
}