#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> res;
    int n = progresses.size();
    vector<int> ch(n,0);
    int cnt = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < progresses.size(); j++){
            progresses[j] += speeds[j];
            if(ch[j] != 1 && progresses[j] >= 100 && cnt == j){
                ch[j] = 1;
                res.push(i);
                cnt++;
                //cout << res.size() << endl;
            } 
        }
        if(!res.empty()){
            answer.push_back(res.size());
            while(!res.empty()){
                if(res.top() <= i){
                    res.pop();
                }
            }
        }
        
        if(cnt == n) break;
    }
    
    return answer;
}