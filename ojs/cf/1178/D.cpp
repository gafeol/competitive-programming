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

const int MAXN = 212345;
const int MAXP = 212345;

int n, m, k;
int s[MAXN];
int mrk[MAXP];
int deg[MAXN];

int liga[1234][1234];

vector<pii> e;

void add(int a, int b){
    e.pb({a, b});
    assert(liga[a][b] == 0);
    assert(liga[b][a] == 0);
    assert(a != b);
    liga[a][b] = 1;
    liga[b][a] = 1;
    deg[a]++;
    deg[b]++;
}

int main (){
    vector<int> pri;
    for(int a=2;a<MAXP;a++){
        if(mrk[a]) continue;
        pri.pb(a);
        for(ll b = a;b * a < MAXP;b++)
            mrk[a*b] = 1;
    }
    int mx = 0;
    int bf = 0;
    for(int p: pri){
        if(mx < p - bf){
    //        printf("prime %d - %d: gap %d\n", bf, p, p - bf);
            mx = p - bf;
        }
        bf = p;
    }
	scanf("%d", &n);
    int nn = n;
    while(n > 0 && n != 4 && n != 5){
        int a = n-2, b = n-1, c = n;
        add(a, b);
        add(a, c);
        add(b, c);
        n -= 3;
    }
    if(n == 4){
        add(1, 2);
        add(2, 3);
        add(3, 4);
        add(4, 1);
    }
    else if(n == 5){
        add(1, 2);
        add(2, 3);
        add(3, 4);
        add(4, 5);
        add(5, 1);
    }
    n = nn;
    int ne = e.size();
    int nxt = *lower_bound(pri.begin(), pri.end(), ne);
    set<int> q;
    for(int a=1;a<=n;a++)
        q.insert(a);
    while(e.size() < nxt && !q.empty()){
        int u = *q.begin();    
        int ligacom = -1;
        for(auto it: q){
            int v = it;
            if(u != v && !liga[u][v]){
                ligacom = v;
                break;
            }
        }
        if(ligacom != -1){
            add(u, ligacom);
            q.erase(ligacom);
        }
        q.erase(u);
    }
    if(mrk[e.size()]){
        puts("-1");
    }
    else{
        for(int a=1;a<=n;a++){
            if(mrk[deg[a]]){
//                printf("a %d deg %d\n", a, deg[a]);

            }
            assert(!mrk[deg[a]]);
        }
        printf("%d\n", (int)e.size());
        for(pii p: e){
            printf("%d %d\n", p.fst, p.snd);
        }
    }
}

