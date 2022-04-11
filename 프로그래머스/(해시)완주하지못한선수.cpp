#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    string answer = "";
    for(int i= 0; i < completion.size(); i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
    }
    if(answer == ""){
        answer = participant[completion.size()];
    }
    return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	vector<string> a = {"leo", "kiki", "eden"};
	vector<string> b = {"eden", "kiki"};
	
	cout << solution(a,b);
	
	return 0;
}


