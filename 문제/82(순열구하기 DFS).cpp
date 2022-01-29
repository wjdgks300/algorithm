#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, r, cnt = 0;
vector<int> map(16);
int ch[16], res[16];
void DFS(int d){
	if(d == r){
		for(int j = 0; j < d; j++){
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}else{
		for(int i = 1; i<=n; i++){
			if(ch[i] == 0){
				res[d] = map[i];
				ch[i] = 1;
				DFS(d +1);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &r);
	for(int i = 1; i<= n; i++){
		scanf("%d", &map[i]);
	}

	DFS(0);
	printf("%d\n", cnt);
	return 0;
}