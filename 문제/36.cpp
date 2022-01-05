#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<int> num(n);
	for(int i =0; i< n; i++){
		scanf("%d", &num[i]);
	}
	int j;
	for(int i =1; i<n; i++){
		tmp = num[i];
		for(j = i -1; j >=0; j--){
			if(num[j] > tmp){
				num[j+1] = num[j];
			}
			else break;
		}
		num[j+1] = tmp;
	}
	
	
	for(int i =0;i <n; i++){
		printf("%d ", num[i]);
	}
	
	
	return 0;
}