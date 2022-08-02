#include <bits/stdc++.h>
using namespace std;

int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++){
    	int num;
    	cin >> num;
    	v.push_back(num);
	}
    
    sort(v.begin(), v.end());
    
    int left = 0, min;
    int right = N- 1;
    int res_r = right, res_l = left;
    
    if(abs(v[left] - v[right]) > abs(v[left] + v[right])) min = abs(v[left] +v[right]);
    else min = abs(v[left] - v[right]);
    
    while(left < right){
    	if(v[left] + v[right] < 0){
    	
			
		}
		
		
	}
	cout << v[res_l] << " " << v[res_r];
    
	return 0;	
}
