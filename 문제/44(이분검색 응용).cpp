#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;

int count(int mid){
	int sum = 0, cnt = 1, pos;
	pos = a[0];
	for(int i =1; i < n; i++){
		if(a[i] - pos >= mid){
			cnt++;
			pos = a[i];
		}
	}
	return cnt;
}


int main(){
	int c, lt =0, rt, mid, ret, tmp;
	scanf("%d %d", &n, &c);	
	
	for(int i =0; i<n;i++){
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	
	rt = a[n-1] - a[0];

	while(lt <= rt){
		mid = (lt + rt) / 2;
		if(count(mid) >= c){
			ret = mid;
			lt = mid +1;
		}else rt = mid -1;
	}
	
	
	printf("%d", ret);
	return 0;
}