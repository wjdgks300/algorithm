#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int a[1501];

int main() {
	//freopen("input.txt", "rt", stdin);
	int h, w, cnt= 1, min = 2100000000;
	int n, ret = 0;
	scanf("%d", &n);	
	
	a[1] =1;
	int pos1 = 1, pos2 =1, pos3= 1;
	for(int i= 2; i<=n; i++){
		if(a[pos1]*2 < a[pos2]*3) min = a[pos1]*2;
		else min = a[pos2]*3;
		if(a[pos3]*5 <min) min = a[pos3]*5;
		if(a[pos1]*2 == min) pos1++;
		if(a[pos2]*3 == min) pos2++;
		if(a[pos3]*5 == min) pos3++;
		a[i] = min;
	}
	
	printf("%d", a[n]);
	
	return 0;
}