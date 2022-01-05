#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
	
	int n, tmp, f;
	scanf("%d", &n);
	int j;
	int cnt1 =0, cnt2 = 0;
	for(int i=2; i<=n; i++){
		tmp = i;
		j=2;
		while(1){
			if(tmp%j == 0){
				tmp= tmp/j;
				if(j == 2) cnt1++;
				else if(j==5) cnt2++;
			}
			else j++;
			if(tmp==1) break;
		}	
	}
	
	if(cnt1 == 0 || cnt2 ==0) printf("0");
	else if(cnt1 < cnt2) printf("%d", cnt1);
	else printf("%d", cnt2);
	
	return 0;
 }