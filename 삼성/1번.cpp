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

int capacity[20000];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("sample_input.txt", "rt", stdin);
	int t;
	cin >> t;
	for(int i = 0; i < t;i++){
		int n, m, d;
		cin >> n >> m >> d;
        int size = n * m;
		vector<int> v;
		vector<int> v2;
        int next = 0;
		for(int j = 0; j< n; j++){
			for(int k = 0; k < m;k++){
				int num;
				cin >> num;
				v.push_back(num);
                v2.push_back(0);
			}
		}
		for(int j = 0; j <d; j++){
			cin >> capacity[j];
		}
        sort(v.rbegin(), v.rend());
		long long sum = 0;
		for(int j = 0; j < d; j++){
			long long day = 0;
			//cout << v.top();
			for(int k = 0; k < capacity[j];k++){
				if(next >= size){
                    next = 0;
                }if(v[next] + j +1 -v2[next] == 2) day += 1;
                else day+= v[next] + j +1 -v2[next] -1;
                v2[next] = j+1;
                v[next] = 1;
                next++;
			}
//			cout << "day = "<< j << ":"<< day << endl;
			sum += day * (j+1);
		}
		cout <<"#"<< i+1 << " "<< sum << endl;
	}
		
	
	return 0;
}