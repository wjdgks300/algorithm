#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


// 0: up   1:right  2:down  3:left
int n, k,direction = 1; 
int maps[101][101];

int cur_x = 1, cur_y = 1;
struct loc{
	int cnt;
	char dir;
	loc(int a, char b){
		cnt = a;
		dir = b;
	}
};

deque<pair<int , int> > tail;
vector<loc> v;
int ans;
void dfs(int cnt){
	
	for(int i = 0; i < v.size(); i++){
		if(cnt == v[i].cnt){
			if(v[i].dir == 'D') direction = (direction + 1) % 4;
			else {
				if(direction == 0) direction = 3;
				else direction = (direction -1) % 4;
			}
		}
	}
//	if(y > n || y <= 0 || x > n || x <=0){
//		return;
//	}
	
	if(direction == 0){
		if(cur_y -1 <= 0 || maps[cur_y -1][cur_x] == 1){
			ans = cnt+1;
			return;
		} 
		else{
			if(maps[cur_y -1][cur_x] != 2){
				maps[cur_y -1][cur_x] = 1;
				maps[tail.back().first][tail.back().second] = 0;
				tail.pop_back();
				tail.push_front(make_pair(cur_y -1, cur_x ));
			}
			else{
				maps[cur_y -1][cur_x] = 1;
				tail.push_front(make_pair(cur_y -1, cur_x));
			}
			cur_y -= 1;
			dfs(cnt+1);
		}
	}else if(direction == 1){
		if(cur_x + 1 > n || maps[cur_y][cur_x+1] == 1) {
			ans = cnt+1;
			return;
		} 
		else{
			if(maps[cur_y][cur_x+1] != 2){
				maps[cur_y][cur_x+1] = 1;
				maps[tail.back().first][tail.back().second] = 0;
				tail.pop_back();
				tail.push_front(make_pair(cur_y, cur_x + 1));
			}else{
				maps[cur_y][cur_x+1] = 1;
				tail.push_front(make_pair(cur_y, cur_x+1));
			}
			cur_x += 1;
			dfs(cnt+1);
		}
	}else if(direction == 2){
		if(cur_y + 1 > n || maps[cur_y + 1][cur_x] == 1){
			ans = cnt+1;
			return;
		} 
		else{
			if(maps[cur_y +1][cur_x] != 2){
				maps[cur_y + 1][cur_x] = 1;
				maps[tail.back().first][tail.back().second] = 0;
				tail.pop_back();
				tail.push_front(make_pair(cur_y + 1, cur_x));
			}else{
				maps[cur_y +1][cur_x] = 1;
				tail.push_front(make_pair(cur_y +1, cur_x));
			}
			cur_y += 1;
			dfs(cnt+1);
		}
	}else if(direction == 3){
		if(cur_x - 1<= 0 || maps[cur_y][cur_x -1] == 1) {
			ans = cnt+1;
			return;
		} 
		else{
			if(maps[cur_y][cur_x-1] != 2){
				maps[cur_y][cur_x-1] = 1;
				maps[tail.back().first][tail.back().second] = 0;
				tail.pop_back();
				tail.push_front(make_pair(cur_y, cur_x - 1));
			}else{
				maps[cur_y][cur_x-1] = 1;
				tail.push_front(make_pair(cur_y, cur_x -1));
			}
			cur_x -= 1;
			dfs(cnt+1);
		}
	}
}



int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	
	for(int i = 0; i < k; i++){
		int y, x;
		cin >> y >> x;
		maps[y][x] = 2;
	}
	
	int change;
	cin >> change;
	
	for(int i = 0; i < change; i++){
		int a;
		char b;
		cin >> a >> b;
		v.push_back(loc(a,b));
	}
	tail.push_front(make_pair(1,1));
	
	dfs(0);	
	cout << ans;
	
	return 0;
}