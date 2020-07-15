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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
// p[i] = inicio do suffix de ranking i
vector<int> p, r;
inline vector<int> sa(string s){
    int n = s.size();
    vector<int> aux(n);
    p.resize(n);
    r.resize(n+1);
    for(int a=0;a<n;a++){
        r[a] = s[a];
        p[a] = a;
    }
    r[n] = -1;
    
    if(n == 1) // Tratar caso n = 1
        return vector<int>(1, 0);


    for(int d=1;d < n;d*=2ll){
        sort(p.begin(), p.end(), [&](int a, int b){
            return make_pair(r[a], r[min(n, a+d)]) < make_pair(r[b], r[min(n, b+d)]);
                }); 
        int val = 0;
        for(int a=0;a<n;a++){
            if(a > 0)
                val += (make_pair(r[p[a]], r[min(n, p[a]+d)]) != make_pair(r[p[a-1]], r[min(n, p[a-1]+d)]));
            aux[p[a]] = val;
        }
        for(int a=0;a<n;a++)
            r[a] = aux[a];
        if(r[p[n-1]] == n-1) break;
    }

    //Kazai 
    int sz = 0;
    vector<int> lcp(n); // lcp[i] = |lcp(s[i...], s[p[r[i]+1]....])|
    for(int i=0;i<n;i++){
        if(r[i] == n-1){
            lcp[i] = sz = 0;
            continue;
        }
        int o = p[r[i]+1];
        while(i + sz < n && o + sz < n && s[i + sz] == s[o + sz])
            sz++;
        lcp[i] = sz;
        sz = max(0ll, sz-1);
    }
    return lcp;
}

int n, m, k;

// inverte cada string de v e concatena
inline string concatena(vector<string> &v){
    int sz = 0;
    for(string &s: v){
        reverse(s.begin(), s.end());
        sz += s.size();
        sz++; // conta o $
    }
    string concat; 
    concat.resize(sz);
    int i = 0;
    for(string &s: v){
        for(char c: s){
            concat[i++] = c;
        }
        concat[i++] = '$';
    }
    assert(i == sz);
    return concat;
}

inline vector<ll> concatenaJ(vector<vector<ll>> &joys){
    vector<ll> concat; 
    for(vector<ll> &v: joys){
        reverse(v.begin(), v.end());
        for(int x: v){
            concat.pb(x);
        }
        concat.pb(0ll); // valor do $
    }
    return concat;
}

inline vector<ll> getDisDollarSig(string &s){
    int dis = 0;
    vector<ll> d(s.size());
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == '$')
            dis = 0;
        else
            dis++;
        d[i] = dis;
    }
    return d;
}

int32_t main (){
    freopen("exciting.in", "r", stdin);
    for_tests(t, tt){
        int sz = 0;
        vector<string> strs;
        vector<vector<ll>> joys;
        scanf("%lld", &n);
        for(int a=0;a<n;a++){
            char pal[112345];
            scanf(" %s", pal);
            strs.pb(pal);
        }
        for(int a=0;a<n;a++){
            vector<ll> j(strs[a].size());
            for(int b=0;b<strs[a].size();b++){
                scanf("%lld", &j[b]);         
            }
            joys.pb(j);
        }
        string c = concatena(strs);
        vector<ll> cj = concatenaJ(joys);
        vector<int> lcp = sa(c);
        ll qeq = 0;
        ll qsim = 0;
        vector<ll> dsig = getDisDollarSig(c);
        stack<pair<int, ll>> maxA;

        ll ans = 0;
        for(int rk=0;rk<c.size();rk++){
            if(c[p[rk]] == '$') continue; 
            int i = p[rk];
            /*
            debug("rk %lld p %lld\n", rk, p[rk]);
            for(int a=i;c[a] != '$';a++){
                debug("%c", c[a]);
            }
            debug("\n");
            */
            if(qeq == 0){
                int prefSize = dsig[i];
                qeq++;
                int u = i;
                assert(r[u] == rk);
                while(r[u] + 1 < c.size()){
                    int nxt = p[r[u]+1];
                    if(lcp[u] < prefSize || dsig[nxt] != prefSize) break;
                    qeq++;
                    u = nxt;
                }
            }
            if(qsim == 0){
                int prefSize = dsig[i];
                vector<ll> As;
                vector<int> pos;
                qsim++;         
                int u = i;
                As.pb(cj[u]);
                pos.pb(u);
                while(r[u] + 1 < c.size()){
                    int nxt = p[r[u]+1];
                    if(lcp[u] < prefSize) break;
                    qsim++;
                    u = nxt;
                    As.pb(cj[u]);
                    pos.pb(u);
                }
                while(!As.empty()){
                    ll val = As.back();
                    if(maxA.empty() || maxA.top().snd <= val){
                        maxA.push({pos.back(), val});
                    }
                    As.pop_back();
                    pos.pop_back(); 
                }
            }

            // smaller sim

            debug("qeq %lld qsim %lld\n", qeq, qsim);
            ll mxA = maxA.top().snd;
            ll sz = dsig[i];
            ll pop = qeq;
            debug("ans %lld*%lld*%lld = %lld\n", pop,mxA,sz, pop*mxA*sz);
            ans = max(ans, pop*mxA*sz);
            if(i == maxA.top().fst)
                maxA.pop();
            qeq--;
            qsim--;
        }
        printf("%lld\n", ans);
    }
}

