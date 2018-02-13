#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 8002;

const ll modn = 1e9+7;
const ll modn2 = 1e9+9;

inline ll mod(ll x){
	return x%modn;
}

inline ll mod2(ll x){
	return x%modn2;
}

unordered_map<pll, int> ind;

char s[MAXN];

ll h, h2;

const ll m = 26*2;

ll v(char c){
	if(c >= 'a' && c <= 'z')
		return c-'a';
	return 26+c-'A';
}

int main(){
	scanf(" %s", s);
	int n = strlen(s);

	ll res =0;
	for(int i=0;i<n;i++){
		h = 0;
		h2 = 0;
		for(int j=i;j<n;j++){
			h = mod(h*m + v(s[j]));
			h2 = mod2(h2*m + v(s[j]));
			if(ind.find(pll(h, h2)) == ind.end()){
				ind[pll(h, h2)]++;
				res += 1 + j - i;
			}
		}
	}
	printf("%lld\n", res);
}
