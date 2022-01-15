#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[10001], dis[10001];

int main() {
	//freopen("input.txt", "rt", stdin);
	int s, e, x, cnt = 0;
	int move[3] = {1, -1, 5};
	scanf("%d %d", &s, &e);
	queue<int> Q;
	
	ch[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		x = Q.front();
		Q.pop();
		
		for(int i =0; i < 3;i++){
			if(x == e){
				break;
			}
			if(ch[x+move[i]] == 0){
				ch[x+move[i]] =1;
				Q.push(x+move[i]);
				dis[x+move[i]] = dis[x] +1; 
			}
		}
	}
	
	printf("%d", dis[e]);
	return 0;
}