#include<bits/stdc++.h>	
using namespace std;

int n, m, h;
int ladder[31][11];
int dd[2] = {1,-1};

void DFS(int start, int num, int y, int x){
	if(num == m){
		if(start == x){
			cout << start << " => " << y;
		}
		
	}
	else{
		for(int i =0; i < 2; i++){
			int xx = x + dd[i];
			if(ladder[y][x] == 1 && ladder[y][xx] ==1){
				DFS(start, num+1, y+1, xx);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n >> m >> h;
	int x, y;
	for(int i =0; i< m; i++){
		cin >> y >> x;
		ladder[y][x] = 1;
		ladder[y][x+1] = 1;
	}
	
	for(int i = 0; i < 4)
	DFS(1,0,1,1);
	
	return 0;
}