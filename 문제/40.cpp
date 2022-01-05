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
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	
	int pos1 = 0, pos2 =0, pos3=0;
	while(pos1 <n && pos2 <n2){
		if(a[pos1] == b[pos2]) {
			c[pos3++] =a[pos1];
			pos1++;
			pos2++;	
		}
		else if(a[pos1] <b[pos2]){
			pos1++;
		}
		else{
			pos2++;
		}
	}
	
	for(int i =0; i< pos3; i++){
		printf("%d ", c[i]);
	}
	
	
	
	return 0;
}