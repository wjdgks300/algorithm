#include <bits/stdc++.h>	
using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //cout<<commands.size();
    for(int i =0; i < commands.size(); i++){
        int k = commands[i][1] - commands[i][0] + 1;
        vector<int> tmp(k,0);
        // cout << commands[i][0] << endl;
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], tmp.begin());
        sort(tmp.begin(), tmp.end());
        //for(auto i : tmp) cout << i;
        //cout << endl;
        answer.push_back(tmp[commands[i][2] -1]);
    }
    
    return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	
	
	return 0;
}


