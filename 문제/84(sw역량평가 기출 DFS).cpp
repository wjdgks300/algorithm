#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ch[16];
int day[16];
int pay[16];
int dest, total, maxs;

void DFS(int d, int total){
	if(d == dest){
		if(total > maxs) maxs = total;
	}else{
		if(d + day[d] <= dest) DFS(d + day[d], total + pay[d]);
		DFS(d+1, total);
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int t, p;
	scanf("%d" , &dest);
	
	for(int i =0; i< dest; i++){
		scanf("%d %d", &t, &p);
		day[i] = t;
		pay[i] = p;
	}
	
	DFS(0, 0);
	printf("%d", maxs);
	return 0;
}