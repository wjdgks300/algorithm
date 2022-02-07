#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt;
int map[30][30];
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

struct Loc{
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q;

int main(){
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	int i, j;
	for(i = 1; i<=n;i++){
		for(j = 1; j<=n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(i = 1; i<=n;i++){
		for(j = 1; j<=n; j++){
			if(map[i][j] == 1){
				Q.push(Loc(i,j));
				map[i][j] = 0;
				while(!Q.empty()){
					Loc tmp = Q.front();
					Q.pop();
					for(int i =0; i < 8; i++){
						if(map[tmp.x + dx[i]][tmp.y + dy[i]] == 1){
							Q.push(Loc(tmp.x+dx[i], tmp.y+dy[i]));
							map[tmp.x + dx[i]][tmp.y+dy[i]] = 0;
						}
					}
				}
				cnt++;
			}
		}
	}
	
	printf("%d", cnt);
	return 0;
}