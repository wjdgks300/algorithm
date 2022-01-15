#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[10001];

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k, x, cnt= 0, pos = 0;
	queue<int> Q;
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i<=n; i++){
		Q.push(i);
	}
	
	while(!Q.empty()){
		for(int i =1; i< k; i++){
			Q.push(Q.front());
			Q.pop();
		}
		Q.pop();
		if(Q.size() == 1){
			printf("%d", Q.front());
			Q.pop();
		}
	}
	return 0;
}