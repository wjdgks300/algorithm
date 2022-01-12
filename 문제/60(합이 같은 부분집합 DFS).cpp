#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int num[11];
int ch[11];
int n;
int sum1 =0, sum2= 0;
void DFS(int L){
	if(L == n+1){
		for(int i =0; i<n;i++){
			if(ch[i] == 1) sum1 += num[i];
			else sum2 += num[i];
		}
		if(sum1 == sum2){
			printf("YES");
			exit(0);
		}
		sum1= 0;
		sum2= 0;
	}
	else{
		ch[L] = 1;
		DFS(L+1);
		ch[L] = 0;
		DFS(L+1);
	}
}


int main(){
	//freopen("input.txt", "rt", stdin);	
	scanf("%d", &n);
	for(int i=0; i<n ;i++){
		scanf("%d", &num[i]);
	}
	DFS(1);	
	printf("NO");
	
	return 0;
}


/* another sol
int n, a[11], total = 0;
bool DFS(int L, int sum){
	if(sum>(total/2)) return;
	if(flag == true) return;
	if(L==n+1){
		if(sum==(total-sum)){
			flag =true;
		}
	}else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
	}
}

int main(){
	int i;
	scanf("%d", &n);
	for(i =1; i<n;i++){
		scanf("%d", &a[i]);
		total+= a[i];
	}
	DFS(1,0);
	if(flag) printf("YES");
	else printf("NO");
}

*/

