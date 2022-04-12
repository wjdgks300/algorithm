#include <bits/stdc++.h>

using namespace std;
vector<char> vec(1000001);
vector<char> bumb(37);
vector<char> ans(1000001);
string a, b;

bool is_matching(int start){
	for(int i = start; i < start+ b.size(); i++){
		if(ans[i] != b[i - start])
			return false;
	}
	return true;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	
	cin >> a >> b;
	int len = b.size();
	int pos = 0;
	for(int i =0; i < a.size(); i++){
		ans[pos] = a[i];
		pos+=1;
		if((pos -len) >= 0 && is_matching(pos - len)){
			pos -= len;
		}
	}
	ans[pos] = '\0';
	if(pos == 0) cout << "FRULA";
	else{
		for(int i =0; ans[i] != '\0'; i++){
			cout << ans[i];
		}
	}
	
	return 0;
}


