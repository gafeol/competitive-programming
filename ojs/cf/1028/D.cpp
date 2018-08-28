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

set<int> s[2];

void fail(){
	puts("0");
	exit(0);
}

void add(int x, int val = -1){
	debug("add", x, val);
	if(val == -1){
		if(s[0].upper_bound(x) != s[0].end())
			add(x, 0);
		else if(s[1].lower_bound(x) != s[1].begin())
			add(x, 1);
		else
			q.insert(x);
		return ;
	}

	if(val == 0){
		if(s[1].lower_bound(x) != s[1].begin())
			fail();
		s[val].insert(x);
	}
	else{
		if(s[0].upper_bound(x) != s[0].end())
			fail();
		s[val].insert(x);
	}
	
}

char t[110];
int main (){
	scanf("%d", &n);
	ll res = 1;
	for(int a=0;a<n;a++){
		int x;
		scanf(" %s %d", t, &x);
		if(t[1] == 'D')
			add(x);	
		else{
			if(q.find(x) != q.end()){
				res = mod(res*2ll);
				q.erase(x);
			}
			else{
				if(s[0].find(x) != s[0].end()){
					if(*s[0].rbegin() != x)
						fail();
					s[0].erase(x);
				}
				else{
					if(!s[1].empty() && *s[1].begin() != x)
						fail();
					s[1].erase(x);
				}
			}
			for(auto it: q)
				add(it, (it > x));
			q.clear();
		}
	}
	res = mod(res * (1ll + (ll)q.size()));
	printf("%lld\n", res);
}

