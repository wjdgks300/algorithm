#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;




int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k, tmp;
	scanf("%d %d" ,&n, &k);
	
	stack<int> s;
	char str[20] = "0123456789ABCDEF";
	while(n > 0){
		tmp = n % k;
		s.push(tmp);
		n = n / k;
	}
	
	while(!s.empty()){
		printf("%c", str[s.top()]);
		s.pop();
	}
	
	return 0;
}