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


// Suffix array Nlog2 + Kazai
vector<int> r, p, aux;

vector<int> sa(string s){
    int n = s.size();
    
    if(n == 1) // Tratar caso n = 1
        return vector<int>(1, 0);

    r.resize(n+1);
    p.resize(n);
    aux.resize(n);

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

int n, m, k;

ll res(int i, int j, int jj){
    if(j == i) j++;
    int it = jj - j + 1;
    if((j - i + 1)&1)
        return (it+1)/2;
    else
        return it/2;
}

int main (){
    IOS();
    cin >> n;
    string s;
    cin >> s;
    string ori = s;
    reverse(s.begin(), s.end());
    s = ori + "$" + s;
    
    ll ans = 0;
    vector<int> lcp = sa(s);
    for(int i=0;i<lcp.size();i++){
        if(s[i] == '$') continue;
        int nxt = p[r[i]+1];
        int ate = lcp.size()-1;
        if(i < n)
            ate = n-1;
        ans += res(i, i+lcp[i], ate);
    }
    printf("%lld\n", ans);
}

