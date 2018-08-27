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

const int MAXN = 364345;

int n, m, k;
void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

set<int> q;

set<pii> s;

char t[110];

int findval(int x){
	auto nxt = s.lower_bound(pii(x, 0));
	int aft = -1;
	if(nxt != s.end()){
		aft = nxt->snd; 
	}
	int bef = -1;
	auto lst = s.lower_bound(pii(x, 0));
	if(lst != s.begin()){
		lst--;
		bef = lst->snd;
	}
	//printf("add %d bef %d aft %d\n", x, bef, aft);
	if(aft == bef) return aft;
	if(aft == 0 && bef == 1){
		puts("0");
		exit(0);
	}
	if(aft == 0) return 0;
	if(bef == 1) return 1;
	return -1;
}

void isbest(pii p){
	auto lst = s.lower_bound(p);
	//puts("bla");
	if(lst != s.begin()){
		lst--;
		if(lst->snd == 1){
			puts("0");
			exit(0);
		}
	}
	//puts("bla");
//	printf("is best %d %d\n", p.fst, p.snd);
	
	auto nxt = s.lower_bound(p);
	nxt++;
	if(nxt != s.end()){
		if(nxt->snd == 0){
			puts("0");
			exit(0);
		}
	}
//	puts("bla");
}

int main (){
	scanf("%d", &n);
	ll res = 1;
	for(int a=0;a<n;a++){
		//printf("a %d\n", a);
		int x;
		scanf(" %s %d", t, &x);
		if(t[1] == 'D'){
			int val = findval(x);
			//printf("val %d\n", val);
			if(val == -1)
				q.insert(x);
			else
				s.insert(pii(x, val));
		}
		else{
			if(q.find(x) == q.end()){
				pii p = *s.lower_bound(pii(x, 0));
				if(p.fst == x){
					isbest(p);
					s.erase(p);					
					for(auto it: q){
						int p = it;
						if(p < x)
							s.insert(pii(p,0));
						else
							s.insert(pii(p,1));
					}
				}
				else 
					assert(false);
			}
			else{
				res = mod(res * 2ll);
				int type = 0;
				for(auto it: q){
					int p = it;
					//	printf("insert %d %d\n", p, type);
					if(p == x)
						type++;
					else
						s.insert(pii(p, type));
				}
				q.clear();
			}
		}
	}
	//printf("sz %d\n", q.size());
	res = mod(res * (1ll + (ll)q.size()));
	printf("%lld\n", res);
}

