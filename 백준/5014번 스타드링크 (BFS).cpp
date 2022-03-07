#include<bits/stdc++.h>	
using namespace std;

int F,S,G,U,D;


struct loc{
	int cur, cnt;
	loc(int a, int b){
		cur = a;
		cnt = b;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> F >> S >> G >> U >> D;
	int ans = -1;
	vector<int> ch(F+1);
	queue<loc> Q;
	Q.push(loc(S, 0));
	ch[S] = 1;
	
	while(!Q.empty()){
		loc tmp = Q.front();
		Q.pop();
		if(tmp.cur == G) {
			ans = tmp.cnt;
			break;	
		} 
		
		if((tmp.cur + U) <= F && ch[tmp.cur + U] != 1){
			Q.push(loc(tmp.cur + U, tmp.cnt + 1));
			ch[tmp.cur + U] = 1;
		}	
		
		if((tmp.cur - D) > 0 && ch[tmp.cur - D] != 1){
			Q.push(loc(tmp.cur - D, tmp.cnt + 1));
			ch[tmp.cur - D] = 1;
		}	 			
			
			
	}
	
	if(ans != -1) cout << ans;
	else cout << "use the stairs";
	return 0;
}