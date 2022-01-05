#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, lt = 0, rt, mid, max, sum =0, cnt = 0;
	scanf("%d %d", &n, &m);
	vector<int> num(n);
	
	for(int i =0;i < n; i++){
		scanf("%d", &num[i]);
		max += num[i];
	}
	rt = max-1;
	
	int ret = 0;
	while(lt != rt){
		mid = (lt + rt) / 2;
		for(int i =0; i < n; i++){
			if(sum < mid)sum += num[i];
			else if(sum >= mid){
				sum = 0;
				cnt++;
			}
		}
		if(cnt ==3){
			ret = mid;
			rt = mid -1;		
		}
		else if(cnt <3){
			lt = mid+1;			
		}else{
			rt = mid -1;
		}
	}
	printf("%d", mid);
	
	
	
	return 0;
}