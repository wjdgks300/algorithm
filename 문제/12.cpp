#include <iostream>
#include <cmath>


 int main(){
 	//freopen("input.txt", "rt", stdin);
 	int n, tmp , res =0;
 	
 	int sum =0;
	scanf("%d", &n);
 	for(int i = 0; i<=10; i++){
 		if(n >= 10 * (int)pow(10,i)){
 			res += (i+1) * (9 * (int)pow(10,i));
 			sum += 	9 * ((int)pow(10,i));
		 }
		 else{
		 	res += (n - sum) * (i+1);
		 	break;
		 }
	 }
	 printf("%d", res);
	

//	int n, sum = 0, c= 1, d= 9, res =0;
//	scanf("%d", &n);
//	while(sum+d<n){
//		res= res+(c*d);
//		sum = sum +d;
//		c++;
//		d= d*10;
//	}
//	res= res+((n-sum) *c);
//	printf("%d\n", res);
//	return 0;
 }