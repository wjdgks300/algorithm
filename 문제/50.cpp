#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin);
	int h, w, sum = 0, max;
	scanf("%d %d",&h, &w);
	vector<vector<int>>num(h,vector<int>(w, 0));
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			scanf("%d", &num[i][j]);
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	max = 0; 
	int pos1, pos2;
	
	for(int i = 0; i<=h -a; i++){
		for(int j =0; j <=w- b; j++){
			for(int k = i; k < i+a; k++){
				for(int l = j; l < j+ b; l++){
					sum += num[k][l];
				}
				
			}
			if(sum > max) max = sum;
			sum = 0;
		}
	}	
	
	printf("%d", max);
	
	return 0;
}