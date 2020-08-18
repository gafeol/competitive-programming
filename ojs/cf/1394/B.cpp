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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

random_device rd;     //Get a random seed from the OS entropy device, or whatever
mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator and seed it with entropy.
//Define the distribution, by default it goes from 0 to MAX(unsigned long long)
uniform_int_distribution<unsigned long long> distr;
unsigned long long getRand() { return distr(eng); }

const int MAXN = 212345;
const int H = 4;

ull h[H][MAXN];

int n, m, k;

ull acc[H][10][10];
ull res[H];


vector<pii> adj[MAXN];
int mxdeg;

vector<ull> hx;
int go(int deg){
    if(deg == 0){
        for(int a=0;a<H;a++){
            hx.pb(0);
        }
        return go(deg+1);
    }
    if(deg == mxdeg+1){
        for(int i=0;i<H;i++){
            if(res[i] != hx[i])
                return 0;
        }
        return 1;
    }

    int ans = 0;
    for(int ch=0;ch<deg;ch++){
        for(int i=0;i<H;i++){
            hx[i] ^= acc[i][deg][ch];
        }
        ans += go(deg+1);
        for(int i=0;i<H;i++){
            hx[i] ^= acc[i][deg][ch];
        }
    }
    return ans;
}

int main (){
    srand(time(NULL));
	scanf("%d%d%d", &n, &m, &mxdeg);
	for(int a=0;a<n;a++){
        for(int i=0;i<H;i++){
            h[i][a] = getRand();
            res[i] ^= h[i][a];
        }
	}
    for(int a=0;a<m;a++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--;v--;
        adj[u].pb({c, v});
    }
    for(int u=0;u<n;u++){
        sort(adj[u].begin(), adj[u].end());
        int deg = adj[u].size();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].snd;
            for(int a=0;a<H;a++){
                acc[a][deg][i] ^= h[a][v];
            }
        }
    }
    printf("%d\n", go(0));
}

