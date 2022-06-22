#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;

struct loc{
	int x,y,val;
	loc(int x, int y, int val){
		
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	for(int i = 0; i < t;i++){
		int n, m, d;
		cin >> n >> m >> d;
		priority_queue<int> v;
		vector<int> v2;
		for(int j = 0; j< n; j++){
			for(int k = 0; k < m;k++){
				int num;
				cin >> num;
				v.push(num);
			}
		}
        int size = (n-1) * (m-1);
		for(int j = 0; j <d; j++){
			int num;
			cin >> num;
			v2.push_back(num);
		}
		long long sum = 0;
        int cnt = 0;
		for(int j = 0; j < d; j++){
			long long day = 0;
			//cout << v.top();
			for(int k = 0; k < v2[j];k++){
				day += v.top() + j;
//				cout << v[k] << " ";
				v.pop();
				v.push(-j);
			}
//			cout << "day = "<< j << ":"<< day << endl;
			sum += day * (j+1);
		}
		cout <<"#"<< i+1 << " "<< sum << endl;
	}
		
	
	return 0;
}