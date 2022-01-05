#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, lt = 0, rt, mid;
	scanf("%d %d", &n, &m);
	vector<int> num(n);
	for(int i =0;i < n; i++){
		scanf("%d", &num[i]);
	}
	sort(num.begin(), num.end());
	rt = n-1;
	while(lt <= rt){
		mid = (lt+rt) / 2;
		if(num[mid] == m){
			printf("%d", mid+1);
			break;
		}else if(num[mid] > m){
			rt= mid -1;
		}else{
			lt = mid+1;
		}
	}
	
	
	return 0;
}