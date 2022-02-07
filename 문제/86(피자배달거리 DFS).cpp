#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ch[20];
int total_mins = 9999;

vector<pair<int,int> >house;
vector<pair<int,int> >pizza;

void DFS(int s, int L){
	if(L ==M){
		int sum =0;
		for(int i =0; i<house.size();i++){
			int cost;
			int mins = 9999;
			for(int j =0; j<M;j++){
				cost = abs(house[i].first - pizza[ch[j]].first) + abs(house[i].second - pizza[ch[j]].second);
				if(cost < mins){
					mins = cost;
				}
				//mins = min(mins, abs(house[i].first - pizza[ch[j]].first) + abs(house[i].second - pizza[ch[j]].second));
			}
			sum += mins;
		}
		if(sum < total_mins){
			total_mins = sum;
		}
	}else{
		for(int i =s; i<pizza.size(); i++){
			ch[L] = i;
			DFS(i+1, L+1);
		}
	}
}

int main(){
	//freopen("input.txt", "rt", stdin);
	cin >> N >>M;
	int tmp;
	for(int i = 0; i< N;i++){
		for(int j = 0; j<N;j++){
			scanf("%d", &tmp);
			if(tmp == 1){
				house.push_back(make_pair(i,j));
			}else if(tmp ==2){
				pizza.push_back(make_pair(i,j));
			}
		}
	}
	DFS(0, 0);
	printf("%d", total_mins);
	return 0;
}