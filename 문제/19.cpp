#include <iostream>
#include <cmath>
#include <algorithm>


int num[101];
int main(){
 	//freopen("input.txt", "rt", stdin);
	int n, cnt =0, res= 0;
	scanf("%d", &n);
	for(int i =1; i<= n; i++){
		scanf("%d", &num[i]);
	}
	
//	for(int i =0; i <n ; i++){
//		for(int j = i+1; j<n; j++){
//			if(num[i] > num[j]) cnt++;
//			if(cnt == (n - (i+1))) res += 1;
//		}
//		cnt =0;
//	}
	int max;
	max = num[n];
	for(int i =n-1; i >=1; i--){
		if(num[i] > max){
			max= num[i];
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
 }