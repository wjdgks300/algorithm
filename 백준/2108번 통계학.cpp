#include<bits/stdc++.h>	

using namespace std;

struct loc{
	int num, cnt;
	loc(int a, int b){
		num = a;
		cnt = b;
	}
	bool operator < (const loc &b)const{
		return num < b.num;
	}
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n;
	int tmp, input;
	
	cin >> n;
	cin >> input;
	vector<loc> vec;
	vec.push_back(loc(input,0));
	for(int i=1; i < n; i++){
		cin >> tmp;
		vec.push_back(loc(tmp, 0));
	} 
	
	sort(vec.begin(), vec.end());
	vector<loc> vec2;
	for(int i =0; i< vec.size(); i++){
		if(vec2.empty()){
			vec2.push_back(loc(vec[i].num, vec[i].cnt));
			continue;
		}
		if(vec2.back().num == vec[i].num){
			loc tmps = vec2.back();
			tmps.cnt++;
			vec2.pop_back();
			vec2.push_back(tmps);
		}else{
			vec2.push_back(loc(vec[i].num, 0));
		}
	}
	
//	for(int i =0 ;i < vec2.size(); i++){
//		cout << "num = " <<vec2[i].num << "cnt = " << vec2[i].cnt << endl;;
//	}
	
	int sum = 0;
	int max = -1, res;
	for(int i =0 ;i < vec.size(); i++){
		sum += vec[i].num; 
	}
	
	for(int i =0 ;i < vec2.size(); i++){
		if(max < vec2[i].cnt) {
			max = vec2[i].cnt;
			res = vec2[i].num;
		}
	}
	int two =0;
	for(int i =0 ;i < vec2.size(); i++){
		if(vec2[i].cnt == max){
			two++;
			if(two == 2){
				res = vec2[i].num;
				break;
			}
		}
	}
	//cout << sum << endl;
	int len = vec.size();
	float avg = sum / (float)n;
	//cout << avg << round(avg) << endl;
	//cout << k<< endl;
	if(round(avg) == -0) cout << 0 <<endl;
	else
		cout << round(sum/(float)n) << endl;
	cout << vec[len/ 2].num << endl;
	cout << res << endl;
	if(len != 1){
		cout << abs(vec[0].num - vec[len -1].num) << endl;	
	}
	else cout << 0 << endl;
	
	return 0;
}


