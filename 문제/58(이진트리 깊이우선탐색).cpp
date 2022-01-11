#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int tmp;

void D(int v){
	if(v>7) return;
	else{
		printf("%d", v);	//전위
		D(v*2);
		//printf("%d", v);	//중위
		D(v*2+1);
		//printf("%d", v);	//후위 병합정렬
	}
}


int main(){
	//freopen("input.txt", "rt", stdin);
	D(1);
	return 0;
}