#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
	
	int n, idx, tmp;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i =0; i<n;i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n;i++){
		idx = i;
		for(int j= i+1; j< n; j++){
			if(a[j] < a[idx]) idx = j;
		}
		tmp = a.at(i);
		a[i] = a[idx];
		a[idx] = tmp;
	}
	for(int i= 0; i< n; i++){
		printf("%d ", a[i]);
	}
	return 0;
 }
 
 
 