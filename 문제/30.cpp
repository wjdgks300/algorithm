#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
	
	int n, tmp, cnt =0, res;
	scanf("%d", &n);
	
	
	// lt cw rt   
	// cw > 3 ---> (lt + 1) *k
	// cw < 3 ---> lt * k
	// cw == 3 ---> (lt * k) + (rt + 1) 
	tmp = n;
	while(tmp > 0){
		tmp /= 10;
		cnt++;
	}
	int lt=1, rt, cw, k;
	cnt -=1;
	for(int i =0; i <= cnt; i++){
		k = (int)pow(10, i);
		tmp = n / (int)pow(10, i);
		lt = tmp / 10;
		cw = tmp % 10;
		rt = n % (int)pow(10,i);
		//printf("%d %d %d\n", lt, cw, rt);
		if(cw > 3) res += (lt +1) * k;
		else if(cw <3) res += lt * k;
		else res += (lt * k) + (rt +1);
	}
	
	printf("%d", res);
	
	return 0;
 }
 
 
 