#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int a[11];
int n, m, total = 0, cnt = 0;
bool flag;
void DFS(int L, int sum) {
	
	if(L == n+1){
		if(total < sum || sum < 0) return;
		if(sum ==m)	cnt++;
	}
	else{
		DFS(L+1, sum + a[L]);
		DFS(L+1, sum - a[L]);
		DFS(L+1, sum);
	} 
}


int main(){
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n ;i++){
		scanf("%d", &a[i]);
		total += a[i];
	}
	
	DFS(1, 0);	
	if(cnt > 0){
		printf("%d", cnt);
	}
	else printf("-1");
	
	return 0;
}



