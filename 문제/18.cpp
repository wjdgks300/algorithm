#include <iostream>
#include <cmath>
#include <algorithm>



int main(){
 	freopen("input.txt", "rt", stdin);
	int d[101];
	int n, max = -2147000000, cnt = 0, res = 0;
	scanf("%d %d", &n, &max);
	
	
	for(int i =0; i <n; i++){
		scanf("%d", &d[i]);
		if(d[i] > max){
			cnt++;
			if(res < cnt){
				res = cnt;
			}
		}
		else cnt =0;
	}
	if(res == 0) printf("-1\n");
	else printf("%d", res);
	
	return 0;
 }