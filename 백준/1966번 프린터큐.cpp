#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	int num;
	cin >> num;
	
	deque<pair<int,int>> q;
	for(int i = 0; i < num; i++){
		int maxs = 0;
		int n, m;
		cin >> n >> m;
		int important[10] = {0,};
		for(int j = 0; j < n; j++){
			int k;
			cin >> k;
			maxs = max(maxs, k);
			q.push_back(make_pair(k,j));
			important[k] += 1;
		}
		int cnt = 0;
		while(!q.empty()){
			if(maxs == q.front().first){
				if(m == q.front().second){
					cnt++;
					cout << cnt << endl;
					while(!q.empty()) q.pop_front();
					break;	
				}
				else{
					q.pop_front();
					cnt++;
					important[maxs]--;
					if(important[maxs] == 0){
						while(important[maxs] ==0){
							maxs--;
						}
					}
				}
			}
			else{
				pair<int, int> tmp = q.front();
				q.pop_front();
				q.push_back(tmp);
			}
		}
	}		
	return 0;
}