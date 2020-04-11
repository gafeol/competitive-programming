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

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];
int prof[MAXN], H[MAXN];

set<pii> q;

int build(int u, int h){
    prof[u] = h;
    H[u] = h;
    int l = u*2;
    int r = u*2+1;
    if(l >= (1<<n))
        return prof[u]; 
    
    prof[u] = min(build(l, h+1), build(r, h+1));
    return prof[u];
}

void rmv(int u){
    int l = u*2, r = u*2+1;
    if(l >= (1<<n) || max(s[l], s[r]) == 0){
        s[u] = 0;
        return ;
    }
    if(s[l] > s[r]){
        s[u] = s[l];
        rmv(l);
    }
    else{
        s[u] = s[r];
        rmv(r);
    }

    if(max(s[l], s[r]) == 0){
        prof[u] = H[u];
    }
    else{
        if(s[l] > s[r])
            prof[u] = prof[l];
        else
            prof[u] = prof[r];
    }
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=1;a<(1<<n);a++){
            scanf("%d", s+a);
        }
        build(1, 1);
        q.insert({-s[1], 1});
        vector<int> ans;
        while(!q.empty()){
            pii p = *q.begin();
            q.erase(q.begin());
            int u = p.snd;
            debug("u %d prof %d\n", u, prof[u]);
            if(prof[u] <= m){
                if(u*2 < (1<<n)){
                    if(s[u*2] != 0)
                        q.insert({-s[u*2], u*2});
                    if(s[u*2+1] != 0)
                        q.insert({-s[u*2+1], u*2+1});
                }
            }
            else{
                ans.pb(u);
                rmv(u);
                if(s[u] != 0)
                    q.insert({-s[u], u});
            }
        }
        ll sum = 0;
        for(int a=1;a<(1<<m);a++)
            sum += s[a];
        printf("%lld\n", sum);
        for(int x: ans)
            printf("%d ", x);
        puts("");
    }
}

