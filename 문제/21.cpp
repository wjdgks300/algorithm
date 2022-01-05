#include <iostream>

int a[11], b[11];
int main(){
 	//freopen("input.txt", "rt", stdin);
 	int score_a =0 , score_b= 0, last = -1;
	for(int i=0; i<10; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<10; i++){
		scanf("%d", &b[i]);
	}
	for(int i =0; i< 10; i++){
		if(a[i] > b[i]) {
			score_a += 3;
			last = 0;
		}
		else if(a[i] < b[i]){
			score_b += 3;
			last = 1;
		} 
		else{
			score_a +=1;
			score_b +=1;
		}
	}
	printf("%d %d\n", score_a, score_b);
	if(score_a > score_b) printf("A");
	else if(score_a < score_b) printf("B");
	else if(score_a == score_b){
		if(last == 0) printf("A");
		else if (last == 1)printf("B");
		else printf("D");
	}
	return 0;
 }