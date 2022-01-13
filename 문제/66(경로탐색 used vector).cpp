#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;
int ch[30], cnt =0, n; 
vector<int> map[30];

void DFS(int L){
	if(n==L){
		cnt++;
	}else{
		for(int i =0; i< map[L].size(); i++){
			if(ch[map[L][i]]==0){
				ch[map[L][i]] =1;
				DFS(map[L][i]);
				ch[map[L][i]] =0;
			} 
		}
	}
}

int main(){
	//freopen("input.txt", "rt", stdin);
	int m, i, j, a, b;
	scanf("%d %d", &n, &m);
	for(int i =1; i<= m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}
	ch[1] =1;
	DFS(1);
	printf("%d", cnt);
	return 0;
}