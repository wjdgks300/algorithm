#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int tmp;

void recur(int k){
	if(k == 0) return;
	else{
		recur(k/2);
		printf("%d", k % 2); 
	}	
}

int main(){
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	recur(n);
	return 0;
}