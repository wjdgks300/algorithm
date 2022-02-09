#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);		//only use cin,cout 
	ifstream cin;
	cin.open("input.txt");
	map<string, int> ch;
	map<string, int>::iterator it;
	char a[100]; 	//string a; 해도 결과값 같음 
	int n;
	cin >> n;
	for(int i =1; i <= n; i++){
		cin >>a;
		ch[a]++;
	}
	
	int max = 0;
	string res;
	
	for(it=ch.begin(); it!=ch.end(); it++){
		//cout << it->first << ' ' << it->second << "\n";
		if(it->second > max){
			max = it->second;
			res = it->first;
		}
	}
	
	cout << res << " : " << max << "\n";
	
	return 0;
}