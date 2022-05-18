#include <bits/stdc++.h>
using namespace std;

struct loc{
	int x, y;
	loc(int a, int b){
		x = a;
		y = b;
	}
	bool operator <(const loc&p)const{
 		if(x == p.x) return y < p.y;
		else return x < p.x;
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int w, h, t, s;
	cin >> w >> h >> t >> s;
	vector<loc> v;
	int min_x = w, min_y = h;
	int max_x = 0, max_y = 0;
	for(int i =0; i < t; i++){
		int x, y;
		cin >> x >> y;
		v.push_back(loc(x,y));
//		if(min_x > x) min_x = x;
//		if(min_y > y) min_y = y;
//		if(max_x < x) max_x = x;
//		if(max_y < y) max_y = y;
	}
	sort(v.begin(), v.end());
	
//	for(int i = 0; i < t; i++){
//		cout << v[i].x << v[i].y << endl;
//	}

//	cout << min_x <<" "<< min_y << endl;
//	cout << max_x <<" "<< max_y;

	// time limit 
//	int res = 0;
//	for(int i = min_x; i<= max_x; i++){
//		for(int j = min_y; j <=max_y; j++){
//			int cnt;
//			if(i + s > w || j + s > h) continue;
//			for(int k = 0; k < v.size(); k++){
//				if(i+s >= v[k].x && i <= v[k].x && j+s >=v[k].y && j <= v[k].y){
//					cnt++;
//					if(res < cnt) res = cnt;
//				}
//				if(i+s < v[k].x && j +s < v[k].y) break;
//			}
//			cnt = 0;
//		}
//	}
	
	int res = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j =0; j < v.size(); j++){
			int cnt = 0;
			int xx = v[i].x;
			int yy = v[j].y;
			if(xx + s > w || yy + s > h) continue;
			for(int k = 0; k < v.size();k++){
				if(xx+s >= v[k].x && xx <= v[k].x && yy+s >=v[k].y && yy <= v[k].y){
					cnt++;
				}
			}
			res = max(res, cnt);
		}
	}
	
	cout << res;
	return 0;
}