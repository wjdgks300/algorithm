#include <bits/stdc++.h>
using namespace std;

struct loc{
    string t_id;
    string f_id;
    loc(string a, string b){
        t_id = a;
        f_id = b;
    }
};


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<loc> vec;
    
    unordered_map<string, int> idx_map;
    unordered_map<string, set<string>> report_map;
    
    for(int i = 0; i < id_list.size(); i++) idx_map[id_list[i]] = i;
    
    
    for(int i =0;i < report.size();i++){
        stringstream ss(report[i]);
        string a, b; 
        ss >> a;
        ss >> b;
        report_map[b].insert(a);
        ss.clear();
    }
        
    
    for(auto it: report_map){
        if(it.second.size() >= k){
            for(auto set_it : it.second){
                //cout << set_it << endl;
                int idx = idx_map[set_it];
                answer[idx]++;
            }
        }
    }
    
    
    return answer;
}
