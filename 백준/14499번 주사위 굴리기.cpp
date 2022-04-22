#include <bits/stdc++.h>
using namespace std;
// r -> y   ,  c -> x
int n, m, x, y, k; 
int maps[21][21];
vector<int> dice(7,0);

void diceMove(int input){
	vector<int> tmp(7,0);
	
	if(input == 1){
		tmp[1] = dice[4];
		tmp[2] = dice[2];
		tmp[3] = dice[1];
		tmp[4] = dice[6];
		tmp[5] = dice[5];
		tmp[6] = dice[3];
	}
	else if(input == 2){
		tmp[1] = dice[3];
		tmp[2] = dice[2];
		tmp[3] = dice[6];
		tmp[4] = dice[1];
		tmp[5] = dice[5];
		tmp[6] = dice[4];
	}
	else if(input == 3){
		tmp[1] = dice[5];
		tmp[2] = dice[1];
		tmp[3] = dice[3];
		tmp[4] = dice[4];
		tmp[5] = dice[6];
		tmp[6] = dice[2];
	}
	else{
		tmp[1] = dice[2];
		tmp[2] = dice[6];
		tmp[3] = dice[3];
		tmp[4] = dice[4];
		tmp[5] = dice[1];
		tmp[6] = dice[5];
	}
	
	copy(tmp.begin(), tmp.end(), dice.begin());
}


int move(int num){
	if(num == 1){
		if(y+1 < n){
			diceMove(1);
			y = y + 1;
			if(maps[x][y] == 0){
				maps[x][y] = dice[6];
			}else{
				dice[6] = maps[x][y];
				maps[x][y] = 0;
			}
		}
		else return -1;
	}
	else if(num == 2){
		if(y-1 >= 0){
			diceMove(2);
			y = y - 1;
			if(maps[x][y] == 0){
				maps[x][y] = dice[6];
			}else{
				dice[6] = maps[x][y];
				maps[x][y] = 0;
			}
		}
		else return -1;
	}
	else if(num == 3){
		if(x-1 >= 0){
			diceMove(3);
			x = x - 1;
			if(maps[x][y] == 0){
				maps[x][y] = dice[6];
			}else{
				dice[6] = maps[x][y];
				maps[x][y] = 0;
			}
		}
		else return -1;
	}
	else{
		if(x+1 < n){
			diceMove(4);
			x = x + 1;
			if(maps[x][y] == 0){
				maps[x][y] = dice[6];
			}else{
				dice[6] = maps[x][y];
				maps[x][y] = 0;
			}
		}
		else return -1;
	}
	return dice[1];
}


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt" ,stdin);
	
	int input;
	
	cin >> n >> m >> x >> y >> k;
	
	for(int i =0; i < n; i++){
		for(int j = 0; j< m; j++){
			cin >> maps[i][j];
		}
	}
	int res;
	for(int i = 0; i< k; i++){
		cin >> input;
		res = move(input);
		if(res != -1)cout << res << endl;	
	}
	
	
	
	return 0;
}