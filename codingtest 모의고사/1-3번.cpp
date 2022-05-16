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
	
	int fir;
	cin >> fir;
	v.push_back(loc(fir, 0));
	for(int i = 1; i < n; i++){
		int h, num;
		cin >> h;
		num = cal(i,h);
		v.push_back(loc(h,num));
	}
	
	for(int i =0; i < v.size(); i++){
		cout << v[i].num << " ";
	}
	
	
	
	
//	if(v[i-1].num == 0){
//			if(v[i-1].h > h) v.push_back(loc(h, i-1));
//			else v.push_back(loc(h,0));
//		}
//		else if(v[i-1].num > 0){
//			if(v[v[i-1].num-1].h > h) v.push_back(loc(h, v[i-1].num));
//			else{
//				for(int i = )
//			}
//		}
	
	return 0;
}