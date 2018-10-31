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

const int MAXN = 512;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int vi[] = {0, 0, -1, 1, 1, 1, -1, -1};
int vj[] = {1, -1, 0, 0, -1, 1, -1, 1};

set<tuple<ll, int, int> > q;
ll M[MAXN][MAXN], d[MAXN][MAXN];

const ll INF = LLONG_MAX;

bool valid(int i, int j){
    return i>= 0 && j >= 0 && i < n && j < m;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf("%lld", &M[a][b]);
            d[a][b] = INF;
        }
	}
    int i, j;
    scanf("%d%d", &i, &j);
    i--;j--;
    d[i][j] = M[i][j];
    q.insert({d[i][j], i, j}); 
    ll res = 0;
    while(!q.empty()){
        ll di;
        tie(di, i, j) = *q.begin();         
        res += max(0ll, -di);
        q.erase(q.begin());
        for(int dir = 0 ;dir < 8;dir++){
            int ii = i + vi[dir]; 
            int jj = j + vj[dir];
            if(valid(ii, jj) && d[ii][jj] > max(M[ii][jj], d[i][j])){
                if(d[ii][jj] != INF)
                    q.erase({d[ii][jj], ii, jj});
                d[ii][jj] = max(M[ii][jj], d[i][j]);
                q.insert({d[ii][jj], ii, jj});
            }
        }
    }
    printf("%lld\n", res);
}

