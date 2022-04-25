#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> maps(200000, 0);
int n, c;

int Count(int m){
	int cnt = 1;
	int cur = 0;
	for(int i = 1; i < n; i++){
		if(maps[i] - maps[cur] >= m){
			cnt++;
			cur = i;
		}
	}
	return cnt;
}

int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> maps[i];
	}
	sort(maps.begin(), maps.begin()+n);
	
	int lt = maps[0], rt = maps[n-1], res = 0; 
	while(lt <=rt){
		int mid = (lt + rt)/2;
		if(Count(mid) >= c){
			res = mid;
			lt = mid + 1;
		}
		else{
			rt = mid - 1;
		}
	}
	
	cout << res;
	return 0;
}