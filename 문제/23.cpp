#include <iostream>
#include <vector>

int main(){
 	//freopen("input.txt", "rt", stdin);
 	
 	int n, cnt =1, max = 0;
 	
 	scanf("%d", &n);
 	std::vector<int> num(n);
 	
 	for(int i=0; i< n;i++){
 		scanf("%d", &num[i]);
	 }
	
	for(int i =1; i<n; i++){
		if(num[i-1] <= num[i]) {
			cnt++;
			if(max < cnt) max = cnt;
		}
		else cnt = 1;
	}
	printf("%d", max);
	return 0;
 }