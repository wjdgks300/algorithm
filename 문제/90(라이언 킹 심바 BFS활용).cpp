#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//simba 2 , move 1, 
int n;
int map[26][26];
int ch[26][26];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Loc{
	int x;
	int y;
	int dis;
	Loc(int a, int b, int c){
		x = a;
		y = b;
		dis = c;
	}
	bool operator <(const Loc &bb)const{
		if(dis == bb.dis){
			if(x==bb.x) return y > bb.y;
			else return x > bb.x;
		}
		else return dis > bb.dis;
	}
};

struct Lion{
	int x;
	int y;
	int lev, exp;
	void level_up(){
		lev += 1;
		exp = 0;
	}
};


int main(){
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	priority_queue<Loc> Q;
	Lion simba;
	int res = 0;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 9){
				simba.x = i;
				simba.y = j;
				map[i][j] = 0;
			}
		}
	}

	
	Q.push(Loc(simba.x,simba.y,0));
	simba.lev = 2;
	simba.exp = 0;
	
	while(!Q.empty()){
		Loc tmp = Q.top();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;
		if(map[x][y] !=0 && map[x][y] <simba.lev){
			simba.x= x;
			simba.y = y;
			simba.exp +=1;
			if(simba.exp == simba.lev) simba.level_up();
			map[x][y] = 0;
			for(int i = 0; i <n; i++){
				for(int j = 0; j<n; j++){
					ch[i][j] =0;
				}
			}
			while(!Q.empty()) Q.pop();
			res=tmp.dis;
		}
		
		for(int i =0; i <4; i++){
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if(xx <0 || xx >=n || yy < 0 || yy >=n || map[xx][yy] > simba.lev || ch[xx][yy] > 0) continue;
			Q.push(Loc(xx, yy, z+1));
			ch[xx][yy] = 1;
		}
	}
	
	printf("%d", res);
		
	return 0;
}