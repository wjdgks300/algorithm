#include <bits/stdc++.h>
using namespace std;

long long maps[1024 * 1025 *2];
long long tempN;

long long cal_sum(long long a,long long b){ // 1~ 3
	a = a + tempN - 1;
	b = b + tempN - 1;
	
	long long sum = 0;
	while(a <=b){
		// a = right child 
		if((a&1) == 1) sum += maps[a];
		// b = left child 
		if((b&1) == 0) sum += maps[b];
		
		a = (a+1) >> 1;  //bit 연산 >> 1 same  /2 
		b = (b-1) >> 1;
		
	}

	return sum;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "rt", stdin);
    int n,m,k;
    cin >> n >> m >> k;
    for(tempN = 1; tempN < n; tempN = tempN << 1);
	//cout << last;
	
	
	for(int i = tempN; i < tempN + n;i++){
		cin >> maps[i];
	}
	
	for(int i = tempN -1; i >=1; i--) maps[i] = maps[2* i] + maps[2* i +1];
	
	long long a, b, c;
	for(int i = n+2; i <= n+m+k+1; i++){
		cin >> a >> b >> c;
		if(a == 1){
			maps[tempN + b -1] = c;
			int x = tempN + b -1;
			x =  x >> 1;
			while(x > 0){
				maps[x] = maps[x*2] + maps[x *2 + 1];
				x = x>>1;
			}
		}
		if(a == 2){
			cout << cal_sum(b,c) << "\n";
		}
	}

    return 0;
}
