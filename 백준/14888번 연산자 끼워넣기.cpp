#include <bits/stdc++.h>
using namespace std;

int N;
int num[12];
int oper[4];
int maxs = INT_MIN, mins = INT_MAX;
void dfs(int d, int sum){
	if(d == N-1){
		if(maxs < sum) {
			maxs = sum;
		}
		if(mins > sum){
			mins = sum;
		}
	}
	for(int i = 0; i < 4; i++){
		if(oper[i] > 0){
			if(i == 0){
				oper[i]--;
				dfs(d+1, sum + num[d+1]);
				oper[i]++;
			}
			if(i == 1){
				oper[i]--;
				dfs(d+1, sum - num[d+1]);
				oper[i]++;
			}
			if(i == 2){
				oper[i]--;
				dfs(d+1, sum * num[d+1]);
				oper[i]++;
			}
			else if(i == 3){
				oper[i]--;
				dfs(d+1, sum / num[d+1]);
				oper[i]++;
			}
		}
	}
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
    	cin >> num[i];
	}
    
    
    for(int i = 0; i < 4; i++){
    	cin >> oper[i];
	}
    
    dfs(0, num[0]);
    
    cout << maxs << "\n" << mins;
	return 0;	
}
