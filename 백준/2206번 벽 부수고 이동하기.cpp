#include <bits/stdc++.h>

using namespace std;
int maps[1002][1002];
int ch[1002][1002][2];

struct loc{
    int x, y, cnt, res;
    loc(int a, int b, int c, int d){
        x = a;
        y = b;
        cnt = c;
        res = d;
    }
};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >>n >>m;

    for(int i =1; i <=n; i++){
        string s;
        cin >>s;
        for(int j = 1; j <=m; j++){
            maps[i][j] = s[j-1] - '0';
        }
    }

    queue<loc> q;
    q.push(loc(1,1,0,1));
    ch[1][1][0] = 1;
    int check =0;
    while(!q.empty()){
        loc tmp = q.front();
        int x = tmp.x;
        int y = tmp.y;
        int cnt = tmp.cnt;
        int res = tmp.res;
        q.pop();


        if(x == n && y == m){
            cout <<res;
            check = res;
            break;
        }


        for(int i = 0; i < 4; i++){
            int xx = x +dx[i];
            int yy = y +dy[i];
            if(xx < 1 ||xx >n || yy < 1 || yy > m ||ch[xx][yy][cnt] == 1) continue;
            if(maps[xx][yy] == 1){
                if(cnt <1){
                        q.push(loc(xx,yy, cnt+1, res + 1));
                        ch[xx][yy][cnt] = 1;
                }
            }
            else if(maps[xx][yy] == 0 && ch[xx][yy][cnt] == 0){
                q.push(loc(xx,yy, cnt, res +1));
                ch[xx][yy][cnt] = 1;
            }

        }
    }

    if(check == 0) cout <<-1;
//    for(int i =1; i <=n; i++){
//        for(int j = 1; j <=m; j++){
//            cout << dist[i][j];
//        }
//        cout <<endl;
//    }


    return 0;
}
