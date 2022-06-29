#include <bits/stdc++.h>

using namespace std;
int maps[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);

    int n, m;
    cin >>n >>m;

    for(int i = 1; i <=n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 1; j <=m ;j++){
            maps[i][j] = tmp[j-1] - '0';
        }
    }


//    for(int i = 1; i <=n; i++){
//        for(int j = 1; j<=m; j++){
//            cout << maps[i][j] <<" ";
//        }
//        cout << "\n";
//    }

    int res = 0;
    if( n == 1 && m == 1){
        if(maps[n][m] == 1){
                cout <<1;
                return 0;
        }
        else {
                cout <<0;
                return 0;
        }
    }

    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=m; j++){
            if(maps[i][j] != 0){
                maps[i][j] = min(maps[i-1][j-1], min(maps[i-1][j], maps[i][j-1])) +1;
                res = max(res, maps[i][j]);
            }
        }
    }


    cout <<res * res <<"\n";

    return 0;
}
