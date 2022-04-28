#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ch[100];
int cnt;
int res[4000];
bool check(int n){
    int count = 0;
    if(n < 2) return false;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            count++;
        }
        if(count >=2) return false;
    }
    if(count < 2) return true;
}
vector<int> dep(3,0);

void dfs(int d, vector<int> nums, int s,int sum){
    if(d == 3){
        if(check(sum)){
            cout << "sum = " << sum << endl;
            cnt++;
        }
        return;
    }
    for(int i = s; i < nums.size(); i++){
        dfs(d+1, nums, i+1, sum+nums[i]);
    }   
    return;
}

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    dfs(0,nums, 0, 0);
    cout << cnt << endl;
    answer = cnt;

    return answer;
}