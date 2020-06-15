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

int n;
// Suffix array Nlog2 + Kazai

vector<int> sa(string s){
    int n = s.size();
    
    if(n == 1) // Tratar caso n = 1
        return vector<int>(1, 0);


    vector<int> r(n+1), p(n), aux(n);
    for(int a=0;a<n;a++){
        r[a] = s[a];
        p[a] = a;
    }
    r[n] = -1;

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
        sz = max(0, sz-1);
    }
    return lcp;
}

char s[51234];

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf(" %s", s);
        int sz = strlen(s);
        vector<int> lcp = sa(s);
        ll ans = 0;
        for(int i=0;i<sz;i++){
            ans += (ll)sz - i - lcp[i];
        }
        printf("%lld\n", ans);
    }
}
