#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,r;
int ch[20];

void DFS(int s, int L){
	if(L == r){
		for(int j =0; j<L; j++){
			cout<<ch[j] << " ";
		}
		cout <<endl;
	}else{
		for(int i =s; i<n;i++){
			ch[L] = i;
			DFS(i+1, L+1);
		}
	}
}

int main(){
	//freopen("input.txt", "rt", stdin);
	cin >>n >>r;
	DFS(0, 0);
	return 0;
}