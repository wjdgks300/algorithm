#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
	
	int n, tmp, cnt =0;
	scanf("%d", &n);
	
	for(int i =1; i<n; i++){
		tmp = i;
		while(tmp > 0){
			if(tmp %10 == 3){
				cnt++;
			}
			tmp /= 10;
		}
	}
	printf("%d", cnt);
	return 0;
 }