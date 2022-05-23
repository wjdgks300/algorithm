#include <bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	string s;
	cin >> s;
//	int cnt = 0;
//	vector<int> v;
//	string num;
//	bool next = false;
//	for(int i = 0; i< s.size(); i++){
//		int k = s[i] - '0';
//		if(k >= 0 && k <=9){
//			num += s[i];
//			next = true;
//		}
//		else{
//			if(next == true){
//				cnt++;
//				v.push_back(stoi(num));
//				num.clear();
//				next = false;
//			}
//		}
//	}
//	if(num.size() > 0){
//		v.push_back(stoi(num));
//		num.clear();
//	}
//	sort(v.begin(), v.end());
//	int res =0;
//	for(int i = 0; i < v.size();i++){
//		res += v[i];
//		//cout << v[i];
//	}
	
	int sum = 0, res = 0;
	for(char x : s){
		if(isdigit(x)) res = res*10 + (x-48);
		else{
			sum+=res;
			res = 0;
		}
	}
	sum += res;
	cout << sum;
	
	return 0;
}