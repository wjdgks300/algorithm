#include <iostream>
#include <cmath>


 int main(){
 	//freopen("input.txt", "rt", stdin);
 	int n, res = 0, tmp;
 	int cnt =0;
	scanf("%d", &n);
 	
 	for(int i=1; i <= n; i++){
 		tmp = i;
 		cnt = 0;
 		while(tmp > 0){
 			tmp = tmp /10;
 			cnt++;
		}
		res += cnt; 
	 }
 	
	printf("%d", res);
	
	
	
	return 0;
 }