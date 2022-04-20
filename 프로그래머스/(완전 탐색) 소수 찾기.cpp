#include<bits/stdc++.h>	

using namespace std;
int cnt, n;
int ch[100000];
vector<int> vec;

bool isPrime(int num){
    int count = 0;
    if(num < 2) return false;
    for(int i = 2; i <=num; i++){
        if(num % i == 0){
            count++;
        }
        if(count >2) return false;
    }
    if(count < 2) return true;
}


void dfs(int d, int k){
    if(d == n) {
        int res = 0;
        for(int i = 0; i <= n; i++){
            if(ch[i] == i){
                res = res * 10 + vec[i];
                if(isPrime(res)) {
                	cnt++;
					cout << res << endl;	
				}
            }
        }
        return;
    }
    else{
        for(int i = k; i< n; i++){
            if(ch[i] == 0){
                ch[i] = d;
                dfs(d+1, i);
                ch[i] = 0;
            }
        }
    }
}
    

int solution(string numbers) {
    int answer = 0;
    
    for(int i =0; i < numbers.size(); i++){
        vec.push_back(numbers[i] - '0');
    }
    //for(auto i: vec) cout << i << " ";
    
    n = numbers.size();
    
    
    for(int i =0; i < n; i++){
        dfs(0, i);
    }
    
    answer = cnt;
    
    return answer;
}


int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	string number;
	cin >> number;
	
	cout << solution(number);
	return 0;
}