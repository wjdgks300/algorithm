#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

void recur(int k){
	if(x == 0) return;
	else{		
		recur(k -1);
		printf("%d ", k);
	}	
}

int main(){
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	recur(n);
	return 0;
}