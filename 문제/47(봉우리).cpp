#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
	freopen("input.txt", "rt", stdin);
	
	int n, cnt =0, k, flag;
	scanf("%d", &n);
	vector<vector<int>> a(n+2, vector<int>(n+2, 0));
	
	for(int i =1; i<=n; i++){
		for(int j =1; j<=n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i =1; i<=n; i++){
		for(int j =1; j<=n; j++){
			flag = 0;
			for(k= 0; k< 4; k++){
				if(a[i][j] <= a[i+dx[k]][j+dy[k]]){
					flag =1;
					break;
				}
			}
			if(flag == 0) cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}