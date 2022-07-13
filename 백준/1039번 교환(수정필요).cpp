#include <bits/stdc++.h>
using namespace std;

int cal_num(string n){
	int num = 0;
    for(int i = 0; i < n.size(); i++){
    	num *= 10;
    	num += n[i] - '0';
	}
	return num;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    string n;
    int K;
    
    cin >> n >> K; 
    int change = n.size() - 1;
	int num = cal_num(n);
    
	queue<string> q;
	q.push(n);
	int cnt = 1;
	int maxs= 0;
	while(!q.empty()){
		string fr = q.front();
		q.pop();
		int check_f = 0;
		int check_s = 0;
		for(int j = cnt; j < n.size()-1;j++)
			for(int i = j+1; i< n.size(); i++){
				string tmp = fr;
				char k = tmp[j];
				tmp[j] = tmp[i];
				tmp[i] = k;
				if(maxs < cal_num(tmp)){
					maxs = cal_num(tmp);
					check_f = j;
					check_s = i;	
				}
			}
		
		
		string tmp = fr;
		char k = tmp[check_f];
		tmp[check_f] = tmp[check_s];
		tmp[check_s] = k;
		q.push(tmp);
		cnt++;
		if(cnt> K){
			while(!q.empty()){
				q.pop();
			}	
			break;
		}
		if(cnt >= n.size()){
			
			change = cnt - change;
			break;	
		} 
	}
	
	if(change != n.size() -1){
		//cout << change;
		if(change % 2 != 0){
			int fir = maxs % 10;
			maxs /= 10;
			int sec = maxs  % 10;
			maxs /= 10;
			maxs *= 10;
			maxs += fir;
			maxs *= 10;
			maxs += sec;
			cout << maxs;
		}
		else cout << maxs;
	}
	else cout << maxs;
    
    return 0;
}
