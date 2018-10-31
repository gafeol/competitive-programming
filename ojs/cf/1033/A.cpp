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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pii q;

map<pii, int> mrk;

bool valid(pii x){
	return (x.fst >= 1 && x.snd >= 1 && x.fst <= n && x.snd <= n);
}

bool check(pii x){
	if((x.fst == q.fst) ||
		(x.snd == q.snd) ||
		(x.fst - x.snd == q.fst - q.snd) ||
		(x.fst + x.snd == q.fst + q.snd))
		return true;
	return false;
}

int vi[] = {0, 0, 1, 1, 1, -1, -1, -1};
int vj[] = {1, -1, 0, -1, 1, 0, 1, -1};

int main (){
	scanf("%d", &n);
	pii r, d;
	scanf("%d%d", &q.fst, &q.snd);
	scanf("%d%d", &r.fst, &r.snd);
	scanf("%d%d", &d.fst, &d.snd);
	queue<pii> q;
	q.push(r);
	mrk[r] = 1;
	while(!q.empty()){
		pii p = q.front();
		q.pop();
		for(int d=0;d<8;d++){
			pii nxt = p;
			nxt.fst += vi[d];
			nxt.snd += vj[d];
			if(valid(nxt) && !check(nxt) && !mrk[nxt]){
				mrk[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	if(mrk[d])
		puts("YES");
	else
		puts("NO");
}

