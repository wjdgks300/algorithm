#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;
int cnt =0, n; 
vector<vector<int>> map(10, vector<int>(10,1));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y){
	int xx, yy;
	if(x== 7 && y == 7){
		cnt++;
	}else{
		for(int i =0; i<4; i++){
			xx = x + dx[i];
			yy = y + dy[i];
			if(map[xx][yy] ==0){
				map[xx][yy] =1;
				DFS(xx, yy);
				map[xx][yy] =0;
			} 
		}
	}
}

int main(){
	//freopen("input.txt", "rt", stdin);
	int m, i, j, a, b;
	for(int i =1; i<= 7; i++){
		for(int j =1; j<= 7; j++){
			scanf("%d", &map[i][j]);
		}
	}
	map[1][1] =1;
	DFS(1,1);
	
	printf("%d", cnt);
	
	return 0;
}