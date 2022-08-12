#include <bits/stdc++.h>
using namespace std;
int res[500002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    
    int N, H;
    cin >> N >> H;
    vector<int> down;
    vector<int> up;
    
    for(int i = 0; i < N; i++){
    	int num;
    	cin >> num;
    	if(i % 2 == 0){
    		down.push_back(num);
		}
		else{
			up.push_back(num);
		}
	}
	
	sort(down.rbegin(), down.rend());
	sort(up.rbegin(), up.rend());
	
	int cnt = 1;
	for(int i = 0; i < down.size(); i++){
		if(i == down.size() -1){
			for(int j = down[i]; j > 0; j--){
				res[j] = cnt;
			}
		}
		else{
			for(int j = down[i]; j > down[i+1]; j--){
				res[j] = cnt;
			}	
		}
		cnt++;
	}
	
	
	int cnt2 = 1;
	for(int i = 0; i < up.size(); i++){
		if(i == up.size() -1){
			for(int j = H+1-up[i]; j < H+1;j++){
				res[j] += cnt2;
			}
		}
		else{
			for(int j = H+1-up[i]; j < H+1-up[i+1]; j++){
				res[j] += cnt2;
			}	
		}
		cnt2++;
	}
	
	int min = INT_MAX;
	int res_cnt = 0;
	for(int i = 1; i<= H; i++){
		if(min > res[i]) {
			res_cnt = 1;
			min = res[i];
		}
		else if(min == res[i]){
			res_cnt++;
		}
	}
	cout <<min <<" "<< res_cnt;
	
	
	
    return 0;
}
