#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long calculate(long long a, long long b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
}


long long solution(string expression) {
    long long answer = 0;
    vector<long long> operand;
    vector<char> operators;
    string num = "";
    for(int i = 0; i< expression.length(); i++){
        if(expression[i] >= '0' && expression[i] <='9'){
        	num += expression[i];
		}
		else{
			operand.push_back(stoll(num));
			operators.push_back(expression[i]);
			num = "";
		}
    }
    operand.push_back(stoll(num));
    
//    for(auto a: operand) cout << a << " " ;
//    cout << endl;
//    for(auto b: operators) cout << b << " ";
	
	
	
	vector<int> check = {0,1,2};
	string op = "*+-";
	do{
		vector<long long> temp_operand = operand;
		vector<char> temp_operators = operators;
		
		
		for(int i = 0; i < 3; i++){
			long long re_cal;
			for(int j = 0; j < temp_operators.size(); ){
				if(op[check[i]] == temp_operators[j]){
					re_cal = calculate(temp_operand[j], temp_operand[j+1], temp_operators[j]);
					temp_operand.erase(temp_operand.begin() + j,temp_operand.begin()+ j + 2);
					temp_operand.insert(temp_operand.begin() + j,re_cal);
					temp_operators.erase(temp_operators.begin()+j);
				}else{
					j++;
				}
			}
		}
		answer = max(answer, abs(temp_operand[0]));
		
	}while(next_permutation(check.begin(), check.end()));
	

    return answer;
}


int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	//int a = solution("100-200*300-500+20");
	
	//cout << a << endl;
	vector<int> v = {0,1,2};
	do{
		for(auto a: v) cout << a;
		cout << endl;
	}while(next_permutation(v.begin(), v.end()));
	
	
	return 0;
}