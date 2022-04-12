#include<bits/stdc++.h>	

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    int count = 0;
    while(pq.size() > 1 && pq.top() < K){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        pq.push(num1 + (num2 * 2));
        count++;
    }
    
    if(pq.top() < K) answer = -1;
    else answer = count;
    
    
    return answer;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	
	
	return 0;
}


