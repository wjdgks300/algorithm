#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dy[21][21];

int DFS(int n, int r){
	if(dy[n][r] > 0) return dy[n][r];
	if(n==r || r==0) return 1;
	else return dy[n][r] = DFS(n-1, r-1) + DFS(n-1, r);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d", DFS(n, r));
 	return 0;
}