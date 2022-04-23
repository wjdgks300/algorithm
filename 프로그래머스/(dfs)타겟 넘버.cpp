#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int k;
int n;
int counts;
int ch[21][2];
void dfs(int d,int sum, vector<int> num){
    if(d == n){
        //cout << sum << endl;
        if(sum == k){
            counts++;
        }
        return;
    }
    for(int i =0; i < 2; i++){
        if(i == 0){
            
            dfs(d+1,sum - num[d], num);
            
        }else if(i == 1){

            dfs(d+1,sum + num[d], num);

        }
    }
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    k = target;
    n = numbers.size();
    dfs(0, 0, numbers);
    answer = counts;
    return answer;
}