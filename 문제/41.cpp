#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, sum =0, cnt= 0, j, k;
	scanf("%d", &n);
	sum = 1;
	for(int i =2; i <n;i++){
		sum+= i;
		k = n - sum;
		if(k % i == 0){
			k /= i;
			for(j= 1; j <i; j++){
				printf("%d + ", k +j);
			}
			printf("%d = %d\n", k+j, n);
			cnt++;
		}
		if(sum >= n){
			printf("%d", cnt);
			break;
		} 
	}

	return 0;
}