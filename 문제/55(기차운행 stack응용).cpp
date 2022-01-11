#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	int n, input, cnt =1, cnt2 =0;
	scanf("%d", &n);
	stack<int> s;
	vector<char> data;
	for(int i = 0; i< n; i++){
		scanf("%d", &input);
		s.push(input);
		data.push_back('P');
		while(1){
			if(s.empty() != true && cnt == s.top()){
				s.pop();
				data.push_back('O');
				cnt++;
			}else break;
		}
	}
	
	if(!s.empty()){
		printf("impossible");
	}else{
		for(int i =0; i< data.size(); i++){
			printf("%c", data[i]);
		}
	}
	
	return 0;
}