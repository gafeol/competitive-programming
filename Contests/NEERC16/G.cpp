#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fst first
#define snd second
#define pb push_back


set<pii> q;

vector<pii> res;

int n;
ll s, d;


int cmp(pii a, pii b){
	if(a.snd < b.fst)
		return 0;
	if(a.fst > b.snd)
		return 2;
	return 1;
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s, &d);
		pii u = pii(s, s+d-1); 
		int ok = 1;
		for(auto &r: q){
			pii nxt = r;
			if(cmp(u, nxt) == 1)
				ok = 0;
		}
		if(ok){
			q.insert(u);
			res.pb(u);
			continue;
		}
		u = pii(1, 1+d-1);
		for(auto &r: q){
			pii nxt = r;
			if(cmp(u, nxt) == 1)
				u = pii(nxt.snd+1, nxt.snd+1+d-1);	
		}
		q.insert(u);
		res.pb(u);
	}
	for(pii u: res){
		printf("%lld %lld\n", u.fst, u.snd);
	}
}

