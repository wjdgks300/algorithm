#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[1000][1000];
int day[1000][1000];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Loc{
	int x;
	int y;
	Loc(int a, int b){
		x = a;
		y = b;
	}
};

queue<Loc> Q;

int main(){
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &m, &n);
	
	for(int i =0; i< n; i++){
		for(int j = 0; j<m; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				Q.push(Loc(i,j));
			}
		}
	}
			
	while(!Q.empty()){
		Loc tmp = Q.front();
		Q.pop();
		for(int k = 0; k<4; k++){
			int xx = tmp.x + dx[k];
			int yy = tmp.y + dy[k];
			if(xx >=0 && xx <n && yy >=0 && yy < m && map[xx][yy] ==0){
				Q.push(Loc(xx,yy));
				map[xx][yy] =1;
				day[xx][yy] = day[tmp.x][tmp.y] + 1;
			}
		}
	}
	
	int maxx = 0;
	
//	for(int i =0; i< n; i++){
//		for(int j = 0; j<m; j++){
//			printf("%d ", day[i][j]);
//		}
//		puts("");
//	}
	
	bool full = true;
	
	for(int i = 0; i< n; i++){
		for(int j = 0; j< m; j++){
			if(map[i][j] == 0) full =false;
		}
	}
	
	if(full){
		for(int i =0; i< n; i++){
			for(int j = 0; j<m; j++){
				if(maxx< day[i][j]) maxx = day[i][j];
			}
		}
		printf("%d", maxx);
	}
	else{
		printf("-1");
	}
	
	
	return 0;
}