#include<bits/stdc++.h>	

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	
	// my sol 
	int n, m;
	cin >> n >> m;
	
	vector<int> degree(m + 1,0);
	vector<int> ch(m+1, 0);
	int a, b;
	vector<pair<int, int> > tmp;
	for(int i = 0; i <m; i++){
		cin >> a >> b;
		degree[b] += 1;
		tmp.push_back(make_pair(a,b));
	}
	
	queue<int> Q;
	
	for(int i =1; i <=m; i++){
		if(degree[i] == 0){
			Q.push(i);
			ch[i] = 1;	
		} 
	}
	
	while(!Q.empty()){
		cout << Q.front() << " ";
		for(int i = 0; i <tmp.size(); i++){
			if(Q.front() == tmp[i].first) {
				degree[tmp[i].second] -= 1;	
			}
		}
		Q.pop();
		for(int i = 1; i<=m;i++){
			if(ch[i] != 1 && degree[i] == 0){
				Q.push(i);
				ch[i] = 1;
			}
		}
	}
	
	
	/*		inflearn sol 2 
	vector<vector<int> > graph(n+1, vector<int> (n+1, 0));
	for(int i = 0; i <m; i++){
		cin >> a >> b;
		degree[b] += 1;
		graph[a][b] = 1;
	}
	
	for(int i =1; i <=m; i++){
		if(degree[i] == 0){
			Q.push(i);
		} 
	}
	
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		cout << now<< " ";
		
		for(int i = 0; i <tmp.size(); i++){
			if(graph[now][i] == 1) {
				degree[i] -= 1;	
				if(degree[i]== 0) Q.push(i);
			}
		}
		
	}
	
	*/
	
	return 0;
}