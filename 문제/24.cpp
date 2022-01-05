#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdlib>

int main(){
 	//freopen("input.txt", "rt", stdin);
 	
	int n, pre;
 	scanf("%d", &n);
 	std::vector<int> num(n+1);
 	std::vector<int> b(n+1);
 	for(int i =1; i<=n; i++){
 		scanf("%d", &num[i]);
	 }
	 
	 pre = num[1];
	 for(int i=2; i<=n; i++){
	 	if(abs(num[i] -pre) >= n){
	 		printf("NO");
	 		exit(0);
		}
		else if(b[abs(num[i] - pre)] ==1){
			printf("NO");
	 		exit(0);
		}
	 	b[abs(num[i] - pre)] =1;
	 	pre = num[i];
	}
	
	for(int i=1; i<n-1; i++){
		if(b[i] != 1) {
			printf("NO");
			exit(0);
		}
	} 
 	printf("YES");
	return 0;
 }