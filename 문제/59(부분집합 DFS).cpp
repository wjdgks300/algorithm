#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int ch[11];
int n;
void DFS(int L){
	if(L == n+1){
		for(int j= 1; j<=L; j++){
			if(ch[j] == 1){
				printf("%d ", j);
			}
		}
		puts("");
	}
	else{
		ch[L]=1;
		DFS(L+1);
		ch[L] = 0;
		DFS(L+1);
	}
}


int main(){
	//freopen("input.txt", "rt", stdin);	
	scanf("%d", &n);	
	DFS(1);	
	
	return 0;
}