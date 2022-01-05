#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> num(n);
	for(int i =0; i< n; i++){
		scanf("%d", &num[i]);
	}
	int tmp;
	for(int i =0; i< n; i++){
		for(int j =i+1; j<n; j++){
			if(num[i] < num[j]){
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	
	int count = 1;
	for(int i = 1; i<= n; i++){
		if(num[i -1] != num[i]) count++;
		if(count == 3){
			printf("%d", num[i]);
			break;
		}
	}
	
	return 0;
}
