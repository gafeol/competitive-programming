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
ll l, r;
int s[MAXN];
vector<int> ans;
ll stp;

void add(int x){
    if(stp >= l && stp <= r)
        ans.pb(x);
    stp++;
}

int main (){
    for_tests(t, tt){
        ans.clear();
        scanf("%d%lld%lld", &n, &l, &r);
        stp = 1;
        int look = 2;
        while(look < n){
            add(1);
            add(look);
            look++;
        }
        add(1);
        add(n);
        int base = 2;
        while(base < n){
            add(base);
            if(stp > r) break;
            if(stp + 2ll*(n-1 - base-1 + 1) >= l){
                for(int o=base+1;o<n;o++){
                    add(o);
                    add(base);
                }
            }
            else{
                stp += (ll)2ll*(n-1 - base-1 + 1);
            }
            add(n);
            base++;
        }
        add(1);
        for(int x: ans)
            printf("%d ", x);
        puts("");
    }
}

