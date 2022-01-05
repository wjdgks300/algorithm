#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, n2, pos = 0, choose=0, tmp;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &n2);
	vector<int> b(n2);
	for(int i=0; i<n2; i++){
		scanf("%d", &b[i]);
	}
	
	vector<int> c(n+n2);
//	int cnt = 0;
//	for(int i = 0; i< n+n2; i++){
//		if(i < n){
//			c[i] = a[i];
//		}
//		else {
//			c[i] = b[cnt];
//			cnt++;
//		}
//	}
//	
//	for(int i =0; i< n+n2; i++){
//		for(int j = 0; j < n+n2; j++){
//			if(c[i] < c[j]){
//				tmp = c[i];
//				c[i] = c[j];
//				c[j] = tmp;
//			}
//		}
//	}

	//another sol
	int pos1 = 0, pos2 =0, pos3=0;
	while(pos1 <n && pos2 <n2){
		if(a[pos1] <b[pos2]){
			c[pos3++] = a[pos1++];
		}
		else{
			c[pos3++] = b[pos2++];
		}
	}
	
	while(pos1<n)c[pos3++] = a[pos1++];
	while(pos2<n2)c[pos3++] = b[pos2++];
	
	for(int i =0; i< n+n2; i++){
		printf("%d ", c[i]);
	}
	
	
	
	return 0;
}