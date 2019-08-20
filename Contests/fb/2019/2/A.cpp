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

int main (){
    for_tests(t, tt){
        scanf("%d%d%d", &n, &m, &k);
        printf("Case #%d: ", tt);
        int x, y;
        scanf("%d%d", &x, &y);
        vector<int> dist;
        vector<pii> s;
        for(int a=0;a<k;a++){
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            s.pb({xx, yy});
            dist.pb(abs(x - xx) + abs(yy - y));
        }
        if(k == 1)
            puts("N");
        else{
            int d2 = abs(s[0].fst - s[1].fst) + abs(s[0].snd - s[1].snd);
            if(!(dist[0]&1) && !(dist[1]&1) && !(d2&1))
                puts("Y");
            else
                puts("N");
        }
    }
}

