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

const int MAXN = 512345;

int n, m, k;
int s[MAXN];

int tot[MAXN];

map<int, int> cnt;
map<int, int> took;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        tot[++cnt[s[a]]]++;
	}
    for(int a=1;a<MAXN;a++)
        tot[a] += tot[a-1];
    int bst = 0, bsta = -1, bstb = -1;
    for(int a=1;a <= n;a++){
        int b = tot[a]/a; 
        //printf("a %lld tot %d b %lld\n", a, tot[a], b);
        if(b < a) continue;
        if(bst < a*b){
            bst = a*b;
            bsta = a;
            bstb = b;
        }
    }
    assert(bst != 0);
    printf("%d\n%d %d\n", bst, bsta, bstb);
    vector<pii> stock;
    auto it = cnt.begin();
    int sz = bsta*bstb;
    while(sz > 0){
        int qtd = min(it->snd, min(sz, bsta));
        sz -= qtd;
        stock.pb({qtd, it->fst});
        it++;
    }

    sort(stock.begin(), stock.end(), greater<pii>());
    int a = 0;
     
    vector<vector<int>> M(bsta, vector<int>(bstb,0));
    for(int ii=0;ii<bsta;ii++){
        for(int jj=0;jj<bstb;jj++){
            int i = ii, j = jj;
            if(M[i][j] == 0)
                assert(i == 0);
            while(M[i][j] == 0){
                //printf("bota %d em %d %d\n", it->fst, i, j);
                if(took[stock[a].snd] >= stock[a].fst)
                    a++;
                M[i][j] = stock[a].snd;
                took[stock[a].snd]++;
                i = (i+1)%bsta;
                j = (j+1)%bstb;
            }
        }
    }
    /*
    for(int a=0;a<bsta;a++){
        map<int, int> has;
        for(int b=0;b<bstb;b++){
            assert(has[M[a][b]] == 0);
            has[M[a][b]] = 1;
        }
        has.clear();
    }
    for(int b=0;b<bstb;b++){
        map<int, int> has;
        for(int a=0;a<bsta;a++){
            assert(has[M[a][b]] == 0);
            has[M[a][b]] = 1;
        }
        has.clear();
    }
    */
    for(int a=0;a<bsta;a++){
        for(int b=0;b<bstb;b++){
            printf("%d ", M[a][b]);
        }
        puts("");
    }
}

