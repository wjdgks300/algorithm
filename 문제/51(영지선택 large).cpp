#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin);
	int h, w, max, tmp;
	scanf("%d %d",&h, &w);
	vector<vector<int>>num(h+1,vector<int>(w+1, 0));
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			scanf("%d", &num[i][j]);
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	 
	
	vector<vector<int>>sum(h+1,vector<int>(w+1, 0));
	
	for(int i =1; i<= h; i++){
		for(int j =1; j<= w; j++){
			sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + num[i][j];
		}
	}
	
	max = 0;
	tmp = 0;
	for(int i =a; i<= h; i++){
		for(int j =b; j<= w; j++){
			tmp = sum[i][j] - (sum[i-a][j] + sum[i][j-b]) + sum[i-a][j-b];
			if(max < tmp) max =tmp;	
		}
	}	
	
	
	
	printf("%d", max);
	
	return 0;
}