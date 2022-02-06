#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int num[11];
int ex[4];
int n;
int maxx, minn = 999999;


void DFS(int d, int s){
	if(d == n){
		if(s > maxx){
			maxx = s;
		}
		else if(s < minn){
			minn = s;
		}
	}else{
		for(int i = 0; i<4;i++){
			if(ex[i] >= 1){
				if(i == 0){
					ex[i] -= 1;
					DFS(d+1, s + num[d]);
					ex[i] += 1;
				}else if(i == 1){
					ex[i] -= 1;
					DFS(d+1,  s - num[d]);
					ex[i] += 1;
				}else if(i == 2){
					ex[i] -= 1;
					DFS(d+1,  s * num[d]);
					ex[i] += 1;
				}else{
					ex[i] -= 1;
					DFS(d+1,  s / num[d]);
					ex[i] += 1;
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	
	for(int i =0; i <n; i++){
		scanf("%d", &num[i]);
	}
	for(int i =0; i < 4; i++){
		scanf("%d", &ex[i]);
	}
	
	
	DFS(1, num[0]);
	printf("%d \n%d",maxx, minn);
	
	return 0;
}