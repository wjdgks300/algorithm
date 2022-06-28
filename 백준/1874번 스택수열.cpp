#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	stack<int> s;
	vector<char> v;
	int cnt = 1;
	int cnt2 = 0;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		for(int j =cnt;j <= n; j++){
			if(s.empty()){
				s.push(j);
				cnt++;
				v.push_back('+');
				//cout << '+' << endl;	
			} 
			else if(s.top() != num){
				s.push(j);
				cnt++;
				v.push_back('+');
				//cout << '+' << endl;
			}
			else{
				v.push_back('-');
				//cout << '-' << endl;
				s.pop();
				break;
			}
		}
		if(cnt == n+1){
			if(s.top() == num){
				v.push_back('-');
				//cout << '-' << endl;
				s.pop();
			}
		}
	}
	
	if(s.empty()) for(auto a: v) cout << a << "\n"; 	//endl 되도록 쓰지말고 "\n" 쓰자!
	else cout << "NO";
	
	return 0;
}