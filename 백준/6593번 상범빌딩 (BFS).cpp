#include<bits/stdc++.h>	
using namespace std;

char maps[31][31][31];
int ch[31][31][31];
int L, R, C;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int end_z = -1, end_y = -1, end_x = -1;
int sta_z = -1, sta_y = -1, sta_x = -1;


struct loc{
	int z, y, x, val;
	loc(int a, int b, int c, int d){
		z =a;
		y =b;
		x =c;
		val = d;
	}
};



int bfs(){
	int cnt = 0;
	queue<loc> Q;
	Q.push(loc(sta_z, sta_y, sta_x, 0));
	ch[sta_z][sta_y][sta_x] = 1;
	while(!Q.empty()){
		loc tmp = Q.front();
		Q.pop();
		//cout << tmp.z << " " << tmp.y << " " << tmp.x << " "<< maps[tmp.z][tmp.y][tmp.z] << endl;
		
		if(tmp.z == end_z && tmp.y == end_y && tmp.x == end_x){
			
			return tmp.val;
		}
		for(int i =0; i < 6; i++){
			int zz = tmp.z + dz[i];
			int yy = tmp.y + dy[i];
			int xx = tmp.x + dx[i];
			if(zz < 0 || zz >= L || yy < 0 || yy >= R || xx <0 || xx >=C) continue;
			if(maps[zz][yy][xx] == '#') continue;
			if(maps[zz][yy][xx] != '#' && ch[zz][yy][xx] != 1){
				ch[zz][yy][xx] = 1;
				Q.push(loc(zz,yy,xx, tmp.val + 1));
			}
		}	
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	
	while(1){
		cin >> L >> R >> C;
		
		memset(maps, false, sizeof(maps));
		memset(ch, false, sizeof(ch));
		if(L==0 && R == 0 && C== 0) break;
		for(int i = 0;i < L; i++){
			for(int j = 0; j<R; j++){
				for(int k = 0; k < C; k++){
					cin >> maps[i][j][k];
					if(maps[i][j][k] == 'S') {
						sta_z = i;
						sta_y = j;
						sta_x = k;
						ch[i][j][k] = 1;	
					}
					else if(maps[i][j][k] == 'E'){
						end_z = i;
						end_y = j;
						end_x = k;
					}
				}
			}
		}
		int res = bfs();
		if(res == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in "<<res<< " minute(s)."<<endl;
	}
	
	return 0;
}


//memo mpas[i][j][k]를 sta나 end에 받아서 넘겨줘야 한다. 