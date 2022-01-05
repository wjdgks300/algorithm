#include <iostream>
#include <vector>

int main(){
 	//freopen("input.txt", "rt", stdin);
 	
 	int n, k, sum =0, max = -217000000;
 	scanf("%d %d", &n, &k);
 	std::vector<int> num(n);
 	for(int i=0; i<n; i++){
 		scanf("%d", &num[i]);
	 }
	 
 	for(int i=0; i<n; i++){
 		if(i < k){
 			sum += num[i];
		 }
		else{
			sum = sum + num[i] - num[i - k];
			if(max < sum) max =sum; 
		}
	}
 	printf("%d", max);
	return 0;
 }