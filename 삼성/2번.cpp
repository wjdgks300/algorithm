#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m,r,k;
char maps[102][102];
int ch[102][102];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct loc{
	int x,y,res;
	loc(int a, int b,int d){
		x =a;
		y = b;
		res = d;
	}
};

struct xcal{
	int cnt;
};


void bfs(int a, int b){
	queue<loc> q;
    q.push(loc(a,b,0));
    int res = 99999999;
    xcal xca;
    while(!q.empty()){
    	loc tmp = q.front();
    	q.pop();
		int x = tmp.x;
		int y = tmp.y;
		
    	if(maps[x][y] == 'A' ||  maps[x][y] == 'B' || maps[x][y] == 'C'){
    		xca.cnt += 1;
    		maps[x][y] = '.';
    		for(int i =1; i <= n; i++){
    			for(int j =1; j<= m; j++){
    				ch[i][j] = 0;
				}
			}
    		while(!q.empty()) q.pop();
    		//cout << x << y << tmp.res << endl;
		}
    	if(maps[x][y] == 'S' && xca.cnt == 3){
    		cout << tmp.res << endl;
    		break;
		}
    	
		if(res < tmp.res) continue;
    	for(int i = 0; i <4; i++){
    		int xx = tmp.x + dx[i];
    		int yy = tmp.y + dy[i];
    		if(xx < 1 || xx > n || yy <1 || yy >m || ch[xx][yy] == 1) continue;
    		if(maps[xx][yy] == 'X' && xca.cnt !=3) continue;
    		ch[xx][yy] = 1;
    		q.push(loc(xx,yy,tmp.res + 1));
		}
	}
	return;
}


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	for(int i = 0; i < t;i++){
        cin >> n >> m >> r >> k;
        for(int i = 1; i <=n; i++){
            for(int j = 1; j<= m; j++){
                cin >> maps[i][j];
        	}	
        }
        cout << "#" << i+1<< " "; 
        bfs(r, k);
        memset(ch, 0, sizeof(ch));
	}
		
	
	return 0;
}