#include<bits/stdc++.h>	
using namespace std;

int n, a, b;
int ch[10001];

int D(int a){
	a = (a *2) % 10000;
	return a;
}
int S(int a){
	if(a != 0){
		a -= 1;	
	}
	else a = 9999;
	return a;
}

int L(int a){
	int current = a;
	a = (current % 1000) * 10 + (current / 1000);
	return a;
}
int R(int a){
	int current = a;
	a = current / 10 + (current % 10) * 1000;
	return a;
}

vector<string> res;	//stack also can use


void BFS(){
	queue<pair<int, string> > Q;
	Q.push(make_pair(a, ""));
	ch[a] = 1;
	
	while(!Q.empty()){
		int tmp = Q.front().first;
		string tmp2 = Q.front().second;
		Q.pop();
		
		if(tmp == b){
			cout << tmp2 << endl;
			return;
		}
		
		int d = D(tmp);
		if(ch[d] != 1){
			ch[d] = 1;
			Q.push(make_pair(d, tmp2 + "D"));
		}
		
		int s = S(tmp);
		if(ch[s] != 1){
			ch[s] = 1;
			Q.push(make_pair(s, tmp2 + "S"));
		}
		
		int l = L(tmp);
		if(ch[l] != 1){
			ch[l] = 1;
			Q.push(make_pair(l, tmp2 + "L"));
		}
		
		int r = R(tmp);
		if(ch[r] != 1){
			ch[r] = 1;
			Q.push(make_pair(r, tmp2 + "R"));
		}
		
	}
}




int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		memset(ch, 0, sizeof(ch));
		BFS();
	}
	
	
	return 0;
}