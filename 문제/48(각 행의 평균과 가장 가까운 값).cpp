#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	int sum = 0, min = 100, ret, diff;
	float avg =0;
	int num[10][10];
	for(int i =0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%d", &num[i][j]);
		}
	}
	
	for(int i =0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			sum += num[i][j];
		}
		avg = sum / 9.0;
		avg = round(avg);
		for(int k = 0; k<9; k++){
			diff = abs(avg - num[i][k]);
			if(min > diff){
				min = diff;
				ret = num[i][k];
			}else if(diff == min){
				if(num[i][k] > ret) ret = num[i][k];
			}
		}
		printf("%d %d\n", (int)avg, ret);
		sum = 0;
		min = 100;
	}
	
	
	return 0;
}