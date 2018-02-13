#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 50002;

const ll modn = 1e9+7;
const ll modn2 = 1e9+9;

inline ll mod(ll x){
	return x%modn;
}

inline ll mod2(ll x){
	return x%modn2;
}

ll h[2][MAXN];
ll h2[2][MAXN];



char s[MAXN], t[MAXN];

const ll m = 26*2;

ll v(char c){
	if(c >= 'a' && c <= 'z')
		return c-'a';
	return 26+c-'A';
}

bool eq(int i){
	return (h[0][i] == h[1][i] && h2[0][i] == h2[1][i]);
}

int main(){
	scanf(" %s", s);
	scanf(" %s", t);
	if(strcmp(s, t) == 0){
		printf("Yes\n0\n");
		return 0;
	}

	int n = strlen(s);
	for(int i=0;i<n/2;i++){
		swap(s[i], s[n-1-i]);
	}
	for(int i=0;i<n;i++){
		if(i > 0){
			h[0][i] = mod(h[0][i-1]*m + v(s[i]));
			h2[0][i] = mod2(h2[0][i-1]*m + v(s[i]));
		}
		else{
			h[0][i] = mod(v(s[i]));
			h2[0][i] = mod2(v(s[i]));
		}
	}
	ll pot = 1, pot2 = 1;
	for(int i=0;i<n;i++){
		if(i > 0){
			h[1][i] = mod(h[1][i-1] + v(t[i])*pot);
			h2[1][i] = mod2(h2[1][i-1] + v(t[i])*pot2);
		}
		else{
			h[1][i] = mod(v(t[i]));
			h2[1][i] = mod2(v(t[i]));
		}
		pot = mod(pot*m);	
		pot2 = mod2(pot2*m);
	}
	for(int i=n-1;i>0;i--){
		if(s[i] != t[i]) break;	
		if(eq(i-1)){
			printf("Yes\n%d\n", n-i);
			return 0;
		}
	}
	if(eq(n-1)){
		printf("Yes\n%d\n", n);
		return 0;
	}
	puts("No");
}
