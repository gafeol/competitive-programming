#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000009;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

random_device rd;
mt19937_64 eng(rd());
uniform_int_distribution<unsigned long long> distr;
//unsigned long long getRand() { return distr(eng); }
//
ll val[500];
ll val2[500];
ll p = 1000000007;


pll h(string s){
    ll ans = 0;
    ll ans2 = 0;
    for(int a=0;a<s.size();a++){
        ans = mod(ans*p);
        ans = mod(ans + val[s[a]]);
        ans2 = mod(ans2*p);
        ans2 = mod(ans2 + val2[s[a]]);
    }
    return {ans, ans2};
}

const int MAXN = 1123456;

int n, m, k;

map<pll, int> cnt;

int main (){
    srand(time(NULL));
    for(int a='a';a<='z';a++)
        val[a] = rand();
    for(int a='a';a<='z';a++)
        val2[a] = rand();
	scanf("%d%d", &n, &k);
    char ss[MAXN];
    scanf(" %s", ss);
    string s = ss;
    s = s + s;
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        char pal[112345];
        scanf(" %s", pal);
        pll hx = h(pal);
        assert(cnt.find(hx) == cnt.end());
        cnt[hx] = a;
    }
    vector<pll> hashs;
    for(int b=0;b<n;b++){
        pll ans = {0, 0};
        for(int i=b*k;i<(b+1)*k;i++){
            ans = {mod(ans.fst*p), 
                    mod(ans.snd*p)}; 
            ans = {mod(ans.fst +  val[s[i]]), 
                    mod(ans.snd + val2[s[i]])};
        }
        hashs.pb(ans);
    }

    ll pot = 1;
    for(int a=0;a<k-1;a++){
        pot = mod(pot*p);
    }

    for(int ini=0;ini<k;ini++){
        bool ok = true;
        map<pll, int> cnt2;
        for(pll hx: hashs){
            if(cnt.find(hx) == cnt.end() || cnt2.find(hx) != cnt2.end()){
                ok = false;
                break;
            }
            cnt2[hx] = 1;
        }
        if(ok){
            puts("YES");
            for(pll &hx: hashs){
                printf("%d ", cnt[hx]+1);
            }
            puts("");
            return 0;
        }
        if(ini == k-1) break;
        for(int b=0;b<n;b++){
            int fst = b*k + ini; 
            hashs[b] = {mod(hashs[b].fst - mod(pot*val[s[fst]])), 
                        mod(hashs[b].snd - mod(pot*val2[s[fst]]))};
            hashs[b] = {mod(modn + hashs[b].fst),
                        mod(modn + hashs[b].snd)};
            hashs[b] = {mod(p*hashs[b].fst + val[s[fst+k]]),
                        mod(p*hashs[b].snd + val2[s[fst+k]])};
        }
    }
    puts("NO");
}


