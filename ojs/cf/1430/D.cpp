#include "bits/stdc++.h"
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
char s[MAXN];
int nxt[MAXN];

set<pii> sm, bg;

void add(int i, int sz = -1){
    if(sz == -1)
        sz = nxt[i] - i;
    if(sz == 1)
        sm.insert({i, sz});
    else
        bg.insert({i, sz});
}

int main (){
    for_tests(t, tt){
        sm.clear();
        bg.clear();
        scanf("%d", &n);
        scanf(" %s", s);
        int comp = 0;

        for(int i=n-1;i>=0;i--){ 
            nxt[i] = ((i < n-1 && s[i+1] == s[i]) ? nxt[i+1] : i+1);
            if(nxt[i] == i+1) {
                comp++;
                if(i + 1 < n){
                    add(i+1);
                }
            }
        }
        add(0);

        int ans = 0;
        while(!bg.empty() || !sm.empty()){
            ans++;
            if(!bg.empty()){
                auto u = *bg.begin();
                bg.erase(bg.begin());
                add(u.fst, u.snd-1);
            }
            else{
                sm.erase(sm.begin()); 
            }
            if(bg.empty() && sm.empty()) break;

            auto mn = [&](set<pii> &q) { return (q.empty() ? INT_MAX : q.begin()->fst); };

            if(mn(sm) < mn(bg))
                sm.erase(sm.begin());
            else
                bg.erase(bg.begin());
        }
        printf("%d\n", ans);
    }
}

