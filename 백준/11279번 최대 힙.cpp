#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	priority_queue<int> q;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(num == 0){
			if(q.empty()) {
				cout << 0 << '\n';
			}
			
			else{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else{
			q.push(num);
		}
	}
	return 0;
}