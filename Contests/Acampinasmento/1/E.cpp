

#include<bits/stdc++.h>

using namespace std;


int n;

void solve(string s, int val, int ult){
	if(val == 0)
		cout << s << endl;
	for(int i=min(ult, val);i>0;i--){
		string ns = s;
		if(s != "")
			ns += '+';
		if(i/10 != 0){
			ns += '0'+(i/10);
		}
		ns += '0'+(i%10);
		solve(ns, val-i, i);
	}
}

int main(){
	scanf("%d", &n);
	solve("", n, n);
}
