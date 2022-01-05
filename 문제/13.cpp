#include <iostream>
#include <cmath>



char num[101];
 int main(){
 	//freopen("input.txt", "rt", stdin);
 	 	
	scanf("%s", &num);
	int n[10] = {0,};
	for(int i=0; num[i] != '\0'; i++){
		
		n[(int)(num[i]- 48)] +=1;
		
	}		
	int max = -1, max_num = 0;
	
	for(int i =0; i <= 9; i++){ 
		if(max < n[i]){
			max = n[i];
			max_num = i;
		}
		else if(max == n[i]){
			if(max_num < i) max_num = i;
		}
	}
	printf("%d", max_num);
	
	return 0;
 }