#include <iostream>
#include <cmath>



char num[101];
int reverse(int x){
//	int res = 0, cnt =0, tmp;
//	tmp = x;
//	while(tmp >0){
//		tmp /=10;
//		cnt++;
//	}
//	while(x > 0){
//		res += (x % 10) * pow(10, cnt-1);
//		x /= 10;
//		cnt--;
//	}
	int res =0, tmp;
	while(x>0){
		tmp = x%10;
		res = res*10+tmp;
		x= x/10;
	}
	return res;
}

bool isPrime(int x){
	int cnt =0;
	for(int i=1; i<=x; i++){
		if(x % i == 0) cnt++;
	}
	if(cnt == 2) 
		return true;
	else
		return false;
}


int main(){
 	//freopen("input.txt", "rt", stdin);
	int n;
	int num[101];
	int re_num[101];
	scanf("%d", &n);
	for(int i =0; i< n; i++){
		scanf("%d", &num[i]);
		re_num[i] = reverse(num[i]);
		if(isPrime(re_num[i])) printf("%d ", re_num[i]);
	}
	
	return 0;
 }