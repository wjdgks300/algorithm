#include <iostream>
#include <vector>

using namespace std;

int main() {
	int s, n, tmp, hit = 0;
	scanf("%d %d", &s, &n);
	vector<int> num(s);
	scanf("%d", &num[0]);
	
	for(int i= 1; i< n; i++){
		scanf("%d", &tmp);
		
		for(int j = 0; j< s; j++){
			if(num[j] == tmp) hit =j;
		}
		
		if(hit == 0){
			for(int j = s-1; j>=1; j--){
				num[j] = num[j -1];
			}
			num[0] = tmp;
		}
		else{
			for(int j = hit; j >=1; j--){
				num[j] = num[j-1];
			}
			num[0] = tmp;
			hit = 0;
		}
		
	}
	
	for(int i =0; i<s; i++){
		printf("%d ", num[i]);
	}
	
	
	
	return 0;
}