#include<bits/stdc++.h>	
using namespace std;

int maps[10][10];
int row[10][10];
int col[10][10];
int square[10][10];

int square_location(int x, int y){
	return (x/3) * 3 + (y/3);
}

void DFS(int num){
	if(num == 81){
		for(int i =0; i < 9; i++){
			for(int j =0; j < 9; j++){
				cout << maps[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	
	int x = num / 9;
	int y = num % 9;
	if(maps[x][y] !=0){
		DFS(num+1);	
	}
	else{
		for(int i =1; i<= 9; i++){
			if(row[x][i] == 0 && col[y][i] == 0 && square[square_location(x,y)][i] == 0){
				row[x][i] = 1;
				col[y][i] = 1;
				square[square_location(x,y)][i] = 1;
				maps[x][y] = i;
				
				DFS(num + 1);
				
				row[x][i] = 0;
				col[y][i] = 0;
				square[square_location(x,y)][i] = 0;
				maps[x][y] = 0; 
				
			}
		}
		
	}
	return;	
}



int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	for(int i =0; i < 9; i++){
		for(int j = 0; j <9; j++){
			cin >> maps[i][j];
			
			if(maps[i][j] != 0){
				row[i][maps[i][j]] = 1;
				col[j][maps[i][j]] = 1;
				int tmp = (i/3) * 3 + (j/3);
				square[tmp][maps[i][j]] = 1;
			}
		}
	}
	

		
	
	
	DFS(0);
	
	
	return 0;
}