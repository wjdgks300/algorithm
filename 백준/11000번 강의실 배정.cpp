#include <bits/stdc++.h>
using namespace std;

struct loc{
	int min, max;
	loc(int x, int y){
		min = x;
		max = y;
	}
	bool operator<(const loc & b)const{
		if(min == b.min) return max < b.max;
		else return min < b.min;
	}
};

struct loc2{
	int min, max;
	loc2(int x, int y){
		min = x;
		max = y;
	}
	bool operator<(const loc2 & b)const{
		if(max == b.max) return min > b.min;
		else return max > b.max;
	}
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<loc> v;
    
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	v.push_back(loc(x,y));
	}
    
    sort(v.begin(), v.end());
//	for(int i = 0; i < n; i++){
//    	cout << v[i].min << v[i].max << "\n";
//	}
	
	priority_queue<loc2> pq;
	pq.push(loc2(v[0].min, v[0].max));
	
	for(int i = 1; i < n; i++){
		if(pq.top().max <= v[i].min){
			pq.pop();
			pq.push(loc2(v[i].min, v[i].max));
		}
		else pq.push(loc2(v[i].min, v[i].max));
	}
	cout << pq.size();
	
	
	
	    
	return 0;	
}
