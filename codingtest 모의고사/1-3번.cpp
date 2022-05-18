#include <bits/stdc++.h>
using namespace std;

struct loc{
	int h, num;
	loc(int a, int b){
		h = a;
		num = b;
	}
//	bool operator <(const loc&p)const{
// 		if(x == p.x) return y < p.y;
//		else return x < p.x;
//	}
};
vector<loc> v; 

int cal(int i, int h){
	if(v[i-1].num == 0){
		if(v[i-1].h > h) return i;
		else return 0;
	}
	else if(v[i-1].num > 0){
		if(v[v[i-1].num-1].h > h && v[i-1].h <= h) return v[i-1].num;
		else if(v[i-1].h > h) return i;
		else{
			return cal(i-1,h);
		}
	}
}


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n; 
	cin >> n;
	
	// my sol 
//	int fir;
//	cin >> fir;
//	v.push_back(loc(fir, 0));
//	for(int i = 1; i < n; i++){
//		int h, num;
//		cin >> h;
//		num = cal(i,h);
//		v.push_back(loc(h,num));
//	}
//	
//	for(int i =0; i < v.size(); i++){
//		cout << v[i].num << " ";
//	}
	
	
	
	
	//stack ***** important!! (stack의 기본이 되는 거임) 
	stack<int> s;
	vector<int> h(n+1),res(n+1, 0);
	for(int i = 1; i <=n ;i++){
		cin >> h[i];
	}
	for(int i = n; i >=1; i--){
		while(!s.empty() && h[i]>h[s.top()]){
			res[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for(int i = 1; i <=n; i++){
		cout << res[i] << " ";
	}
	return 0;
}