#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, num[21][21], cnt;
int ch[21];
bool flag = true;
void DFS(int L){
	if(L == n){
		cnt++;
	}
	else{
		for(int i =1; i<=n; i++){
			if(num[L][i] == 1 && ch[i] == 0){
				ch[i]= 1;
				DFS(i);
				ch[i]= 0;
			}
		}
	}
}


int main() {
	//freopen("input.txt", "rt", stdin);
	int m, a, b, k;
	scanf("%d %d" ,&n, &m);
	
	
	for(int i =0; i< m; i++){
		scanf("%d %d", &a, &b);
		num[a][b] = 1;
	}
	ch[1]=1;
	DFS(1);
	
	printf("%d", cnt);
	
	
	return 0;
}