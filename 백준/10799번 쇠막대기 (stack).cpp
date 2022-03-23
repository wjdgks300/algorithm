#include<bits/stdc++.h>	
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	string input;
	stack<int> s;
	
	int total = 0;
	cin >> input;
	int check = 0;
	
	for(int i= 0; input[i] != '\0'; i++){
		if(input[i] == '('){
			s.push(1);
			check = 1;
		}
		else{
			if(check ==1){
				
				s.pop();
				total += s.size();
				check = 0;
			}
			else{
				check = 0;
				total++;
				s.pop();
			}
		}
	}
	
	cout << total << endl;
	
	return 0;
}


