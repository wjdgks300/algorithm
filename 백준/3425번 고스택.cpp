#include <bits/stdc++.h>
using namespace std;
stack<long long> st2;
bool is_error = true;

void check(){
	if(st2.size() != 1 || is_error == false){
		cout << "ERROR" << "\n";
		while(!st2.empty()){
			st2.pop();
		}
	}
	else{
		cout << st2.top() << "\n";
		st2.pop();
	}
	return;
}

void play(vector<string> v, vector<long long> num_v){
	int cnt = 0;
	for(int i = 0; i <v.size(); i++){
		if(v[i] == "NUM"){
			long long num = num_v[cnt];
			cnt++;
			st2.push(num);
		}else if(v[i] == "POP"){
			if(st2.empty()){
				is_error = false;
				return;
			}
			st2.pop();	
		}else if(v[i] == "INV"){
			if(st2.empty()){
				is_error = false;
				return;
			}
			else{
				long long tmp = -st2.top();
				st2.pop();
				st2.push(tmp);
			}
		}else if(v[i] == "DUP"){
			long long tmp = st2.top();
			st2.push(tmp);
			
		}else if(v[i] == "SWP"){
			if(st2.size() < 2){
				is_error = false;
				return;
			}
			long long tmp = st2.top();
			st2.pop();
			long long tmp2 = st2.top();
			st2.pop();
			st2.push(tmp);
			st2.push(tmp2);
			
		}else if(v[i] == "ADD"){
			if(st2.size() < 2){
				is_error = false;
				return;
			}
			long long tmp = st2.top();
			st2.pop();
			long long tmp2 = st2.top();
			st2.pop();
			if(abs(tmp+ tmp2) > 1000000000){
				is_error = false;
				return;
			}
			st2.push(tmp + tmp2);
			
		}else if(v[i] == "SUB"){
			if(st2.size() < 2){
				is_error = false;
				return;
			}
			long long tmp = st2.top();
			st2.pop();
			long long tmp2 = st2.top();
			st2.pop();
			if(abs(tmp - tmp2) > 1000000000){
				is_error = false;
				return;
			}
			st2.push(tmp2 - tmp);
			
		}else if(v[i] == "MUL"){
			if(st2.size() < 2){
				is_error = false;
				return;
			}
			long long tmp = st2.top();
			st2.pop();
			long long tmp2 = st2.top();
			st2.pop();
			if(abs(tmp * tmp2) > 1000000000){
				is_error = false;
				return;
			}
			st2.push(tmp * tmp2);
			
		}else if(v[i] == "DIV"){
			if(st2.size() < 2){
				is_error = false;
				return;
			}
			long long tmp = st2.top();
			st2.pop();
			long long tmp2 = st2.top();
			st2.pop();
			int div_cnt = 0;
			if(tmp < 0) div_cnt++;
			if(tmp2 < 0) div_cnt++;
			if(tmp != 0){
				int push_num = abs(tmp2) / abs(tmp);
				if(div_cnt == 1){
					st2.push(-push_num);	
				}else{
					st2.push(push_num);
				}
				
				
			}
			if(tmp == 0){
				is_error = false;
				return;
			}
		}else if(v[i] == "MOD"){
			if(st2.size() < 2){
				is_error = false;
				return;
			}
			long long tmp = st2.top();
			st2.pop();
			long long tmp2 = st2.top();
			st2.pop();
			if(tmp != 0){
				st2.push(tmp2 % tmp);
			}
			if(tmp == 0){
				is_error = false;
				return;
			}
		}
	}
	return;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    string s;
    
    while(s != "QUIT"){
    	vector<string> v;
    	vector<long long> num_v;
    	stack<long long> st;
    	while(1){
    		cin >> s;
    		if(s == "NUM"){
    			long long n;
    			cin >> n;
				num_v.push_back(n);
			}
    		
			
    		if(s == "END"){
    			s = "";
				break;	
			}
			if(s == "QUIT") break;
			v.push_back(s);
		}
		
		
		if(s == "QUIT") continue;
		long long num, input;
		cin >> num;
		for(int i = 0; i < num; i++){
			cin >> input;
			//st.push(input);
			st2.push(input);
			play(v, num_v);
			check();
			is_error = true;
//			cout << input << endl;
		}
		cout << endl;
    	
	}
    return 0;
}
