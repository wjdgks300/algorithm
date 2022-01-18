#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int unf[1001];

int Find(int v){
	if(v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a!=b) unf[a] = b;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m ,a , b;
	cin >> n >> m;
	for(int i =1; i <=n; i++){
		unf[i] = i;
	}
	for(int i =1; i<=m; i++){
		cin >>a >>b;
		Union(a,b);
	}
	int c, d;
	cin >> c >> d;
	if(Find(c) != Find(d)) printf("NO");
	else printf("YES");
	
	
 	return 0;
}