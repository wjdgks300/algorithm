#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[8][8];
int dis[8][8];
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
	
	for(int i = 0; i<7; i++){
		for(int j = 0; j < 7; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	Q.push(Loc(0,0));
	map[0][0] = 1;
	int cnt = 0, minn = 999999;
	while(!Q.empty()){
		Loc tmp = Q.front();
		Q.pop();
		for(int i =0; i < 4; i++){
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if(xx >= 0 && yy >=0 && xx <7 && yy <7 && map[xx][yy] == 0){
				Q.push(Loc(xx, yy));
				dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
				map[xx][yy] =1;
			}
		}
	}
	if(dis[6][6] == 0){
		printf("-1");
	}
	else{
		printf("%d", dis[6][6]);
	}
	
	
	return 0;
}