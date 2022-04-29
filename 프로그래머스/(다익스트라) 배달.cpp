#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct loc{
    int v;
    int cost;
    loc(int a, int b){
        v =a;
        cost = b;
    }
    bool operator <(const loc &b)const{
        return cost > b.cost;
    }
};


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dist(100, 2147000000);
    vector<pair<int, int> > vec[55];
    for(int i = 0; i < road.size(); i++){
        int v1 = road[i][0];
        int v2 = road[i][1];
        int costs = road[i][2];
        vec[v1].push_back(make_pair(v2, costs));
        vec[v2].push_back(make_pair(v1, costs));
    }
    priority_queue<loc> pQ;
    pQ.push(loc(1,0));
    dist[1] = 0;
    while(!pQ.empty()){
        int now = pQ.top().v;
        int cost = pQ.top().cost;
        pQ.pop();
        
        for(int i =0; i < vec[now].size(); i++){
            int next = vec[now][i].first;
            int next_cost = vec[now][i].second + cost;
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pQ.push(loc(next, next_cost));
            } 
        }
    }
    
    for(int i = 1; i<= N; i++){
        if(dist[i] <=K){
            cout << i << " " << dist[i] << endl;
            answer++;
        }
        else{
            cout << " 실패" << i << " " << dist[i] << endl;
        }
    }  
    
    return answer;
}