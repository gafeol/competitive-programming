#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007	;
inline ll mod(ll x) { return x % modn; }

#define type fst
#define time snd.fst
#define xx snd.snd

const int MAXN = 212345;

int n, m, k;
pip s[MAXN];

map<int, int> ind, bit[MAXN];

vector<int> cmp;

int mxt;

void upd(int a, int i, int val){
	while(i < mxt){
		bit[a][i] += val;
		i += (i&(-i));
	}
}

int qry(int a, int i){
	int res = 0;
	while(i > 0){
		res += bit[a][i];
		i -= (i&(-i));
	}
	return res;
}

int main (){
	int deg = 0;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int tp, t, x;
		scanf("%d %d %d", &tp, &t, &x);
		s[a].type = tp;
		s[a].time = t;
		s[a].xx = x;
		cmp.pb(t);
	}

	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	mxt = cmp.end() - cmp.begin() + 10;

	for(int a=0;a<n;a++){
		int tp = s[a].type;
		int t = lower_bound(cmp.begin(), cmp.end(), s[a].time) - cmp.begin() + 1;
		int x = s[a].xx;
	
		if(tp == 1){
			if(ind.find(x) == ind.end())
				ind[x] = deg++;
			upd(ind[x], t, 1);
		}
		else if(tp == 2){
			if(ind.find(x) == ind.end())
				ind[x] = deg++;
			upd(ind[x], t, -1);
		}
		else{
			if(ind.find(x) == ind.end())
				ind[x] = deg++;
			printf("%d\n", qry(ind[x], t));
		}
	}
}
