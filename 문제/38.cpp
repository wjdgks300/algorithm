#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, pos = 0;
	scanf("%d", &n);
	
	vector<int> inv(n);
	vector<int> ret(n,999);
	for(int i =0; i<n;i++){
		scanf("%d", &inv[i]);
	}
	
	
	for(int i =0; i< n;i++){
		pos = inv[i];
		for(int j=0;j<=pos; j++){
			if((i+1)> ret[j]) pos++;
		}
		ret[pos] = i+1;
	}

	for(int i =0; i< n; i++){
		printf("%d ", ret[i]);
	}



//another sol
/*	  
	vector<int> inv(n);
	vector<int> ret(n);
	int cnt = 1;
	for(int i =n-1; i>=0;i--){
	
		pos = i;
		for(int j = 0; j <inv[i]; j++){
			ret[pos] = ret[pos+1];
			pos++;
		}
		ret[pos] = i+1;
	}
	for(int i =0; i< n; i++){
		printf("%d ", ret[i]);
	}
*/
	
	return 0;
}