#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin);
	int n, max, sum = 0;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> b(n);
	
	for(int i =0; i< n; i++){
		scanf("%d", &a[i]);
	}
	for(int i =0; i< n; i++){
		scanf("%d", &b[i]);
	}
	
	for(int i =0; i< n; i++){
		max = a[i];
		for(int j = 0; j< n;j++){
			if(max > b[j]) sum += b[j];
			else sum += max;
		}
	}
	
	printf("%d", sum);
	
	return 0;
}