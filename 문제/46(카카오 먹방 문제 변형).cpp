#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	//freopen("input.txt", "rt", stdin);
	int n , k, pos = 0, sum =0, cnt = 0;
	scanf("%d", &n);
	int num[n+1];
	for(int i =1; i<=n; i++){
		scanf("%d", &num[i]);
		sum += num[i];
	}
	scanf("%d", &k);
	
	if(sum <= k){
		printf("-1");
		return 0;
	}
	
	while(1){
		pos++;	
		if(pos > n) pos =1; 
		if(num[pos] != 0){
			num[pos] -= 1;
			cnt++;
		} 
		if(cnt == k) break;
	}
	
	while(1){
		pos++;
		if(pos>n) pos =1;
		if(num[pos] != 0) break;
	}
	
	printf("%d", pos);	
	
	return 0;
}