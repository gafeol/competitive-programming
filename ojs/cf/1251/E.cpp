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

vector<int> s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++)
            s[a].clear();
        for(int a=0;a<n;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            s[i].pb(j);
        }
        int acc[MAXN];
        acc[0] = 0;
        for(int a=1;a<n;a++)
            acc[a] = acc[a-1] + s[a-1].size();
        int cnt = 0;
        multiset<int> q;
        ll ans = 0;
        for(int a=n-1;a>=0;a--){
            if(s[a].empty()) continue;
            for(int x: s[a])
                q.insert(x);
            while(acc[a] + cnt < a){
                ans += (ll)*q.begin();
                q.erase(q.begin());
                cnt++;
            }
        }
        printf("%lld\n", ans);
    }
}

