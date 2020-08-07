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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int cnt[MAXN];
set<pii> q, ori;
set<int> pos, opos;

void add(int x){
    auto it = q.find({-cnt[x], x});
    if(it != q.end())
        q.erase(it);
    cnt[x]++;
    q.insert({-cnt[x], x});
}

bool go(int sp){
    q = ori;
    pos = opos;
    //debug("sp %d\n", sp);
    vector<pii> rec[MAXN];
    for(int i=0;i<n;i++){
        for(pii p: rec[i]){
            q.insert(p);
        }
        if(q.empty()) return false;
        auto bg = *q.begin(); 
        //debug("botou %d\n", bg.snd);
        q.erase(q.begin());

        if(bg.fst+1 < 0){
            if(i + sp >= n) return false;
            rec[i+sp].pb({bg.fst+1, bg.snd});
        }
    }
    return true;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        q.clear();
        ori.clear();
        opos.clear();
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            cnt[s[a]] = 0;
            opos.insert(a);
        }
        for(int a=0;a<n;a++)
            add(s[a]);
        ori = q;
        q.clear();
        int i = 1, j = n-1;
        while(i < j){
            int m = (i + j+1)/2;
            if(go(m))
                i = m; 
            else
                j = m-1;
        }
        printf("%d\n", i-1);
    }
}

