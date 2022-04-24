#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int n, p, q, r;

vector<string> split(string sentence, char Separator){
	vector<string> answer;
	stringstream ss(sentence);
	string tmp;
	
	while(getline(ss, tmp, Separator)){
		answer.push_back(tmp);
	}
	return answer;
}



int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	string a;
	cin >> a;
	vector<string> result = split(a, '-');
	vector<int> res;
	int k;
	for(int i = 0; i< result.size(); i++){
		//cout << result[i] << endl;
		string b = result[i];
		vector<string> tmp = split(b, '+');
		int sum = 0;
		for(int j = 0; j < tmp.size(); j++){
			//cout << tmp[j] << endl;
			sum += stoi(tmp[j]);
		}
		res.push_back(sum);
	}
	k = res[0];
	if(res.size() == 1) cout << k;
	else{
		for(int i = 1; i< res.size(); i++){
			k -= res[i];
		}
		cout << k;
	}
	
	return 0;
}