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

int n[3], m, k;
vector<int> s[3];

int getY(ll x, int t){
    if(lower_bound(s[t].begin(), s[t].end(), x) == s[t].end())
        return -1;
    return *lower_bound(s[t].begin(), s[t].end(), x);
}

ll sq(ll x) { return x*x; }

ll val(ll x, ll y, ll z){
    return sq(x - y) + sq(x - z) + sq(y - z);
}

ll best(ll x, ll y, int t){
    int i = 0, j = s[t].size()-1;
    while(j - i > 6){
        int l = i + (j - i)/3;
        int r = j - (j - i)/3;
        ll vl = val(x, y, s[t][l]);
        ll vr = val(x, y, s[t][r]);
        if(vl > vr)
            i = l;
        else
            j = r;
    }
    int Z = 0; 
    ll bst = LLONG_MAX;
    for(int a=i;a<=j;a++){
        if(val(x, y, s[t][a]) <= bst){
            bst = val(x, y, s[t][a]);
            Z = s[t][a];
        }
    }
    return bst;
}

ll go(){
    ll ans = LLONG_MAX;
    for(ll x: s[0]){
        ll y = getY(x, 1);
        if(y != -1)
            ans = min(ans, best(x, y, 2));
        y = getY(x, 2);
        if(y != -1)
            ans = min(ans, best(x, y, 1));
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        for(int a=0;a<3;a++)
            scanf("%d", &n[a]);
        for(int a=0;a<3;a++){
            s[a].clear();
            for(int i=0;i<n[a];i++){
                int x;
                scanf("%d", &x);
                s[a].pb(x);
            }
            sort(s[a].begin(), s[a].end());
        }
        ll ans = 0;
        ans = go();
        swap(s[0], s[1]);
        ans = min(ans, go());
        swap(s[0], s[2]);
        ans = min(ans, go());
        printf("%lld\n", ans);
    }
}

