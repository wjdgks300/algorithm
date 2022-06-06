#include <bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	int n;
	stack<int> s;
	cin >> n;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		//cout << str;
		if (str == "push"){
			int num;
			cin >> num;
			s.push(num);
		}
		else if(str == "pop"){
			if(s.size() == 0){
				cout << -1 << endl;
			}else{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if(str =="top"){
			if(s.size() == 0){
				cout << -1 << endl;
			}else
				cout << s.top() << endl;
		}
		else if(str == "size"){
			cout << s.size() << endl;
		}
		else if(str == "empty"){
			if(s.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
		
	return 0;
}