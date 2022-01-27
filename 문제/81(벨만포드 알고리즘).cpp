#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dist[101];
struct Edge{
	int v;
	int e;
	int val;
	Edge(int a, int b, int c){
		v= a;
		e = b;
		val = c;
	}
};

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, a, b, c, s, e;
	scanf("%d %d", &n, &m);
	vector<Edge> map;
	
	for(int i =1; i <= m;i++){
		scanf("%d %d %d", &a, &b, &c);
		map.push_back(Edge(a,b,c));
	}
	for(int i = 1; i <=n; i++){
		dist[i] = 2147000000;
	}
	scanf("%d %d", &s, &e);
	dist[s] = 0;
	for(int i =0; i<n-1; i++){
		for(int j =0; j < map.size();j++){
			int v = map[j].v;
			int e = map[j].e;
			int val = map[j].val;
			if(dist[v] != 2147000000 && dist[e] > dist[v] + val){
				dist[e] = dist[v] + val;
			}
		}
	}
	
	for(int j = 0; j < map.size();j++){
		int v = map[j].v;
		int e = map[j].e;
		int val = map[j].val;
		if(dist[v] != 2147000000 && dist[e] > dist[v] + val){
			printf("%d", -1);
			exit(0);
		}
	}
	
	printf("%d", dist[e]);	
	return 0;
}