#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int sum = 0, n, minx = 214900000;
int ch[30];
vector<vector<int>> num(30, vector<int>(30));


void DFS(int L){
	if(L == n){
		if(minx > sum){
			minx = sum;
		}
	}else{
		for(int i = 1; i<=n; i++){
			if(ch[i] == 0 && num[L][i] != 0){
				ch[i] =1;
				sum += num[L][i];
				DFS(i);
				sum -= num[L][i];
				ch[i] = 0;
			}
		}
	}
}


int main(){
	//freopen("input.txt", "rt", stdin);
	int m, a, b, k;
	scanf("%d %d",&n, &m);
	for(int i =1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &k);
		num[a][b] = k;
	}
	
	ch[1] =1;
	DFS(1);
	
	printf("%d", minx);
	
	return 0;
}



