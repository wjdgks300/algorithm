#include<bits/stdc++.h>	
using namespace std;

int x, k;
int dx[3] = {-1, 1, 2};
int mins = 99999;
int ch[100001];

struct loc{
	int x, cnt;
	loc(int a, int b){
		x =a;
		cnt = b;
	}
};

int bfs(int s){
	queue<loc> Q;
	Q.push(loc(s, 0));
	int var = 0;
	while(!Q.empty()){
		loc tmp = Q.front();
		Q.pop();
		ch[tmp.x] = 1;
		if(tmp.cnt > mins) continue;
		if(tmp.x == k){
			if(mins > tmp.cnt){
				mins  = tmp.cnt;
				var = 1;
			}else if(mins == tmp.cnt){
				var++;
			}
		}
		for(int i =0; i <3; i++){
			int xx;
			if(i < 2){
				xx = tmp.x + dx[i];	
				if(xx >=0 && xx <= 100000 && ch[xx] != 1){
					Q.push(loc(xx, tmp.cnt + 1));		
				}
				
			
			}else{
				xx = tmp.x * dx[i];				
				if(xx <= 100000 && ch[xx] != 1 ){
					Q.push(loc(xx, tmp.cnt + 1));		
				}			
			}
		}
	}	
	
	return var;
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin >> x >> k;
	int v;
	v = bfs(x);
	
	cout << mins << "\n" << v;
	return 0;
}


