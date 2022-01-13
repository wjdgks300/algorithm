#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int sum = 0, n, cost = 214900000;
int ch[30];
vector<pair<int, int> > map[30];


void DFS(int L, int sum){
	if(L == n){
		if(cost > sum){
			cost = sum;
		}
	}else{
		for(int i = 0; i<map[L].size(); i++){
			if(ch[map[L][i].first] == 0){
				ch[map[L][i].first] =1;
				DFS(map[L][i].first, sum + map[L][i].second);
				ch[map[L][i].first] =0;
			}
		}
	}
}


int main(){
	//freopen("input.txt", "rt", stdin);
	int m, a, b, c;
	scanf("%d %d", &n, &m);
	for(int i= 0; i <m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b,c));
	}
	ch[1] =1;
	DFS(1, 0);
	
	printf("%d", cost);
	
	return 0;
}



