#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
 	//freopen("input.txt", "rt", stdin);
 	
	int n, tmp, f;
	scanf("%d", &n);
	vector<int> ch(n+1);
	int j;
	for(int i=2; i<=n; i++){
		tmp = i;
		j=2;
		while(1){
			if(tmp%j == 0){
				tmp= tmp/j;
				ch[j]++;
			}
			else j++;
			if(tmp==1) break;
		}	
	}
	printf("%d! = ", n);
	for(int i =2; i<=n; i++){
		if(ch[i] !=0) printf("%d ", ch[i]);
	}
	
	return 0;
 }