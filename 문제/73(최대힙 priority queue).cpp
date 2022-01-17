#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	priority_queue<int> pQ; 
	while(1){
		scanf("%d", &n);
		if(n > 0){
			pQ.push(n);
		}else if(n == 0){
			if(pQ.empty()) printf("-1\n");
			else{
				printf("%d\n", pQ.top());
				pQ.pop();
			}
		}
		else break;
	}
	
	return 0;
}