#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int valid(ll n){
	for(;n;n/=ll(10)){
		int r = n%ll(10);
		if(r == 3) return 0;
		if(r == 4) return 0;
		if(r == 7) return 0;
	}
	return 1;
}

int parse(int r){
	if(r == 6) return 9;
	if(r == 9) return 6;
	return r;
}

int test(ll n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	if(n == 3) return 1;
	if(n == 5) return 1;

	if(n%ll(2) == 0) return 0;
	if(n%ll(3) == 0) return 0;
	if(n%ll(5) == 0) return 0;

	for(ll w=6;w*w <= n; w++){
		w++;
		if(n%w == 0) return 0;
		w += ll(4);
		if(n%w == 0) return 0;
	}
	return 1;
}

int main(){
	ll n;
	cin >> n;
	if(!valid(n) || n == 1){
		puts("no");
		return 0;
	}
	int fst = test(n);
	
	ll m = 0;
	for(;n;n/=ll(10))
		m = ll(10)*m + ll(parse(n%ll(10)));

	int snd = test(m);

	if(fst&snd) puts("yes");
	else        puts("no");
}
