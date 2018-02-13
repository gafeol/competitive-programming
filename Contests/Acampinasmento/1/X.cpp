#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> s;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		s.push_back(x);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	if((n&1)){
		for(int a=0;a<s.size();a++){
			printf("%d\n", s[a]);
		}
	}
	else{
		for(int a=s.size()-1;a>=0;a--){
			printf("%d\n", s[a]);
		}
	}
}
