#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdlib>

using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
 	
	int n, min;
	scanf("%d", &n);
	vector<int> num(n);
	vector<int> a(n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
		a[i] = i+1;
	}
	for(int i=0; i<n; i++){
		for(int j= 0; j<i; j++){
			if(num[i] > num[j]) a[i] -=1;
		}
	}
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
 }