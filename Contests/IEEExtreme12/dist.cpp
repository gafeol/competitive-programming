#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 612345;

int n, m, k;
int s[MAXN];

set<pii> pu, pd;

set<int> fr;

vector<int> rep;

ll bitu[MAXN], bitd[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

void updu(int i, ll val){
	i += 2;
	while(i < MAXN){
		bitu[i] += val;
		i += (i&-i);
	}
}

void updd(int i, ll val){
	i += 2;
	while(i < MAXN){
		bitd[i] += val;
		i += (i&-i);
	}
}

ll qryu(int i){
	i += 2;
	ll ans = 0;
	while(i > 0){
		ans += bitu[i];
		i -= (i&-i);
	}
	return ans;
}

ll qryd(int i){
	i += 2;
	ll ans = 0;
	while(i > 0){
		ans += bitd[i];
		i -= (i&-i);
	}
	return ans;
}

// men, mai
ll sumup(int i, int j){
	return qryu(j) - qryu(i-1);	
}

ll sumdw(int i, int j){
	return qryd(j) - qryd(i-1);
}

int mrk[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] += n;
		if(mrk[s[a]])
			rep.pb(s[a]);
		mrk[s[a]] = 1;
	}
	sort(s, s+n);
	sort(rep.begin(), rep.end());

	for(int a=0;a<MAXN;a++){
		if(!mrk[a])
			fr.insert(a);
	}
	ll res = 0;
	for(int pos: rep){
		int cld = *(--fr.lower_bound(pos));
		int clu = *fr.upper_bound(pos);
		//printf("pos %d\n", pos);
		//printf("cld %d clu %d\n", cld, clu);
		ll vald = pos - cld - sumup(cld, pos-1);
		ll valu = clu - pos - sumdw(pos+1, clu);
		//printf("vald %lld valu %lld\n", vald, valu);
		if(vald <= valu){
			auto it = pu.lower_bound(pii(cld, -1));
			res += vald;			
			while((it = pu.lower_bound({cld, -1})) != pu.end() && it->fst < pos){
				int p = it->fst;
				int val = it->snd;
				updu(p, -val);
				pu.erase(it);
			}

			pd.insert(pii(cld, pos - cld));
			updd(cld, pos-cld);
			fr.erase(cld);
		}
		else{
			res += valu;
			auto it = pd.upper_bound({pos, INT_MAX});
			while((it = pd.upper_bound({pos, INT_MAX})) != pd.end() && it->fst < clu){
				int p = it->fst;
				int val = it->snd;
				updd(p, -val);
				pd.erase(it);
			}

			pu.insert(pii(clu, clu - pos));
			updu(clu, clu - pos);
			fr.erase(clu);
		}
	}
	printf("%lld\n", res);
}

