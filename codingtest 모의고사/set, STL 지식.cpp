#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	
//	string a = "Time is 2020 year 03 Month";
//	string res;
//	int pos, max = INT_MIN;
//	while((pos = a.find(' '))!= string::npos){
//		string tmp = a.substr(0,pos);
//		//cout << tmp << endl;
//		int len = tmp.size();
//		if(len > max){
//			max = len;
//			res = tmp;
//		}
//		a= a.substr(pos+1);
//	}
//	if(a.size() > max) res = a;
//	cout << res;
	//cout << a;
	
	
//	for(int i = 0; i < a.size(); i++){
//		if(isupper(a[i])) cout << a[i];
//	}
//	cout << endl;
//	for(int i = 0; i < a.size(); i++){
//		if(islower(a[i])) cout << a[i];
//	}
//	cout << endl;
//	for(int i = 0; i < a.size(); i++){
//		if(isdigit(a[i])) cout << a[i];
//	}
//	cout << endl;
//	
//	cout << a.find('T') << endl;
//	cout << endl;
//	
//	a.push_back('s');
//	cout << a <<endl;
//	
//	a.pop_back();
//	cout << a <<endl;
//		
//	cout << a.substr(8) << endl;
//	
//	cout << a.substr(0,4) << endl;
//	a.clear();
//	cout << a << endl;
	
	//set
	vector<int> a = {1,3,2,3,2,3,2,3,1,2};
	set<int> s;								// 자동으로 정렬 됨 
	for(int i = 0; i < a.size(); i++){
		s.insert(a[i]);
	}
	cout << s.size() << endl;
	
//	for(auto it=s.begin(); it!=s.end(); it++){
//		cout << *it<< " ";
//	}
	for(auto x : s) cout << x << " ";
	if(s.find(3) == s.end()) cout << "false";
	else cout << "true";
	
	return 0;
}