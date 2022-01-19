#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int unf[300];
int v, sum;

struct Loc{
	int x, y, z;
	Loc(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}
	bool operator < (Loc &b){
		if(z != b.z) return z < b.z;
	}
};

int Find(int v){
	if(v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a != b) unf[a] = b;
}



int main() {
	//freopen("input.txt", "rt", stdin);
	int e, a, b, c;
	scanf("%d %d", &v, &e);
	vector<Loc> XY;
	for(int i =1; i<=v; i++){
		unf[i] = i;
	}
	for(int i =0; i < e; i++){
		scanf("%d %d %d", &a, &b, &c);
		XY.push_back(Loc(a,b,c));
	}
	
	sort(XY.begin(), XY.end());
	
	for(auto pos : XY){
		//printf("%d %d %d \n", pos.x, pos.y, pos.z);
		int fa = Find(pos.x);
		int fb = Find(pos.y);
		if(fa != fb){
			sum += pos.z;
			Union(pos.x, pos.y);
		}
	}
	printf("%d", sum);
	return 0;
}