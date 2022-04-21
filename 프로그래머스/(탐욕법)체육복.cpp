#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
     for(int i = 0; i < reserve.size(); i++){
        for(int j = 0; j <lost.size(); j++){
            if(reserve[i] == lost[j]){
                cout << lost[j] << reserve[i] << endl;
                lost.erase(lost.begin() + j);
                reserve.erase(reserve.begin() + i);
                for(auto p : lost) cout << p << " ";
                cout << endl;
                answer++;
                i = -1;
                break;
            }
        }
    }
    
    for(int i = 0; i < reserve.size(); i++){
        for(int j = 0; j <lost.size(); j++){
            if(reserve[i] + 1== lost[j]|| reserve[i] - 1== lost[j]){
                cout << lost[j] << reserve[i] << endl;
                lost.erase(lost.begin() + j);
                for(auto p : lost) cout << p << " ";
                cout << endl;
                answer++;
            }
        }
    }
    return answer;
}