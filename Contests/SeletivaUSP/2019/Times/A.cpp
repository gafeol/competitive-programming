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

const int MAXN = 500005;
const int SQRT = sqrt(MAXN)+1;
const int MAGIC = 800;

int n, m, k;
int s[MAXN];
int res[MAXN];

struct qry{
    int l, r, x, k, id;

    bool operator <(const qry& o) {
        int ba = l/SQRT, bb = o.l/SQRT;
        return (ba < bb || (ba == bb && r < o.r));
    }
};

vector<qry> sm[MAGIC+2];
vector<qry> bg;

vector<int> pos[MAGIC+2];

int cnt[MAXN];

void add(int i){
    cnt[s[i]]++;
}

void rmv(int i){
    cnt[s[i]]--;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}

    for(int a=0;a<m;a++){
        int l, r, x, k;
        scanf("%d%d%d%d", &l, &r, &x, &k);
        l--;r--;
        if(k <= MAGIC)
            sm[k].pb({l, r, x, k, a});
        else
            bg.pb({l, r, x, k, a});
    }

    for(int val = 1;val <= MAGIC;val++){
        if(sm[val].empty()) continue;
        for(int a=0;a<=val;a++)
            pos[a].clear();

        debug("val %d\n", val);
        for(int a=0;a<n;a++){
            pos[(s[a]%val)].pb(a);
            debug("pos[%d] push %d\n", (s[a]%val), a);
        }

        for(qry q: sm[val]){
            res[q.id] = (upper_bound(pos[q.x].begin(), pos[q.x].end(), q.r) 
                - lower_bound(pos[q.x].begin(), pos[q.x].end(), q.l));
            debug("resolve res[%d]: %d\n", q.id, res[q.id]);
        }
    }

    sort(bg.begin(), bg.end());
    int i  = 0, j = -1;
    for(qry q: bg){
        while(j < q.r)
            add(++j);
        while(i > q.l)
            add(--i);
        while(j > q.r)
            rmv(j--);
        while(i < q.l)
            rmv(i++);

        int ans = 0;
        debug("q.id %d\n", q.id);
        for(int x=0;x*q.k + q.x < MAXN;x++){
           ans += cnt[x*q.k + q.x]; 
        }
        res[q.id] = ans;
    }
    for(int a=0;a<m;a++){
        printf("%d\n", res[a]);
    }
}

