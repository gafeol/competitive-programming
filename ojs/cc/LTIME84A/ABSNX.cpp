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

const int MAXN = 252345;

int n, m, k;
int s[MAXN];

int maiate[MAXN];

vector<int> ev[MAXN];

int bit[MAXN];

int qry(int i){
    i += 2;
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= (i&-i);
    }
    return ans;
}

void upd(int i, int x){
    i += 2;
    while(i < MAXN){
        bit[i] += x;
        i += (i&-i);
    }
}

ll solve(){
    for(int a=0;a<MAXN;a++){
        bit[a] = 0;
        ev[a].clear();
    }

    stack<int> mx;
    for(int a=0;a<n;a++){
        while(!mx.empty() && s[mx.top()] < s[a]){
            maiate[mx.top()] = a-1;
            mx.pop();
        }
        mx.push(a);
    }
    while(!mx.empty()){
        maiate[mx.top()] = n-1;
        mx.pop();
    }
    stack<int> mn;
    for(int a=n-1;a>=0;a--){
        while(!mn.empty() && s[mn.top()] > s[a]){
            ev[a+1].pb(mn.top());
            mn.pop();
        }
        mn.push(a);
    }
    while(!mn.empty()){
        ev[0].pb(mn.top());
        mn.pop();
    }
    ll ans = 0;
    for(int a=0;a<n;a++){
        for(int id: ev[a])
            upd(id, 1);
        ans += qry(maiate[a]) - qry(a-1);
    }
    return ans;
}


ll dis() {
    ll ans = 0;
    int i = 0, j = 0;
    while(i < n){
        while(j + 1 < n && s[j+1] == s[i])
            j++;
        ans += j - i + 1;
        i++;
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        ll ans = solve();
        reverse(s, s+n);
        ans += solve();
        ans -= dis();
        printf("%lld\n", ans);
    }
}

