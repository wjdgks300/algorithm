#include<bits/stdc++.h>	
using namespace std;
int n, k;
char num[500000];
int main(void)
{
	int min = 9;
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	cin >> num[0];
	
	char c;
	int location = 1;
	int tmp = k;
	for(int i =1; i < n; i++){
		cin >> c;
		while(location > 0 && c > num[location - 1] && tmp > 0){
			tmp--;
			location--;
		}
		num[location] = c;
		location++;
	}
	for(int i= 0; i< n-k; i++){
		cout << num[i];
	}
	return 0;
}


