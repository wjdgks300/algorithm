#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[10];
int a[10];
//s e n d m o r y 
int send(){
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}
int more(){
	return a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[1];
}
int money(){
	return a[4] * 10000 + a[5] * 1000 + a[2] * 100 + a[1] * 10 + a[7];
}
void DFS(int d){
	if(d == 8){
		if(send() + more() == money()){
			if(a[0] == 0 || a[4] == 0) return;
			printf("%d %d %d %d \n", a[0], a[1], a[2], a[3]);
			printf("%d %d %d %d \n", a[4], a[5], a[6], a[1]);
			printf("--------------\n");
			printf("%d %d %d %d %d\n", a[4], a[5], a[2], a[1], a[7]);
		}
	}else{
		for(int i =0; i < 10; i++){
			if(ch[i] == 0){
				a[d] = i;
				ch[i] = 1;
				DFS(d + 1);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	DFS(0);
	return 0;
}