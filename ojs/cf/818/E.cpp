#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXP = 35004, MAXN = 100010;

int n, m, k;
int s[MAXN];
int mrk[MAXP];

map<int, int> cnt, need;

vector<int> has;

vector<int> p;

void add(ll x){
	for(int pri: has){
		while(x%pri == 0){
			x /= pri;
			cnt[pri]++;
		}
	}
}

void rmv(ll x){
	for(int pri: has){
		while(x%pri == 0){
			x /= pri;
			cnt[pri]--;
		}
	}
}

bool valid(){
	for(int pri: has){
		if(cnt[pri] < need[pri])
			return false;
	}
	return true;
}

int main (){
	for(int a=2;a<MAXP;a++){
		if(mrk[a]) continue;
		p.pb(a);
		for(ll b = a;a*b < MAXP;b++){
			mrk[a*b] = 1;
		}
	}
	scanf("%d%d", &n, &m);

	int mm = m;

	for(int pri: p){
		if(pri > sqrt(mm) + 1) break;
		while(mm%pri == 0){
			mm /= pri;
			need[pri]++;
			has.pb(pri);
		}
	}
	if(mm != 1){
		has.pb(mm);
		need[mm]++;
	}
	sort(has.begin(), has.end());
	has.erase(unique(has.begin(), has.end()), has.end());

	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	int j = -1;
	ll res = 0;
	for(int i = 0;i < n;i++){
		while(j < i){
			++j;
			add(s[j]);
		}
		while(j < n-1 && !valid()){
			++j;
			add(s[j]);
		}
		if(!valid())
			break;
		res += (n-j);
		debug("pega i %d j %d\n", i, j);
		rmv(s[i]);
	}
	printf("%lld\n", res);
}
