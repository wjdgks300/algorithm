#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
	int n, k, pos =0, cnt = 0, bp =0;
	scanf("%d %d", &n, &k);
	vector<int> num(n+1);
	
	while(1){
		pos++;
		if(pos >n) pos = 1;
		if(num[pos] == 0){
			cnt++;
			if(cnt==k){
				num[pos] =1;
				cnt=0;
				bp++;
			}
		}
		if(bp == n-1) break;	
	}
	for(int i =1; i<=n; i++){
		if(num[i] == 0){
			printf("%d", i);
			break;
		}
	}
	
	
	return 0;
}