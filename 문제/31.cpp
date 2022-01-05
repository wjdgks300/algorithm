#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
	
	char a[11];
	
	scanf("%s", a);
	int res =0, cnt = 0, tmp =0, cnt2 =0 , pos;
	for(int i =0; a[i] != '\0'; i++){
		if(a[i] == 'C') {
			cnt++;
			res += 12;
		}
		else if(cnt == 1 && a[i] <=57 && a[i] >= 48){
			cnt2++;
		}else if(a[i] == 'H') {
			for(int j=1; j <=cnt2; j++){
				tmp += (a[j] -48) * (int)pow(10, cnt2 - j);
			}
			if(tmp != 0){
				res += res * (tmp -1);
			}
			cnt++;
			pos = i+1;
			res += 1;
			tmp = 0;
			cnt2 =0;
		}
		else {
			cnt2++;
		}
	}
	for(int i= pos; i< pos +cnt2; i++){
		tmp += (a[i] -48) * (int)pow(10, pos + cnt2 - i -1);
	}
	if(tmp != 0){
		res += (tmp -1);
	}
	printf("%d", res);
	return 0;
 }
 
 
 