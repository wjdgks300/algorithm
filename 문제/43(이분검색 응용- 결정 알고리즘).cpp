#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[1001], n;

int count(int s){
	int cnt =1, sum =0;
	for(int i = 0; i<n; i++){
		if(sum+num[i] > s){
			cnt++;
			sum = num[i];		
		}else{
			sum += num[i];
		}
	}
	return cnt;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int m, lt = 0, rt, mid, max, res, maxx = 0;
	scanf("%d %d", &n, &m);
	
	for(int i =0;i < n; i++){
		scanf("%d", &num[i]);
		max += num[i];
		if(num[i] > maxx) maxx = num[i];
	}
	rt = max-1;
	int ret = 0;
	while(lt <= rt){
		mid = (lt + rt) / 2;
		if(count(mid) <= m && mid >= maxx){
			res=mid;
			rt = mid - 1;
		}else{
			lt = mid + 1;
		}
	}
	printf("%d", res);
	
	return 0;
}