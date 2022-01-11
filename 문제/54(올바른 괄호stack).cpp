#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	char c;
	stack<int> s;
	char str[31]; 
	
	scanf("%s", str);
	
	for(int i =0; str[i] != '\0'; i++){
		if(str[i] == '('){
			s.push(1);
		}
		else{
			if(s.empty()){
				printf("NO");
				exit(0);
			}
			s.pop();
		}
	}
	
	if(s.empty()){
		printf("YES");
	}
	else printf("NO");	
	return 0;
}