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

int n, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> adj[MAXN];

map<int, int> m[MAXN];

int mrk[MAXN];

int main (){
	scanf("%d", &n);
    for(int a=1;a<=n;a++)
        m[a][a] = 1;
	for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        m[i][j] = 1;
        adj[j].pb(i);
        m[j][i] = 1;
	}
    for(int a=0;a<n;a++){
        scanf("%d", s+a);
    }
    if(s[0] != 1){
        puts("No");
        return 0;
    }
    int r = 0;
    for(int a=0;a<n;a++){
        mrk[s[a]] = 1;
        while(r < n && m[s[a]][s[r]]){
            mrk[s[r]] = 1;
            r++;
        }
        for(int nxt: adj[s[a]]){
            if(mrk[nxt]) continue;
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}


