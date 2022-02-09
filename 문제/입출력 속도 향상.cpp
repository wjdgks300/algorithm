#include<bits/stdc++.h>	
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <map>
//#include <string>
using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);		//only use cin,cout 
	// -> time: scanf < ios_base::sync_with_stdio(false) 사용하는거보다 빠르다. 
	cin.tie(NULL);		// speed up
	freopen("input.txt", "rt", stdin);
	int n, min = 10000000;
	cin >> n;
	vector<int> a(n);
	for(int i =0; i < n; i++){
		cin >> a[i];
	}
	for(int i =0; i < n; i++){
		if(a[i] < min) min = a[i];
	}
	cout << min;
	
	return 0;
}