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

const int MAXN = 3601;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int d[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	for_tests(t,tt){
		scanf("%d%d", &n, &k);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		memset(d, INF, sizeof(d));
		queue<int> q;
		q.push(0);
		d[0] = 0;
		while(!q.empty()){
			int u = q.front();	
			q.pop();
			for(int a=0;a<n;a++){
				int nxt = max(0, min(3600, u + s[a]));
				if(d[nxt] == INF){
					d[nxt] = d[u] + 1;
					q.push(nxt);
				}
			}
		}
		for(int a=k;a<=3600;a++){
			if(d[a] != INF){
				printf("%d %d\n", d[a], a-k);
				break;
			}
		}
	}
}

