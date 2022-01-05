#include <iostream>
#include <cmath>
#include <algorithm>


int num[11], res[11];

int main(){
 	//freopen("input.txt", "rt", stdin);
	
	int n;
	scanf("%d", &n);
	
	for(int i =0; i< n; i++){
		scanf("%d %d", &num[i], &res[i]);
	}
	int sum =0;
	for(int i=0; i < n; i++){
		for(int j=1; j<= num[i]; j++){
			sum += j;
		}
		if(sum == res[i]) printf("YES\n");
		else printf("NO\n");
		sum =0;
	}
	
	return 0;
 }