#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	char k;
	cin >> n >> k;
	k = toupper(k);
	
	for(int i = 0; i< n; i++){
		string tmp;
		cin >> tmp;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
		//cout << tmp << endl;
		if(tmp.find(k) != string::npos){
			string res = "";
			for(int i = 0; i < tmp.size(); i++){
				if(tmp.find(tmp[i]) == i) res += tmp[i];
			}
			cout << res << endl;
		}
	}

	return 0;
}