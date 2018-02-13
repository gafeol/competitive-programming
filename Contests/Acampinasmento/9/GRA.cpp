#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define fst first
#define snd second

typedef long long ll;

#define pb push_back

const int MAXN = 500010;

int n;

ll m;

int s[MAXN];

vector<pii> v;

int main (){
	scanf("%lld %d", &m, &n);
	int qtd = 0;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] = m - s[a];
	}
	int pos = 0;
	int ult = 0;
	int cnt = 0;
	for(int a=n-1;a>=0;a--){
		pos += s[a] - ult;
		cnt = 1;
		while(s[a] == s[a-1] - 1){
			cnt++;
			a--;
		}
		v.pb(pii(pos, cnt));
		ult = s[a]+1;
	}
	ll x = 0;
	for(pii u: v){
		if((u.fst&1))
			x ^= u.snd; 
		printf("%d %d\n", u.fst, u.snd);
	}
	for(pii u: v){
		for(int q=1;q<=u.snd;q++){
			if(x^q == 0)
				
		}
	}
}
