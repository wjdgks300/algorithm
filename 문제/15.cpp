#include <iostream>
#include <cmath>




int num[200001];
int main(){
 	//freopen("input.txt", "rt", stdin);
	int n, cnt=0;
	
	scanf("%d", &n);
	for(int i =1; i<=n; i++){
		for(int j=i; j<=n; j= j+ i){
			num[j] +=1;
		}
	}
	for(int i=2; i<= n; i++){
		if(num[i] == 2){
			cnt++;
		}
	}
	printf("%d ", cnt);
	 
	return 0;
 }