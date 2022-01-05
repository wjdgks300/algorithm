#include <iostream>
#include <cmath>
#include <algorithm>



int a[60], b[60];
int main(){
 	//freopen("input.txt", "rt", stdin);
	
	char n1[100], n2[100];
	scanf("%s %s", &n1, &n2);
	int tmp;
	for(int i =0; n1[i] !='\0'; i++){
		if(65<= n1[i] && n1[i] <= 90){
			tmp = n1[i] -64;
			a[tmp] += 1;
		}
		else if(97<= n1[i] && n1[i] <= 122){
			tmp = n1[i] - 70;
			a[tmp] += 1;
		}
		
		if(65<= n2[i] && n2[i] <= 90){
			tmp = n2[i] -64;
			b[tmp] += 1;
		}
		else if(97<= n2[i] && n2[i] <= 122){
			tmp = n2[i] - 70;
			b[tmp] += 1;
		}
	}
	
//	int flag = 0;
//	for(int i= 0; i < 60; i++){
//		if(a[i] != b[i]){
//			flag = 1;
//			break;
//		}
//	}
//	
//	if(flag == 0) printf("%s", "YES");
//	else printf("%s", "NO");
	for(int i =1; i <=52; i++){
		if(a[i] !=b[i]){
			printf("NO");
			exit(0);
		}	
	}
	printf("YES");
	return 0;
 }