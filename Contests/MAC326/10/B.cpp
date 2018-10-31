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

vector<int> adj[MAXN];
int deg[MAXN];

int main (){
    for_tests(t ,tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            deg[a] = 0;
            adj[a].clear();
        }
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d %d", &i, &j);
            i--;j--;
            adj[i].pb(j);
            deg[j]++;
        }
        vector<int> res;
        queue<int> q;
        for(int a=0;a<n;a++){
            if(deg[a] == 0)
                q.push(a);
        }
        int miss = 0;
        while(!q.empty()){
            if(q.size() > 1)
                miss = 1;
            int u = q.front();
            res.pb(u);
            q.pop();
            for(int nxt: adj[u]){
                deg[nxt]--;
                if(deg[nxt] == 0)
                    q.push(nxt);
            }
        }
        if(res.size() < n){
            puts("recheck hints");
        }
        else if(miss)
            puts("missing hints");
        else
            for(int x: res)
                printf("%d ", x+1);
        res.clear();
        puts("");
    }
}

