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
	for(int i =0; i<n; i++){
		for(int j = 0; j < n -i -1; j++){
			if(num[j+1] < 0 && num[j] > 0){
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	}
	
	
	for(int i =0;i <n; i++){
		printf("%d ", num[i]);
	}
	
	
	return 0;
}