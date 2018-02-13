#include<bits/stdc++.h>

using namespace std;

int n;

vector<string> ans;

int main(){
	scanf("%d", &n);
	n *= 2;
	for(int bm=0;bm<(1<<n);bm++){
		int cnt = 0, ok = 1;
		for(int a=0;a<n;a++){
			if(bm&(1<<a))
				cnt++;
			else
				cnt--;
			if(cnt < 0){
				ok = 0;
				break;
			}
		}
		if(cnt != 0) ok = 0;
		if(!ok) continue;
		string res = "";
		for(int a=0;a<n;a++){
			if(bm&(1<<a))
				res += '(';
			else
				res += ')';
		}
		ans.push_back(res);
	}
	sort(ans.begin(), ans.end());
	for(string s: ans){
		cout << s << endl;
	}
}
