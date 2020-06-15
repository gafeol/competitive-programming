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

int n, m, k;
int s[MAXN];
int res[MAXN];

map<int, multiset<int> > lig;
map<int, int> cnt;

bool rmv(int a, int b){
    if(lig.find(a) == lig.end())
        return false;
    if(lig[a].find(b) == lig[a].end())
        return false;
    lig[a].erase(lig[a].find(b));
    return true;
}

int main (){
    for_tests(t, tt){
        cnt.clear();
        lig.clear();
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            if(cnt.find(s[a]) == cnt.end())
                cnt[s[a]] = 0;
            cnt[s[a]]++;
        }
        for(int a=0;a<n/2;a++){
            int b = n-1-a;   
            int sm = min(s[a], s[b]);  
            int mx = max(s[a], s[b]);
            lig[sm].insert(mx);
        }
        for(int a=0;a<n;a++){
            scanf("%d", res+a);
            if(cnt.find(res[a]) == cnt.end())
                cnt[res[a]] = 0;
            cnt[res[a]]--;
        }
        bool ok = true;
        for(int a=0;a<n;a++){
            if(cnt[s[a]] != 0)
                ok = false;
        }
        if((n&1) && s[n/2] != res[n/2])
            ok = false;
        for(int a=0;ok && a<n/2;a++){
            int b = n-1-a;
            int sm = min(res[a], res[b]);
            int mx = max(res[a], res[b]);
            ok = rmv(sm, mx);
        }
        if(ok)
            puts("Yes");
        else
            puts("No");
    }
}

