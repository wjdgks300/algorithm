#include <bits/stdc++.h>
using namespace std;

struct loc{
    int a , b;
    loc(int x, int y){
        a= x;
        b = y;
    }
    bool operator<(const loc&bl)const{
        if(a == bl.a){
            return b < bl.b;
        }
        else{
            return a < bl.a;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >>N;
        vector<loc> v;
        for(int i = 0; i <N;i++){
            int a, b;
            cin >>a >> b;
            v.push_back(loc(a,b));
        }
        sort(v.begin(), v.end());
        int cnt = 0, right_min = INT_MAX;

        for(int j = 0; j < N; j++){
            if(v[j].b < right_min){
                cnt++;
                right_min = v[j].b;
            }
        }
        cout << cnt <<"\n";
    }

    return 0;
}
